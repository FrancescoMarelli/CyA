#include "Set.h"

Set::Set() {
  sz_ = 64;
  SetAlphabet();
}

Set::Set(unsigned& size) {
    sz_= size;
}

Set::~Set(){}

void Set::Decode(std::string& in_str) {
  //  str_ = in_str;
}

void Set::SetAlphabet() {
  my_alpha = "abcdefghijklmnopqrstuvwxyz";
}

void Set::ConvertAlphabetToASCII() {
  for(unsigned i=0; i < my_alpha.length();i++) {
     char x = my_alpha.at(i);
     
  //   vector_ascii_[i] = (int)x;
 std::cout << x << " ";
 // vector_ascii_.resize(i+1);
  }
  std::cout << "\n";
}


