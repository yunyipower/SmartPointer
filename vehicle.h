#pragma once

#include <string>
#include <iostream>
using namespace std;

class RfCount
{
public:
    RfCount(){}
    RfCount(unsigned rfc):
        rfc_(rfc){
    }

    ~RfCount(){}

    unsigned AddRef(){
        return ++rfc_;
    }

    unsigned CutRef(){
        return --rfc_;
    }

private:
    unsigned rfc_;
};

template <typename T>
class SP
{
public:
    SP();
    SP(T *pa);
    SP(const SP<T>& sp);
    ~SP();

    T& operator*(){
        return *pt_;
    }

    T* operator->(){
        return pt_;
    }

    SP& operator=(const SP &sp);

    unsigned AddRef(){
        return reference_count_->AddRef();
    }

    unsigned CutRef(){
        return reference_count_->CutRef();
    }

private:
    RfCount* reference_count_;
    T *pt_;
};

class A
{
public:
    A();
    A(int num);
    ~A(){}

    void PrintNum();

private:
    int num_;
};