#ifndef SET_H_
#define SET_H_

#include <string>
#include <sstream>
#include <vector>
#include <iostream>


class Set {
  public:
    Set();
    Set(int&);
    ~Set();
    void Work (std::string);
    void read (std::string);
    void write(std::string);
    void operator=(std::string);
    //void operator>>(Set, std::string&);
   // Set operator+(Set, int);
    void operator+(int);
    void PrintSet (void);


  private:
    std::vector<unsigned long int> set_storage;
    unsigned long int set_;
    std::string expression1_;
    std::string expression2_;
    std::string result_;
    int max_elements_;
    std::vector<std::string> Split (std::string,std::string);
    std::string FindOperators(std::string);
    void Operate(std::string, std::string );
    bool CheckSyntax(std::string);
    std::vector<unsigned long int> Range(std::vector<int>);
    unsigned long int Convert (std::vector<int>);
    unsigned long int Complement (unsigned long int);
    unsigned long int Union (unsigned long int, unsigned long int);
    unsigned long int Intersection (unsigned long int, unsigned long int);
    unsigned long int RelativeComplement (unsigned long int, unsigned long int);
    void PrintBits (unsigned long int);
    std::vector<int> ExtractIntegerWords(std::string);

};

#endif //SET_H_