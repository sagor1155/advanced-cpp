#include <iostream>
#include <functional>

using namespace std;

int main(void){
    // basic syntax
    [](){
        cout << "it's a lambda function" << endl;
    }();

    // return type & argument 
    int retvalue = [](int baseValue) -> int {
        return (baseValue + 100);
    }(100);
    cout << "ret value: " << retvalue << endl;

    // function pointer
    std::function<int (int)> fxsquare = [](int x) -> int {
        return (x*x);
    };
    cout << "fxsquare: " << fxsquare(10) << endl;
}