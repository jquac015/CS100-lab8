#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"
#include "iterator.hpp"
#include "visitor.hpp"

class Sub : public Base {
public:
    Base* val1;
    Base* val2;
    Sub(Base* first, Base* second) : Base() { val1 = first; val2 = second;}
    virtual double evaluate() {return (val1->evaluate() - val2->evaluate());}
    virtual std::string stringify() {return val1->stringify() + "-" + val2->stringify(); }
    virtual Iterator* create_iterator(){
        Iterator* it = new BinaryIterator(this);
        return it;
    }
    virtual Base* get_left(){ return val1; }
    virtual Base* get_right(){ return val2; }
    virtual void accept(CountVisitor* visit){
        visit->visit_sub();
    }
};

#endif
