#include "Operations.h"

namespace {
    OperationMaker<Pop> pop("POP");
    OperationMaker<Push> push("PUSH");
    OperationMaker<Plus> plus("+");
    OperationMaker<Minus> minus("-");
    OperationMaker<Mul> mul("*");
    OperationMaker<Div> dic("/");
    OperationMaker<Sqrt> SQRT("SQRT");
    OperationMaker<Print> print("PRINT");
    OperationMaker<Define> define("DEFINE");
}

void Pop::calculate(std::list<std::string> arguments, std::list<double> &stack, std::map<std::string, double> &variables,
               std::ofstream *fout) {
    if (arguments.size() > 0) {
        throw std::logic_error("Wrong number of arguments");
    }
    if (stack.size() == 0) {
        throw std::logic_error("Stack is empty");
    }
    stack.pop_front();
}

void Push::calculate(std::list<std::string> arguments, std::list<double> &stack, std::map<std::string, double> &variables,
                std::ofstream *fout) {
    if (arguments.size() != 1) {
        throw std::logic_error("Wrong number of arguments");
    }
    double value;
    if (variables.find(arguments.front()) != variables.end()) {
        value = variables[arguments.front()];
    } else {
        value = stod(arguments.front(), nullptr);
    }
    stack.push_front(value);
}

void Plus::calculate(std::list<std::string> arguments, std::list<double> &stack, std::map<std::string, double> &variables,
                std::ofstream *fout) {
    if (arguments.size() > 0) {
        throw std::logic_error("Wrong number of arguments");
    }
    double value = 0;
    if (stack.size() < 2) {
        throw std::logic_error("Stack is empty");
    }
    value += stack.front();
    stack.pop_front();
    value += stack.front();
    stack.pop_front();
    stack.push_front(value);
}

void Minus::calculate(std::list<std::string> arguments, std::list<double> &stack, std::map<std::string, double> &variables,
                 std::ofstream *fout) {
    if (arguments.size() > 0) {
        throw std::logic_error("Wrong number of arguments");
    }
    double value = 0;
    if (stack.size() < 2) {
        throw std::logic_error("Stack is empty");
    }
    value += stack.front();
    stack.pop_front();
    value -= stack.front();
    stack.pop_front();
    stack.push_front(value);
}

void Mul::calculate(std::list<std::string> arguments, std::list<double> &stack, std::map<std::string, double> &variables,
               std::ofstream *fout) {
    if (arguments.size() > 0) {
        throw std::logic_error("Wrong number of arguments");
    }
    double value = 0;
    if (stack.size() < 2) {
        throw std::logic_error("Stack is empty");
    }
    value += stack.front();
    stack.pop_front();
    value *= stack.front();
    stack.pop_front();
    stack.push_front(value);
}

void Div::calculate(std::list<std::string> arguments, std::list<double> &stack, std::map<std::string, double> &variables,
               std::ofstream *fout) {
    if (arguments.size() > 0) {
        throw std::logic_error("Wrong number of arguments");
    }
    double value = 0;
    if (stack.size() < 2) {
        throw std::logic_error("Stack is empty");
    }
    value += stack.front();
    stack.pop_front();
    if (stack.front() != 0) {
        value /= stack.front();
    } else {
        throw std::logic_error("Division by zero");
    }
    stack.pop_front();
    stack.push_front(value);
}

void Sqrt::calculate(std::list<std::string> arguments, std::list<double> &stack, std::map<std::string, double> &variables,
                std::ofstream *fout) {
    if (arguments.size() > 0) {
        throw std::logic_error("Wrong number of arguments");
    }
    double value = 0;
    if (stack.size() < 1) {
        throw std::logic_error("Stack is empty");
    }
    value += stack.front();
    stack.pop_front();
    value = sqrt(value);
    stack.push_front(value);
}

void Print::calculate(std::list<std::string> arguments, std::list<double> &stack, std::map<std::string, double> &variables,
                 std::ofstream *fout) {
    if (arguments.size() > 0) {
        throw std::logic_error("Wrong number of arguments");
    }
    double value = 0;
    if (stack.size() < 1) {
        throw std::logic_error("Stack is empty");
    }
    value += stack.front();
    if (fout != nullptr) {
        *fout << value << std::endl;
    } else {
        std::cout << value << std::endl;
    }
}

void Define::calculate(std::list<std::string> arguments, std::list<double> &stack, std::map<std::string, double> &variables,
                  std::ofstream *fout) {
    if (arguments.size() != 2) {
        throw std::logic_error("Wrong number of arguments");
    }
    std::string str = arguments.front();
    arguments.pop_front();
    variables[str] = stod(arguments.front(), nullptr);
}
