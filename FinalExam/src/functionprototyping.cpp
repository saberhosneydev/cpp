#include<iostream>
using namespace std;

int square(int y){
    return y*y;
}
int main() {
    for(int x=1;x <=10;x++){
        cout << square(x) << " " << endl;
    }
return 0;
}
