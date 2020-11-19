#include "File.h"


File::File( std::string& pattern, std::string& input_file, std::string& output_file) {

  SetInput(input_file);
  SetOutput(output_file);

  std::ifstream input_aux;
  std::ofstream output_aux;

  input_aux.open(GetInput());
  output_aux.open(GetOutput());
  
  std::string line;
  
  if(input_aux.is_open()){

    // Numero de simbolos de alfabeto
    getline(input_aux,line);
    mydfa_.SetNumberofSymbols(line);

    // Set Alphabeto 
    for(int i = 0; i < mydfa_.GetSizeAlph();i++){
      getline(input_aux,line); 
      mydfa_.SetAlphabet(line);
    }

    // Numero de Estados
    getline(input_aux,line);
    mydfa_.SetNumberofState(line);
    
     // Set Vector Estados 
    for(int i = 0; i <mydfa_.GetSizeState();i++){ 
      getline(input_aux,line);
      mydfa_.SetState(line);
    }
  
    //Set Estado Inicial 
    getline(input_aux,line);
    mydfa_.SetStartingState(line);
    
    // Numero de Estados de Aceptación
    getline(input_aux,line);
    mydfa_.SetHowManyAcceptingStates(line); 
  
    // Set Vector de Estados de Aceptación // te coge todo el pdf mria
   for(int i = 0; i < mydfa_.GetSizeAccept();i++){
      getline(input_aux,line);
      mydfa_.SetAcceptState(line); 
   }
    // Transicciones
    getline(input_aux,line);
    mydfa_.SetTransictions(line);
    
    // Leo el vector de transicciones
    std::string entry_,state_one,state_two;
    while (input_aux >> state_one >> entry_ >> state_two ){
      mydfa_.SetTransVector(state_one, entry_, state_two);
    }

    // leer cadena
    std::ifstream read_pattern;
    read_pattern.open(pattern);
    
    if(read_pattern.is_open()){
      
      while(getline(read_pattern,line)){

        mydfa_.SetCadena(line);
          if(mydfa_.Resolve() == true){
            output_aux << "La cadena " << line << " es aceptada por el automata." << std::endl;
          }else{
            output_aux << "La cadena " << line << " no es aceptada por el automata."<< std::endl;
          }
      }
    }else{
        std::cout << "Fichero input.dfa no se abrió"<<std::endl;
       }
    read_pattern.close();

    }else{
         std::cout << "Couldn't open the file, Try Again" << std::endl;
        }

input_aux.close();
output_aux.close();
}

File::~File() {
    
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


