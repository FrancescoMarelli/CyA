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

#include "Capicua.h"
#include <cmath>


//Constructor
Capicua::Capicua(int digits, std::string& output_file){

 SetDigits(digits);                                             //How many digits the number has
 SetMax(pow(10,digits));                                        //Superior extreme of numbers ex. 2 digits ->  99
SetMin(pow(10,digits - 1));                                     //Inferior extreme of number  ex. 2 digits -> 10
 SetOutput(output_file);

 std::vector<int> numeros(GetMax());                            //Storing cector of size 10^n and all the numbers of n digits
 for(unsigned int i = GetMin(); i < GetMax(); i++) {
     numeros[i] = i;                                            //Filling the Vector with those numbers
 }
 Product(numeros);                                          
}

Capicua::~Capicua() {}


//Scalar Product of each number
int Capicua::Product(std::vector<int>& number) {
std::ofstream output_file;                                      
output_file.open(output_file_);                                      
int count_cap = 0;
 std::vector<int> product(max_);                                    //Product storing vector 
  for(unsigned i= GetMin(); i < number.size(); i++) {
     for(unsigned j= GetMin(); j < number.size(); j++) {
         product[i] = number[i] * number[j];
           if(IsPalindrome(product[i])) {                               
            Output( product[i], number[i], number[j], output_file);
            count_cap++;
           }
        }
    }
    std::cout << "Numeros de Capicuas" << count_cap<< std::endl;
    
    output_file.close();
    return 0;
}

//Check if a number is Palindrome
bool Capicua::IsPalindrome(int number) {            
    int temp = number;
    int rest, sum = 0;
    
    while(number > 0) {
        rest = (number % 10);
        sum = (sum * 10) + rest;
        number = number / 10;
    }
    return temp == sum;
 }


//setters

void Capicua::SetOutput(std::string& output_file) {
    output_file_ = output_file;
}

void Capicua::SetDigits(unsigned int digits) {
    digits_ = digits; 
}

void Capicua::SetMax(unsigned int max) {
    max_ = max;
}

void Capicua::SetMin(unsigned int min) {
    min_ = min;
}

//getters

int Capicua::GetDigits() {
    return digits_;
}

unsigned int Capicua::GetMax() {
    return max_;
}

int Capicua::GetMin() {
    return min_;
}

std::string Capicua::GetOutput() {
    return output_file_;
}

//Print onto Output file the palindromic product in this way product = multicand * multiplier
void Capicua::Output(int prod, int l_factor, int r_factor, std::ofstream& output_file ) {
  if(output_file.is_open()) {
      output_file << prod << " = " << l_factor << " x " << r_factor << std::endl; 
  }
   else {
      std::cout << "Hubo un error en la apertura del fichero" << std::endl;
   } 
}

void Capicua::NumberOfDigits(std::string& output_file) {
   
std::fstream fin;
int counter = 0;
fin.open(output_file);
char num;
if(fin.is_open()) {
  while(!fin.eof()) {
     fin.get(num);
     if(isdigit(num)){
         counter++;
        } 
    }    
}
std::cout <<  counter  << std::endl;
        fin.close();
    
}

bool Capicua::IsNumber(const std::string& s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) {
        ++it;
    }
    return !s.empty() && it == s.end();
}





