#include "WordCounter.h"
#include "Singleton.h"
#include "stdlib.h"
#include <iostream>
#include "fstream"
#include <vector>
#include <sstream>
#include <pthread.h>


WordCounter::WordCounter(std::string search_word){
    this->search_word = search_word;
}
// std::string getSearchWord();
// int getWordCount();
// void setSearchWord(std::string search_word);
// void setWordCount(int wordCount);
void WordCounter::writeFile(void* arg){
    pthread_mutex_lock(&(Singleton::getInstance()->getWriterLock()));
    std::ofstream myFile;
    myFile.open("test.txt", std::ios::out);
    for(int i = 0; i < 500; i++){
        myFile << getRandChar();
    }
    myFile.close();
    pthread_mutex_unlock(&(Singleton::getInstance()->getWriterLock()));
}

int readAndCount(void* arg){

}

char WordCounter::getRandChar(){
    return 'a' + rand() % 26;
}