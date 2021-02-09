#ifndef LAB2_OPERATIONFACTORY_H
#define LAB2_OPERATIONFACTORY_H

#include <string>
#include <map>
#include "IOperationMaker.h"

class OperationFactory {
    std::map<std::string, IOperationMaker *> operations;
private:
    OperationFactory() = default;

public:
    OperationFactory(const OperationFactory &) = delete;

    static OperationFactory &getInstance();

    void registerMaker(const std::string &name, IOperationMaker *operatorMaker);

    IOperationMaker &getOperationMaker(const std::string &name);
};

#endif