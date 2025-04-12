#ifndef ADVANCEDMORSEENCODER_H
#define ADVANCEDMORSEENCODER_H

#include "MorseEncoder.h"
#include "InputValidator.h"
#include <algorithm>

class AdvancedMorseEncoder : public MorseEncoder {
public:
    std::string encode(const std::string& input) const override {
        if (!InputValidator::isValidText(input)) {
            throw std::invalid_argument("Input contains invalid characters.");
        }

        std::string cleanInput = input;
        std::transform(cleanInput.begin(), cleanInput.end(), cleanInput.begin(), ::toupper);
        return MorseEncoder::encode(cleanInput);
    }
};

#endif // ADVANCEDMORSEENCODER_H
