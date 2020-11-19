//  
//  University of La Laguna
//  Computer Science Degree 
//  Subject : Computabilidad y Algoritmia
//  Second Course
//  Developer/Student : Francesco Marelli
//  email: alu0101161730@ull.edu.es
//  Third Subjcet Practice 
//  Professor: Francisco de Sande Gonzalez
//  Date: 15/10/2020
//  Last Modification : 19/10/2020

//  'Producto Capicúa' is a program that calculates all the permutations of
//  the numbers of a certain number digit, inserted by the user, then it multiply 
// between them and finally print them in an output file .txt 

//  TIPS
//  Avoid type integers above 5 because the number of permutations is enourmous
//  and it will take too long, just consider that it will find more than 900
//  palindromic number and it will take a few minutes to run it
// 
// Compile with make clean
// 
// Run make
// 

#include "File.cc"
#include "Fibonacci.cc"

int main(int argc, char** argv) {

    std::string input_file = argv[1];
    std::string output_file = argv[2];
    File my_fibonacci(input_file,output_file);
  
//   switch (argc){
//   case 1: {
    
//     break;
//   }
//   case 2: {
    
//     break;
//   }
//   case 3: {
    
//     break;
//   }
//   default:
//     std::cout << "Try again" << std::endl;
//     break;
//   }

  
  return 0;    
};

