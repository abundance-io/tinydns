#include <fstream>
#include <iostream>
#include <optional>
#include <string>

using namespace std;

template <typename T>
T unwrap(std::optional<T> option)
{
  return option.value();
};

// todo! figure out why checking file size is segfaulting
class ByteBuffer
{
public:
  char *bytes;
  int position;
  int stream_size;
  ByteBuffer(char network_bytes[], int stream_size)
  {
    this->position = 0;
    this->bytes = network_bytes;
    this->stream_size = stream_size;
  };

  std::optional<char> read()
  {

    if (position < stream_size)
    {
      auto byte = bytes[position];

      position += 1;
      return byte;
    }
    else
    {
      cout << "\ntried to read past stream\n";
      return NULL;
    }
  };

  std::optional<u_int16_t> read_u16()
  {
    auto half_1 = read();
    auto half_2 = read();
    if (half_1.has_value() && half_2.has_value())
    {

      return ((u_int16_t)half_1.value() << 8) | half_2.value();
    }
  };

  std::optional<u_int32_t> read_u32()
  {
    auto half_1 = this->read_u16();
    auto half_2 = this->read_u16();
    if (half_1.has_value() && half_2.has_value())
    {

      return ((u_int32_t)half_1.value() << 16) | half_2.value();
    }
  }
};

enum ResultCode
{
  NOERROR,
  FORMERR,
  SERVFAIL,
  NXDOMAIN,
  NOTIMP,
  REFUSED
};

class DnsHeader
{
public:
  u_int16_t id;
  bool truncated_message;
  bool recursion_desired;
  bool authoritative_answer;
  u_int8_t opcode;
  bool response;
  ResultCode rescode;
  bool checking_disabled;
  bool authed_data;
  bool z;
  bool recursion_available;
  u_int16_t questions;
  u_int16_t answers;
  u_int16_t authoritative_entries;
  u_int16_t resource_entries;

  DnsHeader()
  {
    // set better defaults
    this->id = 0;
    this->recursion_desired = false;
    this->truncated_message = false;
    this->authoritative_answer = false;
    this->opcode = 0;
    this->rescode = ResultCode::NOERROR;
    this->checking_disabled = false;
    this->authed_data = false;
    this->z = false;
    this->recursion_available = false;

    this->questions = false;
    this->answers = 0;
    this->authoritative_entries = 0;
    this->authoritative_entries = 0;
  };

  void read(ByteBuffer buffer)
  {
    this->id = unwrap(buffer.read_u16());
    auto flags = unwrap(buffer.read_u16());
    // upper half
    u_int8_t a = flags >> 8;
    // lower half
    u_int8_t b = flags & 0xFF;
    this->recursion_desired = (a & (1 << 0)) > 0;
    this->truncated_message = (a & (1 << 1)) > 0;
    this->authoritative_answer = (a & (1 << 2)) > 0;
    this->opcode = (a >> 3) & 0xF;
    this->response = (a & (1 << 7)) > 0;

    this->rescode = static_cast<ResultCode>(b & 0x0F);
    this->checking_disabled = (b & (1 << 4)) > 0;
    this->authed_data = (b & (1 << 5)) > 0;
    this->z = (b & (1 << 6)) > 0;
    this->recursion_available = (b & (1 << 7)) > 0;

    this->questions = unwrap(buffer.read_u16());
    this->answers = unwrap(buffer.read_u16());
    this->authoritative_entries = unwrap(buffer.read_u16());
    this->resource_entries = unwrap(buffer.read_u16());
  }
};

int main()
{
  ifstream queryfile("query_packet.txt", ios::ate | ios::binary);
  std::streamsize size = queryfile.tellg();
  queryfile.seekg(0, ios::beg);
  char file_buffer[size];
  queryfile.read(file_buffer, size);
  ByteBuffer buff = ByteBuffer(file_buffer, size);
  DnsHeader header = DnsHeader();
  header.read(buff);
  cout << header.response;
  cout << header.resource_entries;

  queryfile.close();
  return 0;
}
