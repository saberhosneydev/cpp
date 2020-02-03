#include <iostream>

using namespace std;

class myClass {
public:
    int who;
    myClass(int id);
    ~myClass();
}
global_obj1(1), global_obj2(2);

myClass::myClass(int id){
    cout << "Initializing" << id << endl;
    who = id;
}

myClass::~myClass(){
    cout << "Destructing" << who << endl;
}
int main(){
myClass local_obj1(3);
cout << "SPACER" << endl;
myClass local_obj2(4);

return 0;
}
