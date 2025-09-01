#include <string>
#include <iostream>
#include "converstions.h"


using namespace std;

int main() {
    cout << "Please input a number: " << endl;
    string input;
    cin >> input;
    string bits = decimal_to_binary(stoi(input));
    cout << bits << endl;
    cout << binary_to_int(bits) << endl;
    string hex = binary_to_hexadecimal(bits);
    cout << hex << endl;
    cout << hexadecimal_to_binary(hex);
    /*
    if (input[0] == 'b'){
        convert_bin(input);
    } else if (input[0] == '0' && input[1] == 'x'){
        convert_hex(input);
    } else {
        convert_dec(input);
    }
    */

}
