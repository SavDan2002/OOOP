#include "Calculator.h"

int main(int argv, char **args) {
    try {
        if (argv > 2) {
            Calculator calculator(args[1], args[2]);
            calculator.calculate();
        } else {
            Calculator calculator;
            calculator.calculate();
        }
    }
    catch (std::logic_error &ex) {
        std::cerr << ex.what() << std::endl;
    }
}
