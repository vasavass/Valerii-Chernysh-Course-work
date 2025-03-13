#include "MorseEncoder.h"

MorseEncoder::MorseEncoder() {
    morseCode = {
        {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."}, {'F', "..-."},
        {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
        {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."},
        {'S', "..."}, {'T', "-"}, {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
        {'Y', "-.--"}, {'Z', "--.."}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"},
        {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."}, {'8', "---.."},
        {'9', "----."}, {'0', "-----"}
    };
    for (auto& pair : morseCode) {
        reverseMorseCode[pair.second] = pair.first;
    }
}

std::string MorseEncoder::encode(const std::string& input) const {
    std::stringstream morse;
    for (char c : input) {
        if (c == ' ') {
            morse << " / ";
        }
        else {
            morse << morseCode.at(toupper(c)) << " ";
        }
    }
    return morse.str();
}

std::string MorseEncoder::decode(const std::string& input) const {
    std::stringstream text;
    std::stringstream morseStream(input);
    std::string morseChar;
    while (morseStream >> morseChar) {
        if (morseChar == "/") {
            text << " ";
        }
        else {
            auto it = reverseMorseCode.find(morseChar);
            if (it != reverseMorseCode.end()) {
                text << it->second;
            }
            else {
                throw std::invalid_argument("Invalid Morse     code input.");
            }
        }
    }
    return text.str();
}
