#include <iostream>
#include <memory>
#include "MorseEncoder.h"
#include "TextEncoder.h"

int main() {
    std::unique_ptr<Encoder> encoder;
    std::string input;
    int choice;

    std::cout << "Choose an option: \n1. Text to Morse\n2. Morse to Text\n";
    std::cin >> choice;
    std::cin.ignore();

    try {
        if (choice == 1) {
            encoder = std::make_unique<MorseEncoder>();
            std::cout << "Enter text: ";
            std::getline(std::cin, input);
            std::string morse = encoder->encode(input);
            std::cout << "Text to Morse: " << morse << std::endl;
        }
        else if (choice == 2) {
            encoder = std::make_unique<MorseEncoder>();
            std::cout << "Enter Morse code (use . and - for symbols, space between letters, and / for spaces between words): ";
            std::getline(std::cin, input);
            std::string decodedText = encoder->decode(input);
            std::cout << "Morse to Text: " << decodedText << std::endl;
        }
        else {
            std::cout << "Invalid choice." << std::endl;
        }
    }
    catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }

    return 0;
}
