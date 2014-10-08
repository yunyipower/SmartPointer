#include "vehicle.h"
#include <iostream>

A::A():num_(0){
}

A::A(int num):
    num_(num){
}

void A::PrintNum(){
    cout<<num_<<endl;
}

template <typename T>
SP<T>::SP():pt_(NULL),
    reference_count_(new RfCount(0)){
        cout<<"default SP constructor."<<endl;
    }

template <typename T>
SP<T>::SP(T *pt):
    pt_(pt),
    reference_count_(new RfCount(0)){
    cout<<"SP constructor1 adds referencecount by 1."<<endl;
    reference_count_->AddRef();
}

template <typename T>
SP<T>::SP(const SP<T>& sp):pt_(sp.pt_),
    reference_count_(sp.reference_count_){
        cout<<"SP constructor2 adds referencecount by 1."<<endl;
        reference_count_->AddRef();
}

template <typename T>
SP<T>::~SP(){
    cout<<"SP destructor cut referencecount by 1."<<endl;
    if(reference_count_->CutRef() == 0){
        cout<<"release the object."<<endl;
        delete pt_;
    }
}

template <typename T>
SP<T>& SP<T>::operator=(const SP &sp){
    if(this != &sp){
        reference_count_ = sp.reference_count_;
        cout<<__FUNCTION__<<" "<<"refcount added by 1."<<endl;
        reference_count_->AddRef();
        pt_ = sp.pt_;
    }
    return *this;
}

template class SP<A>;