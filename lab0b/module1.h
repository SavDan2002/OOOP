#ifndef LAB0B_MODULE1_H
#define LAB0B_MODULE1_H
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iterator>
#include <list>

class PrintCSVFile {
private:
    int _wordsCounter;
    std::map <std::string, int> _wordsMap;
    std::multimap <int, std::string, std::greater<int>> _wordsMultimap;
public:
    //bool _isLetterOrNumber (char symbol);
    void _readInput (const std::string& inputName);
    void _createMultimap ();
    void _printCSVFile (std::string outputName);
};


#endif //LAB0B_MODULE1_H
