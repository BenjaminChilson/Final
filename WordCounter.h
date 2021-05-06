#ifndef WORDCOUNTER_H
#define WORDCOUNTER_H
#include <string>

class WordCounter{
    private:
        std::string search_word;
        int word_count;
    public:
        WordCounter(std::string search_word);
        std::string getSearchWord();
        int getWordCount();
        void setSearchWord(std::string search_word);
        void setWordCount(int wordCount);
        void writeFile(void* arg);
        int readAndCount(void* arg);
        static char getRandChar();

};

#endif