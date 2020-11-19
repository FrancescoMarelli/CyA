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

    public:
      Set();
      Set(std::vector<std::string>& val);
      Set(unsigned size);
      ~Set();
      unsigned GetSize();

     long GetVal();
     void SetVal(std::string& value);
     std::vector<long> GetVector();
     void PutInSet(long element);
     //int GetNofValues();
   //  long BitCounter(std::string& character);
     void DecToBinary(char c);
     void Output() ;


};
#endif