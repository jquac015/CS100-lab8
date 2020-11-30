#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"
#include "iterator.hpp"
#include "visitor.hpp"

class Rand : public Base {
public:
    Rand() : Base() {}
    double val = std::rand()%100;
    virtual double evaluate() {return val;}
    virtual std::string stringify() { return std::to_string(val); }
    virtual Iterator* create_iterator(){
        Iterator* it = new NullIterator(this);
        return it;
    }
    virtual Base* get_left(){ return nullptr; }
    virtual Base* get_right(){ return nullptr; }
};

#endif
