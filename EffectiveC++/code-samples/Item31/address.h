#ifndef ADDRESS_H_
#define ADDRESS_H_

#include <string>

class Address {
    std::string addr;
public:
    Address(const std::string& addr_) : addr(addr_) {}
};

#endif