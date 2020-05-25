
/* RACE CONDITION:
1. Race condition is situation where multiple threads/process happend to change a common data at the same time 
2. If there is race condition then we have to protect it and the protected section is called critical section/region

lets say, global_var x=1,
thread t1 & t2 wants to modify x at the same time. [x++]
variable is incremented in 3 steps: 1.load | 2.increment | 3.store
if t1 & t2 reads(loads) the variable x simultaneously then they will end up writing(storing) same value(2) 
of x. thats how race condition arises. 
*/

/* MUTEX:
1. Mutual Exclusion 
2. used to avoid race condition
3. we use lock() & unlock() on mutex to avoid race condition
*/

/*std::try_lock
1. syntax: std::try_lock(m1, m2, m3,.....mn)
2. on success returns -1 otherwise it will return 0-based mutex index which it could not lock 
3. if fails to lock any mutex then it releases all the mutex it locked before  
4. if call to try_lock results in an exception, unlocked in called for any locked objects before rethrowing  
*/


#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

using namespace std;
using namespace std::chrono;


/* std::try_lock */
std::mutex m1, m2;
int X=0, Y=0;

void doSomeWorkForSeconds(void){
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void incrementXY(int& XorY, std::mutex& m, const char* desc){
    for(int i=0; i<5; i++){
        m.lock();
        XorY++;
        cout << desc << XorY << endl;
        m.unlock();
        doSomeWorkForSeconds();
    }
}

void consumeXY(void){
    int useCount = 5;
    int sum = 0;

    while(1){
        int lockResult = std::try_lock(m1, m2);
        if(lockResult == -1){
            if(X!=0 && Y!=0){
                --useCount;
                sum += (X+Y);
                X=0; Y=0;
                cout << "sum: " << sum << endl;
            }
            m1.unlock();
            m2.unlock();
            if(useCount==0) break;
        }

    }
}

int main(void){

    thread t1(incrementXY, std::ref(X), std::ref(m1), "X: ");
    thread t2(incrementXY, std::ref(Y), std::ref(m2), "Y: ");
    thread t3(consumeXY);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}

/* Mutex::lock & Mutex::try_lock */
/*
std::mutex mtx;
uint32_t money = 0;

void addMoney(void){
    // mtx.lock(); //blocking 
    // money++;
    // mtx.unlock();

    for(int i=0; i<100000; i++){
        // if(mtx.try_lock())    //non-blocking 
        mtx.lock();     //blocking 
        {
            money++;
            mtx.unlock();
        }
    }
}

int main(){
    thread t1(addMoney);
    thread t2(addMoney);

    t1.join();
    t2.join();

    cout << "my money: " << money << endl;
    return 0;
}
*/