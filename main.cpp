#include <fstream>
#include <string>
#include <iostream>
#include <optional>

using namespace std;
struct DnsHeader
{
    u_int16_t id;
    bool truncated_message;
    bool recursion_desired;
    bool authoritative_answer;
    u_int8_t opcode;
    bool response;
    u_int8_t rescode;
    bool checking_disabled;
    bool authed_data;
    bool z;
    bool recursion_available;
    u_int16_t questions;
    u_int16_t answers;
    u_int16_t authoritative_answers;
    u_int16_t resource_entries;
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

int main()
{
    ifstream queryfile("query_packet.txt", ios::ate | ios::binary);
    std::streamsize size = queryfile.tellg();
    queryfile.seekg(0, ios::beg);
    char file_buffer[size];
    queryfile.read(file_buffer, size);
    ByteBuffer buff = ByteBuffer(file_buffer, size);
    queryfile.close();
    return 0;
}
