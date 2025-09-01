#ifndef NUMBER
#define NUMBER
#include <iostream>
#include <string>
#include <tgmath.h>

using namespace std;

string decimal_to_binary(int decimal, int bits_length)
{
    string bits = "";
    for (int i = 0; i < bits_length; i++)
    {
        bits += "0";
    }
    std::cout << bits << std::endl;
    int curr_position = -1;
    int curr_value = decimal;
    while (curr_value > 0)
    {
        curr_position = floor(log2(curr_value));
        bits[bits_length-1 - curr_position] = '1';
        curr_value -= pow(2, curr_position);
    }
    return bits;
}
int binary_to_decimal(string bits)
{
    int curr_value = 0;
    for (int i = 0; i < bits.length(); i++)
    {
        curr_value = curr_value * 2 + ( (int) bits[i] - (int) '0' );
    }
    return curr_value;
}
string binary_to_hexadecimal(string bits)
{
    string hex_mapping = "0123456789ABCDEF";
    string first_chunk = bits.substr(0, 4);
    string second_chunk = bits.substr(4, 4);
    int first_chunk_value = binary_to_decimal(first_chunk);
    int second_chunk_value = binary_to_decimal(second_chunk);
    string hexadecimal = "0x";
    hexadecimal.append(1, hex_mapping[first_chunk_value]);
    hexadecimal.append(1, hex_mapping[second_chunk_value]);

    return hexadecimal;
}
string hexadecimal_to_binary(string hexadecimal)
{
    string hex_mapping = "0123456789ABCDEF";
    char first_chunk_char = hexadecimal[2];
    char second_chunk_char = hexadecimal[3];
    int first_chunk_value = hex_mapping.find(first_chunk_char);
    int second_chunk_value = hex_mapping.find(second_chunk_char);
    string first_chunk = decimal_to_binary(first_chunk_value, 4);
    string second_chunk = decimal_to_binary(second_chunk_value, 4);
    return first_chunk + second_chunk;
}
#endif