//Copyrights (C) owned by Francesco Marelli, <alu0101161730@ull.edu.es> 2020 

#include <iostream>
#include <vector>
#include <cstring>

//Cabezeras de las funciones
void Sieve (int& n);                                     // Función de Sieve/cernita
void Remove(std::vector<bool>& isPrime, int n);          // Remueve de la lista los numeros no primos
void Write(std::vector<bool>& isPrime);                  // Imprime la lista indicando cuales numeros son y no son primos



int main(int argc, char** argv) {
    int  dim = atoi(argv[1]);                       //lectura del input por la consola que es tamaño de la lista de numeros
    if (dim > 2 || argv[1] != NULL) {
        std::cout << "bien";
    }
    // } else if ( dim < 2){
    //     std::cout << "Again";
    //     std::cin >> dim;
    
    Sieve(dim);                                     //Cernita de los numeros primos
    return 0;
};

void Sieve(int& n) //dim
{  
    std::vector<bool> sieve_primes(n,true);                 //Se consideran todos los numeros como primos
    Remove(sieve_primes, n);                                //marcar los numeros que no son primos
    Write(sieve_primes);
}


void Remove(std::vector<bool>& isPrime, int n)
{ 
     
    for(int  p = 2; p * p <= n; p++) {
        if(isPrime[p] == true)  {
            for (int i = p * p; i < n; i += p) {                 //recorrido de los multiplos 
                isPrime[i] = false;                              // si son multiplos no pertenecen a los numeros primos
            } 
        }
    }
};

void Write(std::vector<bool>& isPrime) {
      for(unsigned i = 2; i < isPrime.size(); i++) {            //el iterador empieza en 2 porque 1 y 0 no son considerados numeros primos
        if(isPrime[i]) {                                        //si el numero de la lista inicial es primo 
            std::cout << "Es un numero primo: ";
            std::cout << i << " " << std::endl;
        } else {
            std::cout << "No es numero primo: ";
            std::cout << i << " " << std::endl;
        }
      }
        std::cout << std::endl;
}
