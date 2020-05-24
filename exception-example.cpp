#include <iostream>
#include <string>
#include <exception>
#include <vector>

using namespace std;

class derivedException: public exception{
    virtual const char* what() const throw(){   // throw() is equivalent to noexcept(true) specifier [means doesn't throw any exception]
        return "my derived exception";
    }
}myDerivedException;

class throwexception {
public:
    throwexception(){ //Constructor
        cout << "constructor called" << endl;
    }

    // ~throwexception() noexcept(false) {  //Destructor
    //     cout << "destructor called" << endl;
    //     throw 9;
    // }

    ~throwexception() {  //Destructor
        cout << "destructor called" << endl;
    }
};

void updateVector(vector<string>& firstvector_, vector<string>& secondvector_, string newString) {
    firstvector_.push_back(newString);
    try {
        secondvector_.push_back(newString);
    }
    catch (...) {
        firstvector_.pop_back();
        cout << "second vector update failed." << endl;
    }
}

void updateVector2(vector<string>& firstvector_, vector<string>& secondvector_, string newString) {
    firstvector_.push_back(newString);
    try {
        bad_alloc excep;
        throw excep;
        secondvector_.push_back(newString);
    }
    catch (...) {
        firstvector_.pop_back();
        cout << "second vector update failed." << endl;
    }
}

int main() {

    /* derived exception example */
    try{
        throw myDerivedException;
    }
    catch(const exception& e){
        cerr << e.what() << endl;
    }
    
    /* different thrown exception type & nested handler */
    try{
        throw 10.5;
    }
    catch(int e){
        cerr << "int exception: " << to_string(e) << endl;
    }
    catch(double e){
        cerr << "double exception: " << to_string(e) << endl;
    }
    catch(...){
        cerr << "any other exception" << endl;
    }

    try{
        try{
            throw 20;
        }
        catch(int e){
            cerr << "int exception: " << to_string(e) << endl;
            throw;  // exception thrown to parent block 
        }
    }
    catch(...){
        cout << "exception caught by parent block" << endl;
    }


    /* uncaught exception */
    try
    {
        throwexception texc;
        cout << "Throwing exception will cause termination of program." << endl;
        throw 7;
    }
    catch(...)
    {
        cout << "Main Exception caught"<< endl;
    }
    

    /*  */
    std::vector<std::string> firstvector;
    std::vector<std::string> secondvector;
    std::string mystring("Hello world!");

    cout << "Calling updateVector " << endl;
    updateVector(firstvector, secondvector, mystring);
    cout << "first vector size is " << firstvector.size() << " second vector size is " << secondvector.size() << endl;
    cout << "Calling updateVector2 " << endl;
    updateVector2(firstvector, secondvector, mystring);
    cout << "first vector size is " << firstvector.size() << " second vector size is " << secondvector.size() << endl;
    
    return 0;
}
