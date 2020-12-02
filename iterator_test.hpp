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

TEST(IteratorTest, EvaluateAdd){
    Base* a = new Op(5);
    Base* b = new Op(4);
    Base* c = new Op(7);
    Base* d = new Op(3.5);
    Add* ab = new Add(a, b);
    Div* cd = new Div(c, d);

    Pow* dummy = new Pow(ab, cd);
    BinaryIterator* it = new BinaryIterator(dummy);
    EXPECT_EQ(dummy->get_left(), ab);
    EXPECT_EQ(dummy->get_right(), cd);
}


#endif
