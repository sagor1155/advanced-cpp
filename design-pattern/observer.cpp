/*

*/

#include <iostream>
#include <vector>
#include <list>

using namespace std;

class observer{
    public:
    virtual void update() = 0;
};

class observerOne : public observer
{
    public:
    void update(){ cout << "Observer One Gets Notification" << endl; }
};

class observerTwo : public observer
{
    public:
    void update(){ cout << "Observer Two Gets Notification" << endl; }
};

class observerThree : public observer
{
    public:
    void update(){ cout << "Observer Three Gets Notification" << endl; }
};

class subject {
    private:
    std::list<observer *> observers;

    public:
    subject(){}
    ~subject(){}

    void subscribe(observer *obs){
        observers.push_back(obs);
    }

    void unsubscribe(observer *obs){
        observers.remove(obs);
    }

    void notify(){
        for(auto obs: observers){
            obs->update();
        }
    }
};

int main(){
    observerOne obs1;
    observerTwo obs2;
    observerThree obs3;

    subject *sub = new subject();
    sub->subscribe(&obs1);
    sub->subscribe(&obs2);
    sub->subscribe(&obs3);

    sub->unsubscribe(&obs2);
    sub->notify();
}