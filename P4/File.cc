#include "File.h"
#include "Fibonacci.cc"


File::File(std::string& input_file, std::string& output_file) {

   SetInput(input_file);
   SetOutput(output_file);

   std::ifstream input_aux;
   std::ofstream output_aux;
   input_aux.open(GetInput());
   output_aux.open(GetOutput());
   
   
}

File::~File() {
    std::ofstream output(output_file_);
     output.close();
}

void File::Output(std::ifstream& input, std::string& line) {
    std::ofstream output_file;
    output_file.open(output_file_);

      if(output_file.is_open()){
        output_file << line << std::endl;      
    }
   
}

void File::Input(std::ifstream& input_file) {
  std::string line;
  std::vector<std::string> words;
  if(input_file.is_open()){
     int iterator = 0;
    while(getline(input_file, line)) {
       words[iterator] = line;
       Output(input_file, line);
       std::cout << words[iterator]<< std::endl;
       iterator++;
    }
    number_of_words = iterator;
     input_file.close();
   }else {
       std::cout << "Couldn't open the file, Try Again" << std::endl;
   } 
}

// bool File::IsFibonacci(std::string& word){
//    // std::string tmp;
//    // for(int i = 2; i <=number_of_words; i++) {
//    //    tmp = word[i];
//    //    word[i+1] += word[i];
//    //    word[i] = tmp;
//    // }
//    // return word;
// }

void File::SetInput(std::string& input) {
    input_file_ = input;
}

void File::SetOutput(std::string& output) {
    output_file_ = output;
}
std::string& File::GetInput() {
    return input_file_;
}
std::string& File::GetOutput() {
    return output_file_;
}
   // std::string& GetLine(std::string& line);