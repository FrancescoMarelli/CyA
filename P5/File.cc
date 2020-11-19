#include "File.h"



File::File(std::string& input_file, std::string& output_file) {
   SetInput(input_file);
   SetOutput(output_file);
   input_aux.open(GetInput());
   output_aux.open(GetOutput());   
   Set myset;
}

File::~File() {
     input_aux.close();
     output_aux.close();
}

void File::Output() {
   
 }
    
void File::Input() {
  std::ifstream fin;
  char ch_digit;
  fin.open(input_file_);
  if(fin.is_open()){
      int counter = 0;
     while(!fin.eof()) {
         fin.get(ch_digit);
            myset.DecToBinary(ch_digit);
            std::cout <<  "\n";

        }
        
    }else{
         std::cout << "Couldn't open the file, Try Again" << std::endl;
        }
        myset.Output(); 

fin.close();
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
