#include "module1.h"

int main(int argc, char** argv) {
    PrintCSVFile CSVFile;
    try {
        //CSVFile._readInput (argv[1]);
        CSVFile._readInput ("input.txt");
        CSVFile._createMultimap ();
        CSVFile._printCSVFile ("output.csv");
    }
    catch (char* exception) {
        std::cout << exception << std::endl;
    }
    return 0;
}
