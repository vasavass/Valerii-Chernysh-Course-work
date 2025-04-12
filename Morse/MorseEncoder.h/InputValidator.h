#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H

#include <string>
#include <algorithm>
#include <cctype>

class InputValidator {
public:
    static bool isValidText(const std::string& input) {
        return std::all_of(input.begin(), input.end(), [](char c) {
            return std::isalpha(c) || std::isdigit(c) || c == ' ';
            });
    }
};

#endif // INPUTVALIDATOR_H
