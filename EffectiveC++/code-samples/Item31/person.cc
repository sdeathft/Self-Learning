#include "person.h"         
#include "personImpl.h"

Person::Person(const std::string &name, const Date& date, const Address& addr) :
    pImpl(new PersonImpl(name, date, addr)) {}

std::string Person::name() const {
    return pImpl -> get_name();
}

