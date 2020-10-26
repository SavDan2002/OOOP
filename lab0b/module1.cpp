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
    //char buffer[50];
    //char *buffer;
    std::string buffer;
    while (!fin.eof()) {
        //fin.getline (buffer, 50, "\0");
        getline (fin, buffer);
        std::string word;
        //fin.seekg(fin.peek()+50);
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
    //std::multimap<int, std::string, std::greater <int> > _wordsMultimap;
    //std::multimap<int, std::string> :: iterator multimapIterator = _wordsMultimap.begin();

    std::ofstream fout(outputName);
    if (!fout.is_open()) {
        throw "The file cannot be opened or created";
    }
    std::list <std::string> theSameWords;
    int tempKey, counter;
    std::string tempValue;
    //-----------------------------
    while (multimapIterator != _wordsMultimap.end()) {
        counter = 1;
        fout << multimapIterator->first << ", " << multimapIterator->second << "\n";
        multimapIterator++;
    }
    fout << "----------------------\n";
    multimapIterator = _wordsMultimap.begin();
    //-----------------------------

    while (multimapIterator != _wordsMultimap.end()) {
        tempKey = multimapIterator->first;
        tempValue = multimapIterator->second;
        multimapIterator++;
        counter = 1;
        while (tempKey == multimapIterator->first) {
            theSameWords.push_front(tempValue);
            tempValue = multimapIterator->second;
            multimapIterator++;
            counter++;
        }
        theSameWords.push_front(tempValue);

        theSameWords.sort();
        //advance(multimapIterator, -counter);
        for (int i = 0; i < counter; ++i) {
            fout << theSameWords.front() << ", " << tempKey << ", "
                 << (int)((double)tempKey/(double)_wordsCounter*100) << "%\n";
            theSameWords.pop_front();
        }
    }
}
