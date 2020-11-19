#include "Dfa.h"

#include <string>

Dfa::Dfa():
how_many_accept_state_(0),
how_many_states_(0),
how_many_start_(0),
how_many_trans_(0)
{}

Dfa::~Dfa(){ 
    while(!trans_.empty()){
        Node* aux = new Node {NULL,
        NULL,
        NULL};
        delete aux;
        aux = NULL;
       delete trans_.back();
    trans_.pop_back();
    }
}

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
    Node* mynode = new Node {  stateone, entry, statetwo};
    trans_.push_back(mynode);
    delete mynode;
    mynode = NULL;

}

// Vector de cadenas
void Dfa::SetCadena(std::string& cadena){ 
    cadena_=cadena;
}

// Resolver dfa
void Dfa::Resolve(){
    
    Complete();

    // for(unsigned i = 0; i < trans_.size(); i++){
    //     std::cout << trans_.at(i)->state_one <<" "<< trans_.at(i)->entry_ <<" "<< trans_.at(i)->state_two << std::endl;
    // }

    std::cout << "Lenght " << cadena_.length() << std::endl;
//  estado actual = q0
    std::string estado_actual = trans_.at(0)->state_one;
    std::cout << "Estado Inicial: " << estado_actual << std::endl;
    for(unsigned j = 0; j < cadena_.length(); ++j){
        for(unsigned i = 0; i < trans_.size(); ++i) {
            std::string s(1, cadena_.at(j));
           // std::cout << "Lenght de " << s << " " << s.length() << std::endl;
        
            if((estado_actual == (trans_.at(i)->state_one)) && 
                (s == (trans_.at(i)->entry_))) {
                
                std::cout << "Estado Actual: " << estado_actual << std::endl; 
                std::cout << "entrada: " << s << std::endl;
                estado_actual = trans_.at(i)->state_two;
                std::cout << "Estado Final: " << estado_actual<< std::endl;
                
            }
        }
    }
    bool accept;
        // Compruebo si estado actual es de aceptación
        for(unsigned i = 0; i < accept_states_.size(); ++i){
            if(estado_actual.compare( accept_states_[i])) {
                accept =true ;
            }else{
            accept = false;
            }
        } 

        if(accept==true){
            std::cout << "Se acepta la cadena"<<std::endl;
        }  else{
        std::cout << "No se acepta la cadena "<<std::endl;
        }
}

void Dfa::Complete(){
    bool complete = false;
    // Creo vector fanthom con todas las posibles transicciones
    std::vector<Node*> fanthom;
    std::string death = "Muero";
    if(trans_.size() == (alphabet_.size() * states_.size())) {
        complete = true;
    }else{
        // std::cout << "imprimo el vector estados: "<<std::endl;
        // for (int u = 0; u < states_.size(); ++u) {
        //     std::cout << states_.at(u) << " ";
        // }
        // std::cout << std::endl;
        
        // std::cout << "imprimo el vector simbolos: "<<std::endl;
        // for (int u = 0; u < alphabet_.size(); ++u) {
        //     std::cout << alphabet_.at(u) << " ";
        // }
        // std::cout << "tamaño de alpa: "<<alphabet_.size(); 
        // std::cout << "1: "<<alphabet_.at(0);
        // std::cout << "2: "<<alphabet_.at(1);
        // std::cout << std::endl;
        
        for(unsigned j = 0; j < states_.size(); ++j) {
          for(unsigned i = 0; i < alphabet_.size(); ++i) { 
                Node* aux = new Node { states_.at(j),
                                       alphabet_.at(i),
                                       death};
                fanthom.push_back(aux);
                std::cout <<"meto en fanthom: " <<aux->state_one << " " << aux->entry_  <<  " " << aux-> state_two << std::endl;
                delete aux;
                aux = NULL;
            }
        } 
        // Ahora fanthom tiene todas las permutaciones 
        // Me quedo con las transicciones resta entre trans_ y fanthom
        
        // //debug prints
        // std::cout << "Imprimo el trans: "<<std::endl;
        // for (unsigned int pl = 0; pl < trans_.size(); ++pl) {
        //     std::cout << trans_.at(pl)->state_one << " " << trans_.at(pl)->entry_ << " " << trans_.at(pl)->state_two << std::endl;
        // }
        // std::cout << "Imprimo el fanthom: "<<std::endl;
        // for (unsigned int pl = 0; pl < fanthom.size(); ++pl) {
        //     std::cout << fanthom.at(pl)->state_one << " " << fanthom.at(pl)->entry_  << std::endl;
        // }

        unsigned int iterador = 0;
        while(iterador < fanthom.size()) {
            for(unsigned int i = 0; i < trans_.size(); ++i) {
                if(((fanthom.at(iterador)->state_one) == (trans_.at(i)->state_one)) && 
                   ((fanthom.at(iterador)->entry_ ) == (trans_.at(i)->entry_))) {  
                     free(fanthom.at(iterador));
                     //fanthom.erase(fanthom.begin() + iterador);
                    iterador = 0;
                   std::cout << "fanthom size: " << fanthom.size()<<  std::endl;//eso no lo vee
                   }
            }
            iterador++;
        }
         std::cout << "trans_size(): "<<trans_.size()<< "fanthom: " << fanthom.size()<<  std::endl;
        //  std::cout << "Imprimo fanthom" << std::endl; 
        //  for(unsigned i = 0; i < fanthom.size(); i++) { 
        //      std::cout << fanthom.at(i)->entry_<< " " << fanthom.at(i)->state_one << " " << fanthom.at(i)->state_one << std::endl;
        //  }

        for(unsigned i = 0; i < fanthom.size(); ++i) {
            Node* aux = new Node { fanthom.at(i)->state_one,
                                   fanthom.at(i)->entry_,
                                   "Death"};
            trans_.push_back(aux);
            delete aux;
            aux = NULL;
        }
        complete = true;
    }
    std::cout << "trans_size(): "<<trans_.size()<< "fanthom: " << fanthom.size()<<  std::endl;
     
    //  for(unsigned i = 0; i < trans_.size(); ++i) {
    //      std::cout << trans_.at(i)->state_one <<trans_.at(i)->entry_ <<trans_.at(i)->state_two << std::endl;
    //  }

      
    }


    


