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

#include <iostream>
#include <regex>
#include <sstream>


//Checks if the input argument is a number
bool IsNumber(const std::string& s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

void Usage() {
    std::cout << "Correct usage of this program is ./palindrome_prod.cc number filename.txt" << std::endl;
}

void WellDone() {
    std::cout << "Check the file !" << std::endl;
}

void NotEnough() {
 std::cout << "Not enough arguments  " << std::endl;
}