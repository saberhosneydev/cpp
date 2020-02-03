#include <iostream>
using namespace std;

int maximum(int x, int y, int z){
    int max = x;
    if (y > max){
        max = y;
    }if (z > max){
        max = z;
    }
    return max;
}

int main(){
    int a,b,c;
    cout << "Enter three integers" << endl;
    cin >> a >> b >> c;
    cout << "Maximum number is : " << maximum(a,b,c);
    return 0;
}
