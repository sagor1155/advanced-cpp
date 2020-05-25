
/*
TOPIC: Condition Variable In C++ Threading

NOTES:
1. Condition variables allow us to synchronize threads via notifications.
   a. notify_one();
   b. notify_all();
2. You need mutex to use condition variable
3. Condition variable is used to synchronize two or more threads.
4. Best use case of condition variable is Producer/Consumer problem.
5. Condition variables can be used for two purposes:
    a. Notify other threads
    b. Wait for some condition
*/


#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;
using namespace std::chrono;

std::mutex m1;
std::condition_variable cv;
long balance = 0;

void addMoney(int money){
    // std::lock_guard<mutex> lg(m1);
    // balance += money;
    // cout << "Total balance now: " << balance << endl;
    // cv.notify_one();        //notify to that thread who is waiting on that condition variable 

    for(int i=0; i<5; i++){
        m1.lock();
        balance += money;
        cout << "Total balance now: " << balance << endl;
        m1.unlock();
        cv.notify_one();        //notify to that thread who is waiting on that condition variable 
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void withdrawMoney(int money){
    std::unique_lock<mutex> ul(m1);
    cv.wait(ul, [=](){ return ((balance!=0)?true:false);} );     
    /*
    if condition is false: cv.wait will release mutex and wait here. 
    if condition is  true: cv.wait will lock mutex and proceed to next statement   
    */
    if(balance >= money){
        balance -= money;
        cout << "Amount deducted: " << money << endl;
    }else{
        cout << "Don't have sufficient balance!" << endl;
    }
    
    cout << "Current balance: " << balance << endl;
}

int main(void){
    thread t1(withdrawMoney, 500);
    thread t2(addMoney, 100);

    t1.join();
    t2.join();

    return 0;
}