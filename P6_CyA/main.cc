#include <iostream>

#include "File.cc"

int main(int argc, char** argv){

    std::string input_f;
    std::string output_f;
    std::string pattern;
    output_f = argv[2];
    input_f = argv[1];
    pattern = argv[3];
    
   
    File file_aux(pattern, input_f, output_f);
}