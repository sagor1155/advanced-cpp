
/*
TOPIC: unique_lock In C++

NOTES:
1. The class unique_lock is a mutex ownership wrapper.
2. It Allows:
    a. Can Have Different Locking Strategies
    b. time-constrained attempts at locking (try_lock_for, try_lock_until)
    c. recursive locking
    d. transfer of lock ownership (move not copy)
    e. condition variables. 

Locking Strategies
    TYPE                     EFFECTS(S)
1. defer_lock       do not acquire ownership of the mutex.
2. try_to_lock      try to acquire ownership of the mutex without blocking.
3. adopt_lock       assume the calling thread already has ownership of the mutex.
*/


#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

using namespace std;
using namespace std::chrono;

std::mutex m1;
int somevar = 0;

//Example-1: unique_lock 
void task(int loopCount, const char* threadNo){
    std::unique_lock<mutex> lock(m1);           //Automatically calls lock on mutex m1
    for (size_t i = 0; i < loopCount; i++){
        somevar++;
        cout << "thread: " << threadNo << " somevar: " << somevar << endl;
    }
    //lock.unlock() not needed as it will be invoked from the destructor of unique_lock 
}

//Example-2: defer_lock
void task2(int loopCount, const char* threadNo){
    std::unique_lock<mutex> lock(m1, std::defer_lock);  //doesn't call lock on mutex m1
    lock.lock();            //need to call lock explicitly 
    for (size_t i = 0; i < loopCount; i++){
        somevar++;
        cout << "thread: " << threadNo << " somevar: " << somevar << endl;
    }
    //lock.unlock() not needed as it will be invoked from the destructor of unique_lock 
}

int main(){
    thread t1(task2, 5, "1");
    thread t2(task2, 5, "2");

    t1.join();
    t2.join();

    return 0;
}
