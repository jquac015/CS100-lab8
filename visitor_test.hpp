#ifndef __VISITOR_TEST_HPP__
#define __VISITOR_TEST_HPP__

#include "visitor.cpp"
#include "iterator.hpp"
#include "preorder_iterator.cpp"
#include "gtest/gtest.h"
#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "sub.hpp"


TEST(CountVisitorTest, SubDiv) {
    Base* a = new Op(7);
    Base* b = new Op(5);
    Base* c = new Op(-2);
    Base* d = new Op(10);
    Sub* ab = new Sub(a, b);
    Div* cd = new Div(c, d);

    Add* dummy = new Add(ab, cd);

    CountVisitor *cv = new CountVisitor();
    Iterator* it = new PreorderIterator(dummy);
    it->first();
    while(!it->is_done()){
        it->current()->accept(cv);
        it->next();
    }
    EXPECT_EQ(cv->sub_count(), 1);
    EXPECT_EQ(cv->div_count(), 1);
    EXPECT_EQ(cv->op_count(), 4);
}


TEST(CountVisitorTest, AddMultSubDivPow) {
    Base* a = new Op(7);
    Base* b = new Op(5);
    Base* c = new Op(2);
    Base* d = new Op(4);

    Base* e = new Op(8);
    Base* f = new Op(7);
    Base* g = new Op(20);
    Base* h = new Op(5);

    Add* ab = new Add(a, b);
    Mult* cd = new Mult(c, d);

    Sub* ef = new Sub(e, f);
    Div* gh = new Div(g, h);

    Pow* ab_cd = new Pow(ab, cd);
    Pow* ef_gh = new Pow(ef, gh);

    Add* dummy = new Add(ab_cd, ef_gh);
    CountVisitor* cv = new CountVisitor();
    Iterator* it = new PreorderIterator(dummy);
    it->first();
    while (!it->is_done()) {
        it->current()->accept(cv);
        it->next();
    }
    EXPECT_EQ(cv->add_count(), 1);
    EXPECT_EQ(cv->sub_count(), 1);
    EXPECT_EQ(cv->mult_count(), 1);
    EXPECT_EQ(cv->div_count(), 1);
    EXPECT_EQ(cv->pow_count(), 2);
    EXPECT_EQ(cv->op_count(), 8);
}


TEST(CountVisitorTest, AddMultSubDivPow2) {
    Base* a = new Op(3);
    Base* b = new Op(-5);
    Base* c = new Op(11);
    Base* d = new Op(0);

    Base* e = new Op(5);
    Base* f = new Op(2);
    Base* g = new Op(1);
    Base* h = new Op(121);

    Base* i = new Op(1000);

    Sub* ab = new Sub(a, b);
    Div* cd = new Div(c, d);

    Add* ef = new Add(e, f);
    Mult* gh = new Mult(g, h);

    Sub* ab_cd = new Sub(ab, cd);
    Pow* ef_gh = new Pow(ef, gh);

    Sub* dummy = new Sub(ab_cd, ef_gh);
    Sub* dummy2 = new Sub(ab_cd, i);

    CountVisitor* cv1 = new CountVisitor();
    Iterator* it1 = new PreorderIterator(dummy);
    CountVisitor* cv2 = new CountVisitor();
    Iterator* it2 = new PreorderIterator(dummy2);
    it1->first();
    it2->first();
    while (!it1->is_done()) {
        it1->current()->accept(cv1);
        it1->next();
    }
    while (!it2->is_done()) {
        it2->current()->accept(cv2);
        it2->next();
    }
    EXPECT_EQ(cv1->add_count(), 1);
    EXPECT_EQ(cv1->mult_count(), 1);
    EXPECT_EQ(cv1->sub_count(), 2);
    EXPECT_EQ(cv1->div_count(), 1);
    EXPECT_EQ(cv1->pow_count(), 1);
    EXPECT_EQ(cv1->op_count(), 8);

    EXPECT_EQ(cv2->add_count(), 0);
    EXPECT_EQ(cv2->mult_count(), 0);
    EXPECT_EQ(cv2->sub_count(), 2);
    EXPECT_EQ(cv2->div_count(), 1);
    EXPECT_EQ(cv2->pow_count(), 0);
    EXPECT_EQ(cv2->op_count(), 5);
}

//                      dummy1       dummy2
//                   /         \   /       \
//                abcd    -    efgh         i
//               /    \       /    \
//             ab  -  cd     ef pow gh
//            /  \   /  \   / \    /  \
//           a - b  c / d  e + f  g * h

#endif
