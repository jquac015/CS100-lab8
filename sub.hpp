#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"
#include "iterator.hpp"
#include "visitor.hpp"

class Sub : public Base {
public:
    Base* val1;
    Base* val2;
    Sub(Base* first, Base* second) : Base() { a = first; b = second;}
    virtual double evaluate() {return (a->evaluate() - b->evaluate());}
    virtual std::string stringify() {return a->stringify() + "-" + b->stringify(); }
    virtual Iterator* create_iterator(){
        Iterator* it = new BinaryIterator(this);
        return it;
    }
    virtual Base* get_left(){ return val1; }
    virtual Base* get_right(){ return val2; }
};

#endif
