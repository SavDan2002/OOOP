#pragma once

#include "OperationFactory.h"

OperationFactory &OperationFactory::getInstance() {
    static OperationFactory result;
    return result;
}

void OperationFactory::registerMaker(const std::string &name, IOperationMaker *operatorMaker) {
    operations[name] = operatorMaker;
}

IOperationMaker &OperationFactory::getOperationMaker(const std::string &name) {
    if (operations.find(name) != operations.end()) {
        return *operations[name];
    }
    else {
        throw std::logic_error("Unknown operation");
    }
}

