#ifndef _DFA_H
#define _DFA_H

#include <iostream>
#include <vector>
#include "Set.h"


class Dfa {
    public:
    struct Node {
    std::string state_one;
    std::string entry_;
    std::string state_two;
    };

    private:
    int how_many_symbols_;
    std::vector<std::string> alphabet_;
    int how_many_states_;
    std::vector<std::string> states_;
    int how_many_start_;
    int how_many_accept_state_;
    std::vector<std::string> accept_states_;
    std::string start_state_;
    std::vector<Node*> trans_;
    int how_many_trans_;
    Set set_alpha;
    std::string cadena_;

    public:
    Dfa();
    ~Dfa();
    void SetTransVector(std::string& stateone, std::string&  entry, std::string& statetwo);
    void SetStartingState(std::string&);
    void SetAcceptState(std::string&);
    void SetHowManyAcceptingStates(std::string&);
    void SetTransictions(std::string&);
    void SetNumberofSymbols(std::string&);
    void SetAlphabet(std::string&);
    int GetSizeAlph() { return how_many_symbols_;}
    void SetState(std::string&);
    void SetNumberofState(std::string&);
    int GetSizeState() { return how_many_states_;}
    int GetSizeAccept() { return  how_many_accept_state_;}
    void SetCadena(std::string&);
    bool Resolve();
    void Complete();
};

#endif