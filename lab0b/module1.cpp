#include "module1.h"

bool isLetterOrNumber (char symbol){
    if (symbol >= 'A' && symbol <= 'Z' ||
        symbol >= 'a' && symbol <= 'z' ||
        symbol >= '0' && symbol <= '9'){
        return true;
    }
    else {
        return false;
    }
}

void PrintCSVFile::_readInput (const std::string& inputName){
    std::ifstream fin(inputName);
    if (!fin.is_open()) {
        throw "The file cannot be opened or created";
    }
    std::string buffer;
    while (!fin.eof()) {
        getline (fin, buffer);
        std::string word;
        for (char i : buffer){
            if (isLetterOrNumber(i) && i != '\0'){  // && !buffer.eof();
                word += i;
                continue;
            }
            else if (word.length() > 0 && i != '\0') {
                _wordsMap[word]++;
                word.clear();
                ++_wordsCounter;
            }
        }
    }
    fin.close();
}

void PrintCSVFile::_createMultimap (){
    std::map <std::string, int> :: iterator mapIterator = _wordsMap.begin();
    for (int i = 0; i < _wordsMap.size(); ++mapIterator, ++i) {
        _wordsMultimap.insert(make_pair(mapIterator->second, mapIterator->first));
    }
    _wordsMap.clear();
}

void PrintCSVFile::_printCSVFile (std::string outputName){
    std::multimap <int, std::string> :: iterator multimapIterator = _wordsMultimap.begin();
    std::ofstream fout(outputName);
    if (!fout.is_open()) {
        throw "The file cannot be opened or created";
    }
    while (multimapIterator != _wordsMultimap.end()) {
        fout << multimapIterator->second << ", " << multimapIterator->first << ", "
        << (int)((double)multimapIterator->first/(double)_wordsCounter*100) << "%\n";
        multimapIterator++;
    }
    _wordsMultimap.clear();
}
