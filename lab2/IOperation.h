#ifndef LAB2_IOPERATION_H
#define LAB2_IOPERATION_H

#include <list>
#include <string>
#include <map>
#include <iostream>

class IOperation {
public:
    virtual void
    calculate(std::list<std::string> arguments, std::list<double> &stack, std::map<std::string, double> &variables,
              std::ofstream *output) = 0;

    virtual ~IOperation() = default;
};
#endif
