#ifndef __ITERATOR_TEST_HPP__
#define __ITERATOR_TEST_HPP__

#include "gtest/gtest.h"
#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include "pow.hpp"


TEST(IteratorTest, EvaluateNewOp){
    Op* a = new Op(2.0);
    EXPECT_EQ(a->create_iterator()->current(), nullptr);
    EXPECT_EQ(a->get_left(), nullptr);
    EXPECT_EQ(a->get_right(), nullptr);
}


//TEST(IteratorTest, EvaluateNewAdd){
//    Op* a = new Op(2.0);
//    Op* b = new Op(3.0);
//    Add* res = new Add(a, b);
//    EXPECT_EQ(res->evaluate(), 5);
//    EXPECT_EQ(res->get_left(), a);
//    EXPECT_EQ(res->get_right(), b);
//}


TEST(IteratorTest, EvaluateNewPow){
    Op* a = new Op(2.0);
    Op* b = new Op(3.0);
    Pow* res = new Pow(a, b);
    EXPECT_EQ(res->evaluate(), 8);
    EXPECT_EQ(res->get_left(), a);
    EXPECT_EQ(res->get_right(), b);
}



#endif
