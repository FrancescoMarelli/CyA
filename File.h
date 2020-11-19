#ifndef _FILE_H
#define _FILE_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Dfa.cc"
#include "Set.cc"


class File {

    private:
    std::string input_file_;
    std::string output_file_;
    

    Dfa mydfa_;
    Set A;
        
    public:
    File(std::string&, std::string& input_file, std::string& output_file);
    ~File();
    void Output(std::string&);
  
    void SetInput(std::string& input);
    void SetOutput(std::string& output);
    std::string GetInput();
    std::string GetOutput();
    void Input();
};
#endif