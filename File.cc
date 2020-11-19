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
    output_aux << line<<std::endl;
   
    
    // Set Alphabeto 
    for(int i = 0; i < mydfa_.GetSizeAlph();i++){
      getline(input_aux,line); 
      mydfa_.SetAlphabet(line);
      output_aux << line<<std::endl;
 
    }

    // Numero de Estados
    getline(input_aux,line);
    mydfa_.SetNumberofState(line);
    output_aux << line<<std::endl;

    
     // Set Vector Estados 
    for(int i = 0; i <mydfa_.GetSizeState();i++){ 
      getline(input_aux,line);
      mydfa_.SetState(line);
      output_aux << line<<std::endl;
    }
  
    //Set Estado Inicial 
    getline(input_aux,line);
    mydfa_.SetStartingState(line);
    output_aux << line<<std::endl;
    

    // Numero de Estados de Aceptación
    getline(input_aux,line);
    mydfa_.SetHowManyAcceptingStates(line); 
    output_aux << line<<std::endl;
  
    // Set Vector de Estados de Aceptación // te coge todo el pdf mria
   for(int i = 0; i < mydfa_.GetSizeAccept();i++){
      getline(input_aux,line);
      mydfa_.SetAcceptState(line); 
      
      output_aux <<  line<<std::endl;
   }
    // Transicciones
    getline(input_aux,line);
    mydfa_.SetTransictions(line);
    output_aux << line<<std::endl;
  
     
    //bueno si funciona bien, no importa
   // Dfa::Node aux;
    std::string entry_,state_one,state_two;
    while (input_aux >> state_one >> entry_ >> state_two ){

    mydfa_.SetTransVector(state_one, entry_, state_two);
    output_aux << state_one <<" "<<entry_ << " "<< state_two<<"\n";
   
    

    }

    // leer cadena
    std::ifstream read_pattern;
    read_pattern.open(pattern);
    
    if(read_pattern.is_open()){
      
      while(getline(read_pattern,line)){

        mydfa_.SetCadena(line);
        mydfa_.Resolve(); 
        
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


