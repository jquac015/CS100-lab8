#ifndef __COUNTVISITOR_HPP__
#define __COUNTVISITOR_HPP__

#include "visitor.hpp"
#include "preorder_iterator.cpp"

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
void CountVisitor::visit_op(){

}
int CountVisitor::op_count(){ops+=1;}
void CountVisitor::visit_rand(){

}
int CountVisitor::rand_count(){rands+=1;}
void CountVisitor::visit_mult(){

}
int CountVisitor::mult_count(){mults+=1;}
void CountVisitor::visit_div(){

}
int CountVisitor::div_count(){divs+=1;}
void CountVisitor::visit_add(){

}
int CountVisitor::add_count(){add+=1;}
void CountVisitor::visit_sub(){

}
int CountVisitor::sub_count(){sub+=1;}
void CountVisitor::visit_pow(){

}
int CountVisitor::pow_count(){pow+=1;}

#endif //__COUNTVISITOR_HPP__
