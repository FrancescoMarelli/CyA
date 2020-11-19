#ifndef _SET_H
#define _SET_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class Set {
    private:
    unsigned sz_;
    long value_;
    std::vector<std::string> str_;
    std::string my_alpha;
    
    public:
    Set();
    Set(unsigned& size);
    ~Set();
    unsigned GetSize();

    long GetVal();
    void Decode(std::string& in_str);
    void SetAlphabet(std::string&);
    void Output() ;
    void ConvertAlphabetToASCII();


};
#endif