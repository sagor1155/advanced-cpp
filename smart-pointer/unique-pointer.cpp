
/*
unique_ptr in c++: 
------------------
NOTES:
0. unique_ptr is a class template.
1. unique_ptr is one of the smart pointer provided by c++11 to prevent memory leaks.
2. unique_ptr wraps a raw pointer in it, and de-allocates the raw pointer, when unique_ptr object goes out of scope. 
   It manages the life time of a dynamically created object. 
3. similar to actual pointers we can use arrow and * on the object of unique_ptr,  because it is overloaded in unique_ptr class.
4. When exception comes then also it will de-allocate the memory hence no memory leak.
5. Not only object we can create array of objects of unique_ptr.
6. OPERATION: get, release, reset, swap, get_deleter 
*/

#include <iostream>
#include <memory>

using namespace std;

class Foo {
    private: 
        int data;
    public:
        explicit Foo(int x) {data = x;}
        ~Foo()  { cout << "Foo destructor called" << endl; }
        int getData(void)   {return data;}
};

int main(){
    std::unique_ptr<Foo> p1(new Foo(20));               //way-1: not exception safe 
    std::unique_ptr<Foo> p6(new Foo(40));
    std::unique_ptr<Foo> p2 = make_unique<Foo>(30);     //way-2: exception safe, C++14 feature     
    cout << "data: " << p1->getData() << "  " << (*p1).getData() << endl;

    // p1 = p1; //FAIL: because u can't copy ownership 
    std::unique_ptr<Foo> p3 = std::move(p1);    //pointer ownership is moved to p3 from p1. now p1 indicates to nullptr.   

    Foo* p = p3.get();  //it just returns the managing pointer, here "new Foo(20)". 
    Foo* p4 = p3.release(); //it returns the managing pointer and becomes nullptr. 
    
    p2.reset(p4);    //managed object p2 will get replaced by p4 and the pointer managed by p2 will be deleted 
    cout << "p2 data: " << p2->getData() << endl;



    return 0;
}