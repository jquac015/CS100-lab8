#ifndef __ITERATOR_HPP__
#define __ITERATOR_HPP__

#include <stack>

//#include "base.hpp"
#include "container.hpp"

class Base;

enum ChildIndicator { left, right, end };

class Iterator {
    protected:
        Base* self_ptr;

    public:
        Iterator(Base* ptr) { 
            this->self_ptr = ptr; 
        }

        virtual void first() = 0;
        virtual void next() = 0;
        virtual bool is_done() = 0;
        virtual Base* current() = 0;
};


//This iterator is created by expression tree classes with two children,
//such as operators, and returns one of the children per iteration
class BinaryIterator : public Iterator {
    protected:
        ChildIndicator c;

    public:
        BinaryIterator(Base* ptr) : Iterator(ptr){
            c = left;
        }

        void first(){
            c = left;
        }

        void next(){
            if (c == left) {
                c = right;
            } else {
                c = end;
            }
        }

        bool is_done(){
            return c == end;
        }

        Base* current(){
            if (c == left){
                return self_ptr.get_left();
            } else if (c == right) {
                return self_ptr.get_right();
            } else {
                return nullptr;
            }
        }
};


//This iterator is created by expression tree
//classes which have no children to iterate over such as the operands
class NullIterator : public Iterator {
    public:
        NullIterator(Base* ptr) : Iterator(ptr) {}

        void first() {}
        void next() {}
        bool is_done() {
            return true;
        }
        Base* current() { 
            return nullptr; 
        }
};


//This iterator is created by a user to traverse an entire expression tree.
//Note that it will skip the first node in the expression tree so its helpful to
//add a "dummy" node as root which will be skipped
class PreorderIterator : public Iterator {
    protected:
        std::stack<Iterator*> iterators;

    public:
        PreorderIterator(Base* ptr) : Iterator(ptr){
            iterators = std::stack<Iterator*>();
        }

        void first(){
            while(!iterators.empty()){
                iterators.pop();
            }

            if(self_ptr){
                Iterator* it = self_ptr->create_iterator();
                it->first();
                iterators.push(it);
            }
        }

        void next(){
            Iterator* dummy =
        }

        bool is_done(){
            return iterators.empty();
        }

        Base* current(){
            if(!iterators.empty()){ return iterators.top(); }
            return nullptr;
        }
};

#endif
