#include <iostream>
#include <functional>

// functional programming using lambda expression

using namespace std;

template<int aValue, int bValue>
class ABC{
    private:
        int a = aValue, b = bValue;
    public:
        int getSum(void){
            return [this](){
                return (this->a + this->b);
            }();
        }
};

void classDemo(void){
    ABC<100, 200> abc;
    cout << "abc.getSum() : " << abc.getSum() << endl;
}

void lambdaDemo(void){
    // f(x, y) = x2 + y2 + 2xy

    int x = 5, y = 3;
    function<int (void)> fxsquare = [&]() -> int {
        x++;
        int xsquare = [=]() -> int { return (x*x); }();
        int ysquare = [=]() -> int { return (y*y); }();
        int twoxy   = [=]() -> int { return (2*x*y); }();
        return (xsquare + ysquare + twoxy);
    };
    cout << "fxsquare() : " << fxsquare() << endl;     

    // int x = 5, y = 3;
    // function<int (void)> fxsquare = [x, y]() -> int {
    //     int xsquare = [](int a) -> int { return (a*a); }(x);
    //     int ysquare = [](int b) -> int { return (b*b); }(y);
    //     int twoxy   = [](int a, int b) -> int { return (2*a*b); }(x, y);
    //     return (xsquare + ysquare + twoxy);
    // };
    // cout << "fxsquare: " << fxsquare() << endl;       

    // int somevar = 0;
    // function<int (int, int)> fxsquare = [somevar](int x, int y) -> int {
    //     // cout<<"somevar: " << somevar << endl;   //its a read-only variable 
    //     int xsquare = [](int a) -> int { return (a*a); }(x);
    //     int ysquare = [](int b) -> int { return (b*b); }(y);
    //     int twoxy   = [](int a, int b) -> int { return (2*a*b); }(x, y);
    //     return (xsquare + ysquare + twoxy);
    // };
    // cout << "fxsquare: " << fxsquare(5, 3) << endl;
        
}

int main(void){
    //lambda - basic syntax
    [](){
        cout << "it's a lambda function" << endl;
    }();

    //lambda - return type & argument 
    int retvalue = [](int baseValue) -> int {
        return (baseValue + 100);
    }(100);
    cout << "ret value: " << retvalue << endl;

    //lambda - function pointer
    // function<int (int)> fxsquare = [](int x) -> int {
    //     return (x*x);
    // };
    // cout << "fxsquare: " << fxsquare(10) << endl;

    lambdaDemo();
    classDemo();
}