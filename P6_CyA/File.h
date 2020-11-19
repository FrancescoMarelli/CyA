#ifndef _FILE_H
#define _FILE_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


class File {

    private:
    std::string input_file_;
    std::string output_file_;
    std::ifstream input_aux;
    std::ofstream output_aux;
    std::vector<long> elements;
        
    public:
    File(std::string&, std::string& input_file, std::string& output_file);
    ~File();
     void Output(std::string&);
     void Input(std::string&);
     void SetInput(std::string& input);
     void SetOutput(std::string& output);
     std::string GetInput();
     std::string GetOutput();
};
#endif