#ifndef __ITERATOR_TEST_HPP__
#define __ITERATOR_TEST_HPP__

#include "gtest/gtest.h"
#include "base.hpp"
#include "add.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "sub.hpp"
#include "op.hpp"

TEST(IteratorTest, OpRand){
    Base* a = new Op(2);
    Rand* b = new Rand();

    Pow* dummy = new Pow(a, b);
    BinaryIterator* it = new BinaryIterator(dummy);
    EXPECT_EQ(dummy->get_left(), a);
    EXPECT_EQ(dummy->get_right(), b);
}

TEST(IteratorTest, AddSub){
    Base* a = new Op(5);
    Base* b = new Op(4);
    Base* c = new Op(7);
    Base* d = new Op(3.5);
    Add* ab = new Add(a, b);
    Sub* cd = new Sub(c, d);

    Pow* dummy = new Pow(ab, cd);
    BinaryIterator* it = new BinaryIterator(dummy);
    EXPECT_EQ(dummy->get_left(), ab);
    EXPECT_EQ(dummy->get_right(), cd);
}

TEST(IteratorTest, MultDiv){
    Base* a = new Op(8.2);
    Base* b = new Op(1.1);
    Base* c = new Op(9);
    Base* d = new Op(0);
    Mult* ab = new Mult(a, b);
    Div* cd = new Div(c, d);

    Pow* dummy = new Pow(ab, cd);
    BinaryIterator* it = new BinaryIterator(dummy);
    EXPECT_EQ(dummy->get_left(), ab);
    EXPECT_EQ(dummy->get_right(), cd);
}

TEST(IteratorTest, Pow){
    Base* a = new Op(9.4);
    Base* b = new Op(2.2);
    Pow* ab = new Pow(a, b);

    Pow* dummy = new Pow(a, b);
    BinaryIterator* it = new BinaryIterator(dummy);
    EXPECT_EQ(dummy->get_left(), a);
    EXPECT_EQ(dummy->get_right(), b);
}

#endif
