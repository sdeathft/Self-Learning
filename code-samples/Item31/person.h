#ifndef PERSON_H_
#define PERSON_H_

#include <string>
#include <memory>

class Date;
class Address;
class PersonImpl;

class Person {
public:
    Person() = default;
    Person(const std::string &name, const Date& date, const Address& address);
    std::string name() const;
    // std::string date() const;
    // std::string address() const;

private:
    std::shared_ptr<PersonImpl> pImpl; // shared_ptr to PersonImpl class - doesn't need it's definition!
};

#endif