#include "Set.h"

Set::Set() {
  sz_ = 64;
}

Set::Set(unsigned& size) {
    sz_= size;
}

Set::~Set(){}

void Set::Decode(std::string& in_str) {

}

void Set::SetAlphabet(std::string& cadena) {
  my_alpha = cadena;
}



