#include "Dfa.h"

#include <string>

Dfa::Dfa():
how_many_accept_state_(0),
how_many_states_(0),
how_many_start_(0),
how_many_trans_(0)
{}

Dfa::~Dfa(){}

 void Dfa::SetNumberofSymbols(std::string& symbols){
     int aux = std::stoi(symbols);
     how_many_symbols_ = aux;
 }
   
void Dfa::SetAlphabet(std::string& alphabet){
    alphabet_.push_back(alphabet);  
}

 void Dfa::SetNumberofState(std::string& states){
    int aux = std::stoi(states);
    how_many_states_ = aux; 
 }
   
void Dfa::SetState(std::string& states){
    states_.push_back(states);
}

void Dfa::SetStartingState(std::string& start ){
    start_state_=start;
}

void Dfa::SetHowManyAcceptingStates(std::string& n_accept_states ){
    int aux = std::stoi(n_accept_states); 
   how_many_accept_state_=aux; 
}

void Dfa::SetAcceptState(std::string& accepting_states){
    accept_states_.push_back(accepting_states);
}


void Dfa::SetTransictions(std::string& transictions ){
    int aux = std::stoi(transictions);
    how_many_trans_= aux;
}

void Dfa::SetTransVector(std::string& stateone, std::string& entry, std::string& statetwo){
    Dfa::Node* mynode = new Node {  stateone, entry, statetwo};
    trans_.push_back(mynode);
}

// Vector de cadenas
void Dfa::SetCadena(std::string& cadena){ 
    cadena_=cadena;
}

 // Completo vector de transicciones con los estados de muerte
 void Dfa::Complete(){
    bool complete = false;
    // Creo vector fanthom con todas las posibles transicciones
    std::vector<Node*> fanthom;
    std::string death = "Estado de Muerte";
    // Si trans_ = alphabet.size*state:size significa que el dfa ya tiene todas las permutaciones posibles Sino relleno
    if(trans_.size() != (alphabet_.size() * states_.size())) {
    
        for(unsigned j = 0; j < states_.size(); ++j) {
          for(unsigned i = 0; i < alphabet_.size(); ++i) { 
                Node* aux = new Node { states_.at(j),
                                       alphabet_.at(i),
                                       death};
               fanthom.push_back(aux);
            }
        } 
        // Ahora fanthom tiene todas las permutaciones 
        // Ahora borro las transicciones que estan en fanthom y en trans_, para luego añadirselas a trans_
        unsigned int iterador = 0;
        while(iterador < fanthom.size()) {
            for(unsigned int i = 0; i < trans_.size(); ++i) {
                std::string est1_fant = fanthom.at(iterador)->state_one ;
                std::string est1_trans = trans_.at(i)->state_one;
                std::string est2_fant = fanthom.at(iterador)->entry_  ;
                std::string est2_trans = trans_.at(i)->state_one;
                if((est1_fant == (est1_trans)) &&  (est2_fant == est2_trans)) {  
                     fanthom.erase(fanthom.begin() + iterador);
                     iterador = 0;
                   }
            }
            iterador++;
        }
       // Fill el vector de transicciones con lo los estados que quedaron en fanthom
        for(unsigned i = 0; i < fanthom.size(); ++i) {
            Node* aux = new Node { fanthom.at(i)->state_one,
                                   fanthom.at(i)->entry_,
                                   "Estado de Muerte"};
            trans_.push_back(aux);
        }
    }
      
    }


// Resolver dfa
bool Dfa::Resolve(){
     
    // Completo vector de transicciones con los estados de muerte
    Complete();
    //  estado actual = q0
    std::string estado_actual = trans_.at(0)->state_one;
    // std::cout << "Estado Inicial: " << estado_actual << std::endl;
    for(unsigned j = 0; j < cadena_.length(); ++j){
        for(unsigned i = 0; i < trans_.size(); ++i) {
            std::string s(1, cadena_.at(j));
           
            if((estado_actual == (trans_.at(i)->state_one)) && (s == (trans_.at(i)->entry_))) {
                estado_actual = trans_.at(i)->state_two;
                break;                                  // para que no siga iterando todas las transicciones y estado actual sea correcto
            }
        }
    }
    // Flag para comprobar si se acepta o no la cena
    bool accept = false;
        // Compruebo si estado actual es de aceptación
        for(unsigned i = 0; i < accept_states_.size(); ++i){
            if(estado_actual == accept_states_[i]) {
                accept = true;  
            }
        }
        return accept;
}



    


