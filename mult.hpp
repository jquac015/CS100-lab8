#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"
#include "iterator.hpp"
#include "visitor.hpp"

class Mult : public Base {
public:
    Base* val1;
    Base* val2;
    Mult(Base* value1, Base* value2) : Base() { val1 = value1; val2 = value2;}
    virtual double evaluate() {return (val1->evaluate())*(val2->evaluate());}
    virtual std::string stringify() {return val1->stringify() + "*" + val2->stringify();}
    virtual Iterator* create_iterator(){
        Iterator* it = new BinaryIterator(this);
        return it;
    }
    virtual Base* get_left(){ return val1; }
    virtual Base* get_right(){ return val2; }
};

#endif
