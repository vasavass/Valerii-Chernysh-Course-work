#include "TextEncoder.h"

std::string TextEncoder::encode(const std::string& input) const {
    return input; // No special encoding for plain text
}

std::string TextEncoder::decode(const std::string& input) const {
    return input; // No special decoding for plain text
}
