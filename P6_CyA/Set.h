#ifndef _SET_H
#define _SET_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class Set {
    private:
     std::vector<long> element_of_set_;
     std::vector<long> binary;
     unsigned sz_;
     long value_;
     std::vector<std::string> str_;
     std::string my_alpha;
     std::vector<int> vector_ascii_;

    public:
      Set();
      Set(unsigned& size);
      ~Set();
      unsigned GetSize();

     long GetVal();
     void Decode(std::string& in_str);
     void SetAlphabet();
     void Output() ;
     void ConvertAlphabetToASCII();


};
#endif