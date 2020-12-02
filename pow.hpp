#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include "iterator.hpp"
#include "visitor.hpp"

class Pow : public Base {
public:
    Base* base;
    Base* power;
    Pow(Base* a, Base* b) : Base() { base = a; power = b; }
    virtual double evaluate() {
       if(base->evaluate() == 0) {
            if(power->evaluate() > 0){
                return 0;
            } else {
                throw;
            }
       }

        if(power->evaluate() == 0 && base->evaluate() != 0) return 1;

        double res = base->evaluate();
        double pow = power->evaluate();
        if(pow > 0) {
            for(int i = 1; i < pow; ++i){
                res *= base->evaluate();
            }
            return res;
        } else {
            pow *= -1;
            for(int i = 1; i < pow; ++i){
                res *= base->evaluate();
            }
            return 1.0 / res;
        }
    }
    virtual std::string stringify() {return base->stringify() + "**" + power->stringify();}
    virtual Iterator* create_iterator(){
        Iterator* it = new BinaryIterator(this);
        return it;
    }
    virtual Base* get_left(){ return base; }
    virtual Base* get_right(){ return power; }
    virtual void accept(CountVisitor* visit){
        visit->visit_pow();
        visit->pow_count();
    }
};

#endif
