#ifndef __LISTCONTAINER_HPP__
#define __LISTCONTAINER_HPP__

#include "container.hpp"
#include <list>
#include <iterator>
#include <iostream>
#include <cassert>

class ListContainer : public Container {
protected:
    std::list<Base*> conts;
public:
    ListContainer():Container(){};
    ListContainer(Sort* s):Container(s){};
    void set_sort_function(Sort* s){sort_function = s;}
    virtual void add_element(Base* element){conts.push_back(element);}
    virtual void print(){
        for(std::list<Base*>::iterator iter = conts.begin(); iter != conts.end(); iter++){
            cout << (*iter)->stringify() << ", ";
        }

    }
    virtual void sort(){sort_function->sort(this);}
    virtual void swap(int i, int j){
        assert(i<=conts.size());
        assert(i>=0);
        assert(j<=conts.size());
        assert(j>=0);
        if(i==j){return;}
        std::list<Base*>::iterator iter1 = conts.begin();
        std::list<Base*>::iterator iter2 = conts.begin();
        for(int x=0; x<i;x++){iter1++;}
        for(int y=0; y<j;y++){iter2++;}
        std::iter_swap(iter1,iter2);
    }


    virtual Base* at(int i){
        assert(i<=size());
        assert(i>=0);
        std::list<Base*>::iterator iter = conts.begin();
        for(int j = 0; j<i;j++){
            iter++;
        }
        return *iter;
    }
    virtual int size(){return conts.size();}

};

#endif