
/*
Abstract factory design pattern defines an abstract class for creating families of related objects
but without specifying their concrete sub-class. 

Abstract Factory patterns work around a super-factory which creates other factories. This factory is also 
called as factory of factories. This type of design pattern comes under creational pattern as this pattern 
provides one of the best ways to create an object.

In Abstract Factory pattern an interface is responsible for creating a factory of related objects without 
explicitly specifying their classes. Each generated factory can give the objects as per the Factory pattern.
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

class RoundedRectangle : public Shape
{
public:    
    void draw(void){
        cout << "drawing Roundedrectangle" << endl;
    }
};

class RoundedCircle : public Shape
{
public:    
    void draw(void){
        cout << "drawing Roundedcircle" << endl;
    }
};

class AbstractFactory{
public:
    virtual Shape* getShapeObject(string str) = 0;
};

class ShapeFactory : public AbstractFactory
{
public:
    Shape* getShapeObject(string str){
        if(str.compare("r")==0){
            return new Rectangle();
        }else if(str.compare("c")==0){
            return new Circle();
        }
    }
};

class RoundedShapeFactory : public AbstractFactory
{
public:
    Shape* getShapeObject(string str){
        if(str.compare("r")==0){
            return new RoundedRectangle();
        }else if(str.compare("c")==0){
            return new RoundedCircle();
        }
    }
};

class FactoryProducer{
public:
    static AbstractFactory* getfactory(bool round){
        if(round){
            return new RoundedShapeFactory();
        }else{
            return new ShapeFactory();
        }
    }
};

int main(){
    cout << "Abstract Factory Design Pattern" << endl;
    Shape* sp;
    AbstractFactory* factory = FactoryProducer::getfactory(true);
    sp = factory->getShapeObject("r");    
    sp->draw();

    factory = FactoryProducer::getfactory(false);
    sp = factory->getShapeObject("c");    
    sp->draw();
}