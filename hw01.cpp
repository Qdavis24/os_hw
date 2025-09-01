#include <iostream>
#include <string>

// Quinn Davis and Josh Carr


/**
 * Void function that prints the results from the conversions 
 * Takes in integer dec, string bin, and string hex
 * Prints out each input with appropriate labels
*/
void printresult(int dec, std::string bin, std::string hex) {
    std::cout << "Decimal: " << dec << std::endl;
    std::cout << "Binary: " << bin << std::endl;
    std::cout << "Hexadecimal: " << hex << std::endl;
}

/**
 * Void function that converts a binary input to a decimal and hexadecimal 
 * Takes in a string bin
 * Checks to see if it is a valid binary number and then converts it to decimal and hexidecimal
 * Inputs results into printresult function
 */
void binaryconversion(std::string bin) {
    if (bin.length() != 9) {
        std::cout << "Error: Invalid binary number" << std::endl;
        return;
    }

    int counter = 0;
    for (int i = 1; i < bin.length(); i++) {
        if (bin[i] != '0' && bin[i] != '1') {
            std::cout << "Error: Invalid binary number" << std::endl;
            return;
        }
        int curr_digit = bin[i] - '0';
        counter = counter * 2 + curr_digit;
    }

    std::string hex = "0x";

    printresult(counter, bin, hex);
    return;
}

/**
 * Void function that converts a binary input to a decimal and hexadecimal 
 * Takes in a string hex
 * Checks to see if it is a valid hexidecimal number and then converts it to decimal and binary
 * Inputs results into printresult function
 */
void hexconversion(std::string hex) {
    if (hex.length() != 4) {
        std::cout << "Error: Invalid hexadecimal number" << std::endl;
        return;
    }

    int dec = 0;

    std::string bin = "b";

    printresult(dec, bin, hex);
    return;
}

/**
 * Void function that converts a binary input to a decimal and hexadecimal 
 * Takes in a string input
 * Checks to see if it is a valid decimal number and then converts it to binary and hexidecimal
 * Inputs results into printresult function
 */
void decimalconversion(std::string input) {
    int dec = stoi(input);
    if (dec < 0 || dec > 255) {
        std::cout << "Error: Invalid decimal number" << std::endl;
        return;
    }

    std::string bin = "b";

    std::string hex = "0x";

    printresult(dec, bin, hex);
    return;
}

int main() {
    std::string input;
    std::cout << "Enter a number to convert: ";
    std::cin >> input;
    std::cout << std::endl;

    std::cout << "Input number: " << input << std::endl << std::endl;


    // Checking 
    if (input[0] == 'b') {
        binaryconversion(input);
    }
    else if (input[0] == '0' && input[1] == 'x') {
        hexconversion(input);
    }
    else {
        decimalconversion(input);
    }
}