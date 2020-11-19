#include "File.h"
#include "Set.cc"

File::File(std::string& pattern, std::string& input_file, std::string& output_file) {
   SetInput(input_file);
   SetOutput(output_file);
   input_aux.open(GetInput());
   output_aux.open(GetOutput());
   Input(pattern);
}

File::~File() {
     input_aux.close();
     output_aux.close();
}

void File::Output(std::string& line) {
    if(output_aux.is_open()) {
            output_aux << line << "\n";
    }else{
         std::cout << "Couldn't open the file, Try Again" << std::endl;
        }  
        Set A;
        A.ConvertAlphabetToASCII();
 }
    
void File::Input(std::string&) {
  std::string line;
  Set A;
  if(input_aux.is_open()){
      int counter = 0;
     while(!input_aux.eof()) {
         getline(input_aux,line);
            //A.Decode(line);
            Output(line);
            std::cout <<  "\n";
        }
    }else{
         std::cout << "Couldn't open the file, Try Again" << std::endl;
        }
input_aux.close();
}

void File::SetInput(std::string& input) {
    input_file_ = input;
}

void File::SetOutput(std::string& output) {
    output_file_ = output;
}
std::string File::GetInput() {
    return input_file_;
}
std::string File::GetOutput() {
    return output_file_;
}


