#include <iostream>
#include <fstream>
#include "WordCounter.h"

class Singleton{
    private:
        static Singleton* instance;
        WordCounter* wordCounterInstance;
        pthread_mutex_t writer_lock;
        pthread_t threads[6];
        std::ifstream context[5];
        Singleton(){
            wordCounterInstance = new WordCounter("luke");
        }
    public:
        void run(){
            int returnCode = pthread_create(&threads[6], NULL, wordCounterInstance->writeFile, &context[0]);
            if(returnCode){
                std::cout << "Thread Issue, something went wrong creating the thread" << std::endl;
            }
        }

        pthread_mutex_t getWriterLock(){
            return writer_lock;
        }

        static Singleton* getInstance(){
            if(!(instance)){
                instance = new Singleton;
            }
            return instance;
        }
};