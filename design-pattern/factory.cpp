
/*
In Factory pattern, we create object without exposing the creation logic 
to the client and refer to newly created object using a common interface.

*/

#include <iostream>
#include <string>

using namespace std;

//interface class 
class Shape{
public:
    virtual void draw(void) = 0;    //pure virtual function 
};

class Rectangle : public Shape
{
public:    
    void draw(void){
        cout << "drawing rectangle" << endl;
    }
};

class Circle : public Shape
{
public:    
    void draw(void){
        cout << "drawing circle" << endl;
    }
};

class ShapeFactory{
public:
    static Shape* getShapeObject(string str){
        if(str.compare("r")==0){
            return new Rectangle();
        }else if(str.compare("c")==0){
            return new Circle();
        }
    }
};

int main(){
    cout << "Factory Design Pattern" << endl;
    Shape* sp;
    // ShapeFactory* factoryObj = new ShapeFactory();
    sp =  ShapeFactory::getShapeObject("c");
    sp->draw();

}