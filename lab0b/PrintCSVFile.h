#ifndef LAB0B_PRINTCSVFILE_H
#define LAB0B_PRINTCSVFILE_H
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iterator>

class PrintCSVFile {
private:
    int _wordsCounter;
    std::map <std::string, int> _wordsMap;
    std::multimap <int, std::string, std::greater<int>> _wordsMultimap;
public:
    void readInput (const std::string& inputName);
    void createMultimap ();
    void printCSVFile (std::string outputName);
};

#endif //LAB0B_PRINTCSVFILE_H
