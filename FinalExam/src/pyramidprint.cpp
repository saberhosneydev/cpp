#include <iostream>
using namespace std;

int main(){

int x,y,z,rowN;
cin >> rowN;
for(x=1; x <= rowN; x++){
    for(y=(rowN - 1); y >= x; y--){
        cout << " ";
    }
    for(z = 1; z <= (2*x-1); z++){
        cout << "*";
    }
    cout << endl;
}
return 0;
}
