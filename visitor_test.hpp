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

TEST(CountVisitorTest, Add_Sub){
    Op* a = new Op(5.0);
    Op* b = new Op(2.5);
    Pow* temp = new Pow(a, b);
    Base* dummy = new Add(temp, b);

    Iterator* it = dummy->create_iterator();
    CountVisitor* cv = new CountVisitor();
    while(!it->is_done()){
        Base* phase = it->current();
        phase->accept(cv);
        it->next();
    }

    EXPECT_EQ(cv->op_count(), 2);
    EXPECT_EQ(cv->pow_count(), 1);
    EXPECT_EQ(cv->add_count(), 0);

}




#endif
