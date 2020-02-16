#include <iostream>
#include "picosha2.h"
#include <thread>
#include <vector>
#include <boost/log/trivial.hpp>
#define BOOST_LOG_DYN_LINK 1
#include <unistd.h>

using namespace boost;
using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::rand;


string hashHandler(int a) {
    while (true){
        int stringLenth=30;
        string stringForHash;
        for (int i=0; i<stringLenth;++i){
            stringForHash.push_back(rand()%255);
        }
        const std::string hash = picosha2::hash256_hex_string(stringForHash);
        if (hash.find("0000", 60)==60){
            cout<<"DONE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
            cout<<a<<" - "<<stringForHash.size()<<" - " <<hash<<endl;
            return hash;
        }
    }
}



class hashMaster{
public:

    hashMaster(){
        threadNumber=std::thread::hardware_concurrency();
        cout<<"Thread count - "<<threadNumber<<endl;
        setThreads();
    }

    explicit hashMaster(int number){
        threadNumber=number;
        setThreads();
    }



    void setThreads(){
        for(int i=0; i<threadNumber;i++){
            std::thread th(hashHandler,i);
            allThreads.push_back(std::move(th));
        }
        for(int i=0; i<threadNumber;i++){
            allThreads.at(i).join();
        }
    }



private:
    unsigned long threadNumber;
    short int zeroCount=4;
    vector<std::thread> allThreads;
};



int main() {
    hashMaster c(1);

//
   BOOST_LOG_TRIVIAL(info) << "An informational severity message";

    return 0;
}
