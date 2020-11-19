#include "File.cc"
#include "Set.cc"
#include <fstream>

int main(int argc, char* argv[]) {

    std::string input_f;
    std::string output_f;
    output_f = argv[2];
    input_f = argv[1];
    
   
    File file_aux(input_f, output_f);
    file_aux.Input();

    //file_aux.Output();
  

}