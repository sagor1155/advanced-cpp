/*
weak_ptr in c++:
------------------
NOTES:
0. If we say unique_ptr is for unique ownership and shared_ptr is for shared ownership then
   weak_ptr is for non-ownership smart pointer.
1. It actually reference to an object which is managed by shared_ptr.
2. A weak_ptr is created as a copy of shared_ptr.
3. We have to convert weak_ptr to shared_ptr in order to use or, dereference the managed object.
4. It is used to remove cyclic dependency between shared_ptr.
*/

#include <iostream>
#include <memory>
#include <thread>

using namespace std;

/* Remove cyclic dependency between shared_ptr */
struct Son;
struct Daughter;

struct Mother{
    Mother(){
    }
    ~Mother(){
        cout << "Mother gone" << endl;
    }
    void setSon(const std::weak_ptr<Son> s){
        mySon = s.lock();
    }
    void setDaughter(const std::shared_ptr<Daughter> d){
        myDaughter = d;
    }

    std::shared_ptr<Son> mySon;
    std::weak_ptr<Daughter> myDaughter;
};

struct Son{
    Son(std::shared_ptr<Mother> m):myMother(m){
    }
    ~Son(){
        cout << "Son gone" << endl;
    }

    std::shared_ptr<Mother> myMother;
};

struct Daughter{
    Daughter(std::shared_ptr<Mother> m):myMother(m){
    }
    ~Daughter(){
        cout << "Daughter gone" << endl;
    }

    std::shared_ptr<Mother> myMother;
};

int main(){
    std::shared_ptr<Mother> mother(new Mother);
    std::shared_ptr<Son> son(new Son(mother));
    std::shared_ptr<Daughter> daughter(new Daughter(mother));

    mother->setSon(son);
    mother->setDaughter(daughter);
}


/* Basic Example */
// int main(){
//     cout << "weak pointer example" << endl;
//     auto sharedPtr = std::make_shared<int>(100);
//     std::weak_ptr<int> weakPtr(sharedPtr);          //weakPtr is referencing sharedPtr

//     cout << "weakPtr.use_count(): " << weakPtr.use_count() <<endl;
//     cout << "sharedPtr.use_count(): " << sharedPtr.use_count() <<endl;
//     cout << "weakPtr.expired(): " << weakPtr.expired() <<endl;
    
//     if(std::shared_ptr<int> sharedPtr1 = weakPtr.lock()){
//         cout << "*sharedPtr1: " << *sharedPtr1 << endl;
//         cout << "sharedPtr1.use_count(): " << sharedPtr1.use_count() <<endl;
//         cout << "weakPtr.use_count(): " << weakPtr.use_count() <<endl;
//     }else{
//         cout << "Don't get the resource" << endl;
//     }

//     weakPtr.reset();    //after reset weakPtr won't point to the sharedPtr, it will be expired  
//     if(std::shared_ptr<int> sharedPtr2 = weakPtr.lock()){
//         cout << "*sharedPtr2: " << *sharedPtr2 << endl;
//         cout << "sharedPtr2.use_count(): " << sharedPtr2.use_count() <<endl;
//         cout << "weakPtr.use_count(): " << weakPtr.use_count() <<endl;
//     }else{
//         cout << "Don't get the resource" << endl;
//         cout << "weakPtr.expired(): " << weakPtr.expired() <<endl;
//     }

//     return 0;
// }