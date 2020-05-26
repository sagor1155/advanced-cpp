
/*
TOPIC: std::lock_guard In C++
 
NOTES:
0. It is very light weight wrapper for owning mutex on scoped basis.
1. It acquires mutex lock the moment you create the object of lock_guard.
2. It automatically removes the lock while goes out of scope.
3. You can not explicitly unlock the lock_guard.
4. You can not copy lock_guard
*/

#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

using namespace std;
using namespace std::chrono;

std::mutex m1;
int somevar = 0;

void task(int loopCount, const char* threadNo){
    std::lock_guard<mutex> lock(m1);
    for (size_t i = 0; i < loopCount; i++){
        somevar++;
        cout << "thread: " << threadNo << " somevar: " << somevar << endl;
    }
}

int main(){
    thread t1(task, 5, "1");
    thread t2(task, 5, "2");

    t1.join();
    t2.join();

    return 0;
}
