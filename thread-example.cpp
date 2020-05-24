#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
using namespace std::chrono;

typedef unsigned long long ull;

ull oddSum = 0;
ull evenSum = 0;

void findEven(ull start, ull end){
    for(ull i=start; i<end; i++){
        if((i%2) == 0){
            evenSum += i;
        }
    }
}

void findOdd(ull start, ull end){
    for(ull i=start; i<end; i++){
        if((i%2) != 0){
            oddSum += i;
        }
    }
}

int main(){
    ull start = 0, end = 1900000000;
    auto startTime = high_resolution_clock::now();

    //1. create thread using function pointer 
    thread t1(findEven, start, end);
    thread t2(findOdd, start, end);

    //2. create thread using lambda function    
    

    t1.join();
    t2.join();

    // findEven(start, end);
    // findOdd(start, end);
    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(endTime-startTime);
    cout << "duration: " << duration.count()/1000000 << endl;
    
}
