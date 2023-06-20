#ifndef PERSON_IMPL_H_
#define PERSON_IMPL_H_

#include <string>

#include "date.h"
#include "address.h"

class PersonImpl {
    std::string name;
    Date dob;
    Address addr;
public:
    PersonImpl(const std::string &name_, const Date& dob_, const Address& addr_) :
        name(name_), dob(dob_), addr(addr_) {}

    std::string get_name() {
        return name;
    }
};

#endif