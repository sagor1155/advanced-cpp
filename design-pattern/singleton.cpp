/*
Singleton pattern:
This type of design pattern comes under creational pattern as this pattern provides one of the best ways to create an object.
This pattern involves a single class which is responsible to create an object while making sure that only single object gets created. 
This class provides a way to access its only object which can be accessed directly without need to instantiate the object of the class.

steps must be done: 
1. make the constructor private 
2. make a private static instance 
3. provide a public static get instance method 
4. initialize the instance 
*/

#include <iostream>

using namespace std;


class SingletonClass{
    private:
        static  SingletonClass* instance;

        // Private constructor so that no objects can be created.
        SingletonClass(){
        }

    public:
        static SingletonClass* getInstance(){
            if(instance==nullptr){
                instance = new SingletonClass();
            }
            return instance;
        }

        void printsomething(){
            cout << "singleton pattern demo" << endl;
        }

};

//Initialize pointer to zero so that it can be initialized in first call to getInstance
SingletonClass *SingletonClass::instance = nullptr;

int main(){
    SingletonClass* obj = SingletonClass::getInstance();
    obj->printsomething();
}