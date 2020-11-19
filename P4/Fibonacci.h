#include <iostream>
#include <string>
#include <vector>


class Fibonacci {
    private:
        std::vector<std::string> fibonacci_word_;
        int number_of_words;
        
    public:
    Fibonacci(std::string& first, std::string& second, int position );
    ~Fibonacci();
   // bool IsFibonacci(std::string& word);
};