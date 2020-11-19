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
#ifndef _CAPICUA_H
#define _CAPICUA_H



#include <string>
#include <iostream>
#include <vector>
#include <fstream>


class Capicua
{
private:
 unsigned int digits_;             
 unsigned int max_;                 
 unsigned int min_;                 
 std::string output_file_;          


public:
    // Constructor and Destructor
    
    Capicua( int digits, std::string& output_file);
    ~Capicua();

    //setters
    void SetDigits(unsigned int digits);
    void SetMax(unsigned int max);
    void SetMin(unsigned int min);
    void SetOutput(std::string& output_file);

   //getters
   int GetDigits();
   unsigned int GetMax();
   int GetMin();
   std::string GetOutput();
   
   //Multiply each number of n digits
   int Product(std::vector<int>&  number);
   
   //Check if the product is palindrome or note
   bool IsPalindrome(int  number);

   //Print the palindrome result onto an outputfile
   void Output(int product, int l_factor, int r_factor, std::ofstream& output_file);
   bool IsNumber(const std::string& s);
   void NumberOfDigits(std::string& output_file);

};

#endif