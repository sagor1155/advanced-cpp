/*
shared_ptr in c++:
------------------
There are few points about it:
0. shared_ptr is a smart pointer which can share the ownership of object (managed object).
1. Several shared_ptr can point to the same object (managed object).
2. It keep a reference count to maintain how many shared_ptr are pointing to the same object.
   and once last shared_ptr goes out of scope then the managed object gets deleted.
3. shared_ptr is threads safe and not thread safe. [what is this??]
   a. control block is thread safe
   b. managed object is not
4. There are three ways shared_ptr will destroyed managed object.
   a. If the last shared_ptr goes out of scope.
   b. If you initialize shared_ptr with some other shared_ptr.
   c. If you reset shared_ptr.
5. Reference count doesn't work when we use reference or pointer of shared_ptr.
*/

#include <iostream>
#include <memory>
#include <thread>

using namespace std;

class Foo {
    private: 
        int data;
    public:
        explicit Foo(int x) {data = x;}
        ~Foo()  { cout << "Foo destructor called" << endl; }
        int getData(void)   {return data;}
};

void threadFunction(std::shared_ptr<Foo> sp, const char* tno){
    cout << "use count inside thread-" << tno << ": " << sp.use_count() << endl;
}

int main(){
    cout << "shared pointer example" << endl;

    // shared pointer in thread
    std::shared_ptr<Foo> sp(new Foo(100));
    cout << "use count inside main:  " << sp.use_count() << endl;
    thread t1(threadFunction, sp, "T1"), t2(threadFunction, sp, "T2"), t3(threadFunction, sp, "T3");
    t1.join(); t2.join(); t3.join(); 


    // std::shared_ptr<Foo> sp(new Foo(100));
    // cout << "data: " << sp->getData() << endl;
    // cout << "reference count: " << sp.use_count() << endl;

    // std::shared_ptr<Foo> sp1 = sp;  //it will increment use_count (copy by value not pointer or reference)
    // cout << "reference count: " << sp1.use_count() << endl;
    
    // std::shared_ptr<Foo> *sp2 = &sp;    //this won't increment use_count
    // cout << "reference count: " << sp2->use_count() << endl;


    // Foo* f = new Foo(20);
    // cout << f->getData() << endl;
    // delete f;
    
    return 0;
}