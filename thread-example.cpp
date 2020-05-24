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

void threadFunction(int x){
    while(x-- > 0){
        cout << x << endl;
    }
}

class Base{
    public:
        static void run(int x){
            while(x-- > 0){
                cout << x << endl;
            }
        }

};

int main(){
    ull start = 0, end=100000, end2 = 1900000000;
    auto startTime = high_resolution_clock::now();

    // 1. create thread using function pointer 
    // thread t1(findEven, start, end);
    // thread t2(findOdd, start, end);

    // 2. create thread using lambda function    
    // thread t1([](int x){
    //     while(x-- > 0){
    //         cout << x << endl;
    //     }
    // }, 10);

    // 3. create thread using member function 
    Base b;
    // thread t1(&Base::run, &b, 10);  //for non-static member u need to pass object 
    thread t1(&Base::run, 10);  //for static member u don't need to pass object


    t1.join();
    // t2.join();

    // findEven(start, end);
    // findOdd(start, end);
    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(endTime-startTime);
    cout << "duration: " << duration.count()/1000000 << " sec" << endl;
    
}
