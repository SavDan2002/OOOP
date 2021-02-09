#include "Calculator.h"

std::list<std::string> getString(std::string &str) {
    std::string word;
    std::list<std::string> result;
    for (auto i : str) {
        if (i != ' ' && i != '#' && i != '\t') {
            word += i;
        } else if (word.size() != 0) {
            result.push_back(word);
            word.clear();
        }
        if (i == '#') {
            break;
        }
    }
    if (word.size() != 0) {
        result.push_back(word);
    }
    return result;
}

Calculator::Calculator() : fin(nullptr), fout(nullptr) {}

Calculator::Calculator(const std::string &in, const std::string &out) {
    fin = new std::ifstream(in);
    fout = new std::ofstream(out);
}

void Calculator::calculate() {
    std::istream *in;
    if (fin == nullptr) {
        in = &std::cin;
    } else {
        in = fin;
    }
    while (!in->eof()) {
        std::string str;
        getline(*in, str);
        std::list<std::string> arguments = getString(str);
        if (arguments.size() == 0) {
            continue;
        }
        OperationFactory &factory = OperationFactory::getInstance();
        try {
            IOperationMaker &operatorMaker = factory.getOperatorMaker(arguments.front());
            std::unique_ptr<IOperation> operation(operatorMaker.create());
            arguments.pop_front();
            operation->calculate(arguments, stack, variables, fout);
        }
        catch (std::logic_error &ex) {
            std::cerr << "Error: " << ex.what() << std::endl;
            throw;
        }
    }
}

Calculator::~Calculator() {
    if (fin != nullptr && fout != nullptr) {
        fin->close();
        fout->close();
        delete fin;
        delete fout;
    }
}
