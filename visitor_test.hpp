#ifndef __VISITOR_TEST_HPP__
#define __VISITOR_TEST_HPP__

#include "visitor.cpp"
#include "gtest/gtest.h"
#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "sub.hpp"

TEST(CountVisitorTest, PowAdd){
    Base* a = new Op(3);
    Base* b = new Op(7);
    Pow* ab = new Pow(a, b);

    Base* dummy = new Add(ab, b);

    Iterator* it = dummy->create_iterator();
    CountVisitor* cv = new CountVisitor();
    it->first();

    while(!it->is_done()){
        it->current()->accept(cv);
        it->next();
    }

    EXPECT_EQ(cv->op_count(), 1);
    EXPECT_EQ(cv->pow_count(), 1);
    EXPECT_EQ(cv->add_count(), 0);
}


TEST(CountVisitorTest, SubDiv) {
    Base* a = new Op(7);
    Base* b = new Op(5);
    Base* c = new Op(-2);
    Base* d = new Op(10);
    Sub* ab = new Sub(a, b);
    Div* cd = new Div(c, d);

    Base* dummy = new Add(ab, cd);

    CountVisitor *cv = new CountVisitor();
    PreorderIterator* it = new PreorderIterator(dummy);
    it->first();
    while(!it->is_done()){
        it->current()->accept(cv);
        it->next();
    }
    EXPECT_EQ(cv->sub_count(), 1);
    EXPECT_EQ(cv->div_count(), 1);
    EXPECT_EQ(cv->op_count(), 4);
}

#endif
