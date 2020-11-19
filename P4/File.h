#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class File {

    private:
    std::string input_file_;
    std::string output_file_;
    int number_of_words;
        

    public:
    File(std::string& input_file, std::string& output_file);
    ~File();
    void Output(std::ifstream& input, std::string& line);
    void Input(std::ifstream& input_file);
    void SetInput(std::string& input);
    void SetOutput(std::string& output);
    std::string& GetInput();
    std::string& GetOutput();
   // std::string& GetLine(std::string& line);
    
   
};