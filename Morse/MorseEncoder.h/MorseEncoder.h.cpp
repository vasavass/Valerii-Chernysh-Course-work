#ifndef MORSEENCODER_H
#define MORSEENCODER_H

#include "Encoder.h"
#include <map>
#include <sstream>
#include <algorithm>
#include <cctype>

class MorseEncoder : public Encoder {
public:
    MorseEncoder();
    std::string encode(const std::string& input) const override;
    std::string decode(const std::string& input) const override;

private:
    std::map<char, std::string> morseCode;
    std::map<std::string, char> reverseMorseCode;
};

#endif // MORSEENCODER_H
