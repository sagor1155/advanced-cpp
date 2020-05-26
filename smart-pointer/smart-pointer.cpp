
/*
smart pointers in c++: 
It is basically a wrapper which wraps raw pointer and handles the life time of the object for you, 
means if there is no reference to the pointer it will delete it otherwise it will hold. There are basically three types of smart pointers. 
TYPES:
1. unique_ptr
2. shared_ptr
3. weak_ptr
And the basic job of smart pointer is, it actually makes sure that we don't have memory leaks. 
*/

#include <iostream>

using namespace std;

class MyInt {
    public:
        explicit MyInt(int* p=nullptr){ 
            data=p; 
        }
        ~MyInt(){
            cout << "destructor called. deleting pointer." << endl;
            delete data;
        }
        int& operator *(){
            return *data;
        }
    private:
        int* data;

};

int main(){
    cout << "smart pointer example" << endl;  
    int* p = new int(10);
    MyInt myint = MyInt(p);
    *myint = 200;
    cout << *myint << endl;   
    return 0;
}