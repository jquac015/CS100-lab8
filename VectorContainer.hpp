#ifndef __VECTORCONTAINER_HPP__
#define __VECTORCONTAINER_HPP__

#include "container.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <cassert>

using namespace std;

class VectorContainer : public Container{
protected:
    vector <Base*> v;

public:
    VectorContainer(): Container() {};
    VectorContainer(Sort* s): Container(s) {};

    void set_sort_function(Sort* s){ sort_function = s; }

    virtual	void add_element(Base* b){ v.push_back(b); }

    virtual	void print(){
        for(int i = 0; i < v.size() - 1; ++i){
            cout << v[i]->stringify() << ", ";
        }
        cout << v[v.size() - 1]->stringify() << endl;
    }

    virtual void sort(){
        sort_function->sort(this);
    }


    virtual void swap(int i, int j){
        assert(i >= 0);
        assert(i <= v.size() - 1);
        assert(j >= 0);
        assert(j <= v.size() - 1);
        if(i == j) { return;}

        Base* temp;
        temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }

    virtual Base* at(int i){
        assert(i >= 0);
        assert(i <= v.size() - 1);
        return v[i];
    }

    virtual int size(){ return v.size(); }
};

#endif