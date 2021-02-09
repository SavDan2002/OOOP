#ifndef LAB2_OPERATIONMAKER_H
#define LAB2_OPERATIONMAKER_H

#include "Operations.h"
#include "IOperationMaker.h"
#include "OperationFactory.h"
#include <string>

template<class T>
class OperationMaker : public IOperationMaker {
public:
    IOperation *create();

    OperationMaker(const std::string &str);
};

template<class T>
IOperation *OperationMaker<T>::create() {
    return new T();
}

template<class T>
OperationMaker<T>::OperationMaker(const std::string &str) {
    OperationFactory::getInstance().registerMaker(str, this);
}

#endif
