#include "PrintCSVFile.h"

int main(int argc, char** argv) {
    PrintCSVFile CSVFile;
    if (argc != 3){
        std::cout << "bad input" << std::endl;
        return 0;
    }
    try {
        CSVFile.readInput(argv[1]);
        //CSVFile.readInput ("input.txt");
        CSVFile.createMultimap();
        CSVFile.printCSVFile(argv[2]);
        //CSVFile.printCSVFile ("output.csv");
    }
    catch (std::logic_error &ex) {
        std::cerr << ex.what() << std::endl;
    }
    return 0;
}
