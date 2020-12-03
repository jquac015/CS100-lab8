#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include "iterator.hpp"
#include "visitor.hpp"
#include <cmath>

class Pow : public Base {
    private:
        Base* base;
        Base* power;

    public:
        Pow(Base* a, Base* b) : Base() { base = a; power = b; }
        virtual double evaluate() { return pow(base->evaluate(), power->evaluate()); }
        virtual std::string stringify() {return base->stringify() + "**" + power->stringify();}
        virtual Iterator* create_iterator(){
            Iterator* it = new BinaryIterator(this);
            return it;
        }
        virtual Base* get_left(){ return base; }
        virtual Base* get_right(){ return power; }
        virtual void accept(CountVisitor* visit){
            visit->visit_pow();
        }
};

#endif
