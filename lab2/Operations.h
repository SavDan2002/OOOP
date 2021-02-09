#ifndef LAB2_OPERATIONS_H
#define LAB2_OPERATIONS_H

#include <list>
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <cmath>
#include "IOperation.h"
#include "OperationMaker.h"

class Pop : public IOperation {
public:
    void calculate(std::list<std::string> arguments, std::list<double> &stack, std::map<std::string, double> &variables,
                   std::ofstream *fout) override;
};

class Push : public IOperation {
public:
    void calculate(std::list<std::string> arguments, std::list<double> &stack, std::map<std::string, double> &variables,
                   std::ofstream *fout) override;
};

class Plus : public IOperation {
public:
    void calculate(std::list<std::string> arguments, std::list<double> &stack, std::map<std::string, double> &variables,
                   std::ofstream *fout) override;
};

class Minus : public IOperation {
public:
    void calculate(std::list<std::string> arguments, std::list<double> &stack, std::map<std::string, double> &variables,
                   std::ofstream *fout) override;
};

class Mul : public IOperation {
public:
    void calculate(std::list<std::string> arguments, std::list<double> &stack, std::map<std::string, double> &variables,
                   std::ofstream *fout) override;
};

class Div : public IOperation {
public:
    void calculate(std::list<std::string> arguments, std::list<double> &stack, std::map<std::string, double> &variables,
                   std::ofstream *fout) override;
};

class Sqrt : public IOperation {
public:
    void calculate(std::list<std::string> arguments, std::list<double> &stack, std::map<std::string, double> &variables,
                   std::ofstream *fout) override;
};

class Print : public IOperation {
public:
    void calculate(std::list<std::string> arguments, std::list<double> &stack, std::map<std::string, double> &variables,
                   std::ofstream *fout) override;
};

class Define : public IOperation {
public:
    void calculate(std::list<std::string> arguments, std::list<double> &stack, std::map<std::string, double> &variables,
                   std::ofstream *fout) override;
};

#endif //LAB2_OPERATIONS_H
