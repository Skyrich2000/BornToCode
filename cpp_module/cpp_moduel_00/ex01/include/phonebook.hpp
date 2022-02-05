#include <iomanip>
#include <iostream>

#include "contact.hpp"

#define MAX_CONTACTS 8

class PhoneBook {
   private:
    int index;
    Contact contacts[MAX_CONTACTS];

   public:
    PhoneBook();
    ~PhoneBook();

    bool addContact();
    void printSummary();
    bool search();
};
