#ifndef TEXTENCODER_H
#define TEXTENCODER_H

#include "Encoder.h"
#include <string>

class TextEncoder : public Encoder {
public:
    std::string encode(const std::string& input) const override;
    std::string decode(const std::string& input) const override;
};

#endif // TEXTENCODER_H

