#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include "iterator.hpp"
#include "visitor.hpp"

class Op : public Base {
public:
    double val;

    Op(double value) : Base() { val = value; }
    virtual double evaluate() { return val; }
    virtual std::string stringify(){
        if(val < 0){
            return "(" + std::to_string(val) + ")";
        } else {
            return std::to_string(val);
        }
    }
    virtual Iterator* create_iterator(){
        Iterator* it = new NullIterator(this);
        return it;
    }
    virtual Base* get_left(){ return nullptr; }
    virtual Base* get_right(){ return nullptr; }
    virtual void accept(CountVisitor* visit){
        visit->visit_op();
    }
};

#endif
