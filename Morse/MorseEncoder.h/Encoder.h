#ifndef ENCODER_H
#define ENCODER_H

#include <string>

class Encoder {
public:
    virtual ~Encoder() = default;
    virtual std::string encode(const std::string& input) const = 0;
    virtual std::string decode(const std::string& input) const = 0;
};

#endif 
