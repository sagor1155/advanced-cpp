
/* timed_mutex
1. timed mutex is blocked till timeout time or, the lock is acquired and returns true if success otherwire false 
2. member functions:
    a. lock
    b. unlock
    c. try_lock_for
    d. try_lock_untill 
    e. try_lock 
*/


#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

using namespace std;
using namespace std::chrono;


/* Mutex::lock & Mutex::try_lock */
std::timed_mutex mtx;
uint32_t money = 0;

void addMoney(int i){
    auto time_now = std::chrono::steady_clock::now();
    // if(mtx.try_lock_for(std::chrono::seconds(2))){
    if(mtx.try_lock_until(time_now + std::chrono::seconds(2))){
        money++;
        cout << "thread: " << i << " acquired lock" <<endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        mtx.unlock();
    }else{
        cout << "thread: " << i << " couldn't enter!!!" << endl;
    }
}

int main(){
    thread t1(addMoney, 1);
    thread t2(addMoney, 2);

    t1.join();
    t2.join();

    cout << "my money: " << money << endl;
    return 0;
}
