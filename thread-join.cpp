/* JOIN:
1. waits for the thread to be finished 
2. double joining will result in termination of the program 
3. always check joinable before join
*/

/* DETACH:
1. this is used to detach newly created thread from the parent thread
2. always check if the thread is joinable before detaching it 
3. if we haved detached thread and main function is returning then detached thread execution is supended
4. never waits for the thread to be finished 
*/

/* NOTES:
1. Either join() or, detach() should be called on object. otherwise during thread object's destructor it will terminate the program. 
because inside destructor it checks if thread is still joinable? if yes then it terminates the program.  
*/

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
using namespace std::chrono;

void run(int x){
    while (x --> 0){
        cout << "value is: " << x << endl;
    }
    std::this_thread::sleep_for(chrono::seconds(3));
    cout << "thread finished" << endl;
}


int main(){
    thread t1(run, 5);
    
    // std::this_thread::sleep_for(chrono::seconds(1));
    
    cout << "main()" << endl;

    if(t1.joinable()){
        t1.join();
    }

    // t1.detach();

    cout << "main() after" << endl;
    // std::this_thread::sleep_for(chrono::seconds(1));
    return 0;
}