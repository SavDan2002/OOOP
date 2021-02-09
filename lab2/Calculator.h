#ifndef LAB2_CALCULATOR_H
#define LAB2_CALCULATOR_H

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>
#include <memory>
#include "OperationMaker.h"
#include "OperationFactory.h"

class Calculator {
    std::list<double> stack;
    std::map<std::string, double> variables;
    std::ifstream *fin;
    std::ofstream *fout;
public:
    Calculator();

    Calculator(const std::string &in, const std::string &out);

    void calculate();

    ~Calculator();
};

#endif
