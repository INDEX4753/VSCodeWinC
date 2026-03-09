#include <iostream>
#include <cstring>
#include <cstdint>
#include <string>
#include <cstdlib>

const char base64_table[65] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

char *asciiToBase64(const char *input, int input_len);

int main()
{
    std::string input_str;
    std::getline(std::cin, input_str);

    char *base64_result =
        asciiToBase64(input_str.c_str(), static_cast<int>(input_str.size()));

    std::cout << base64_result << std::endl;

    delete[] base64_result;

    system("pause");
}

char *asciiToBase64(const char *input, int input_len)
{
    // only for check
    if (input == nullptr || input_len <= 0)
    {
        char *empty = new char[1];
        empty[0] = '\0';
        return empty;
    }

    // get output len
    int output_len = ((input_len + 2) / 3) * 4;
    char *output = new char[output_len + 1];
    output[output_len] = '\0';

    // 8 * 3 = 6 * 4
    int idx = 0;
    for (int i = 0; i < input_len; i += 3)
    {
        uint32_t triple = 0;
        for (int j = 0; j < 3; j++)
        {
            if (i + j < input_len)
            {
                triple |= (static_cast<uint8_t>(input[i + j]) << (16 - j * 8));
            }
        }

        output[idx++] = base64_table[(triple >> 18) & 0x3F];
        output[idx++] = base64_table[(triple >> 12) & 0x3F];
        output[idx++] = base64_table[(triple >> 6) & 0x3F];
        output[idx++] = base64_table[triple & 0x3F];
    }

    // deal with the end
    switch (input_len % 3)
    {
    case 1:
        output[output_len - 2] = '=';
        output[output_len - 1] = '=';
        break;
    case 2:
        output[output_len - 1] = '=';
        break;
    default:
        break;
    }

    return output;
}