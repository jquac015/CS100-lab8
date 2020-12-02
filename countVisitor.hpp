#ifndef __COUNTVISITOR_HPP__
#define __COUNTVISITOR_HPP__

#include "visitor.hpp"

using namespace std;

CountVisitor::CountVisitor(){
    ops=0;
    rands=0;
    mults=0;
    divs=0;
    add=0;
    sub=0;
    pow=0;
}
void CountVisitor::visit_op(){ops+=1;}
int CountVisitor::op_count(){return ops;}
void CountVisitor::visit_rand(){rands+=1;}
int CountVisitor::rand_count(){return rands;}
void CountVisitor::visit_mult(){mults+=1;}
int CountVisitor::mult_count(){return mults;}
void CountVisitor::visit_div(){divs+=1;}
int CountVisitor::div_count(){return divs;}
void CountVisitor::visit_add(){add+=1;}
int CountVisitor::add_count(){return add;}
void CountVisitor::visit_sub(){sub+=1;}
int CountVisitor::sub_count(){return sub;}
void CountVisitor::visit_pow(){pow+=1;}
int CountVisitor::pow_count(){return pow;}

#endif //__COUNTVISITOR_HPP__
