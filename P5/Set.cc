#include "Set.h"


Set::Set() {
  sz_ = sizeof(long); 
  
}

Set::Set(unsigned size) {
    sz_ = size;
}

Set::~Set(){}

long Set::GetVal() {
    return value_;
}

unsigned Set::GetSize() {
    return sz_;
}

void Set::SetVal(std::string& value) {
    long aux = std::stoll(value);
    value_ = aux;
}
std::vector<long> Set::GetVector() {
    return element_of_set_;
}


void Set::DecToBinary(char c) {
    if(isdigit(c)){
        for (long i = 7; i >= 0; --i) {
            std::cout << ((c & (1 << i))? '1' : '0');
            PutInSet(i);
        }
    }
}

void Set::PutInSet(long element) {
    element_of_set_.push_back(element);
}

void Set::Output() {
    std::cout << "My set is : ";
    for(unsigned i = 5; i < element_of_set_.size(); i++)
    std::cout << element_of_set_[i];
}