//  University of La Laguna
//  Computer Science Degree 
//  Subject : Computabilidad y Algoritmia
//  Second Course
//  Developer/Student : Francesco Marelli
//  email: alu0101161730@ull.edu.es
//  Seventh Subject Practice 
//  Professor: 
//  Date: 17/11/2020
//  Last Modification : 17/11/2020

#include "File.cc"
#include <iostream>

void ShowHelp(){
    std::cout << "Este programa establece a travès de un DFA si una cadena, introducida por pantalla"
                << "sigue el patrón del establecido por el enunciado.\n";
    std::cout << "El correcto funcionamiento del programa es:"
                << "./a.out [dfa.txt] [output.txt] [string]\n";
}

int main(int argc, char* argv[]){
   
    switch(argc)
    {
        case 0: {
        std::cout << "Introducir los ficheros de entrada y salida, y la cadena que se quiere evaluar, "
                    << "para mas info --help."<<std::endl;
        }
        break;
        case 1:{
            std::cout << "Introducir los ficheros de entrada y salida, y la cadena que se quiere evaluar, "
                         << "para mas info --help."<<std::endl;
        }
        break;
        case 2:{
            std::string argumento;
            argumento = argv[1];
            if(argumento == "--help"){
                ShowHelp();
            }
            else{
                std::cout << "Opción no valida, intente con '--help'\n";
            }
        }
         break;
         case 3: {
             std::cout << "Introducir una opción correcta: consultar opción --help\n";
             break;
         }       
        case 4: {
         std::string input_f;
         std::string output_f;
         std::string pattern;
         pattern = argv[1];
         input_f = argv[2];
         output_f = argv[3];
         File file_aux(pattern, input_f, output_f);

        }
         break;

        default:
        std::cout << "Introducir una opción correcta: consultar opción --help\n";
    }
   
}