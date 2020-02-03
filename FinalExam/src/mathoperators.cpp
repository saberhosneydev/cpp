#include <iostream>
#include <math.h>
using namespace std;

int main(){
    cout << "Enter a number : ";
    int N;
    cin >> N;
    cout << "N after adding " << (N+=2) << endl;
    cout << "N after subtract " << (N -= 2) << endl;
    cout << "N after dividing " << (N /= 2) << endl;
    cout << "N after multiplying " << (N *= 2) << endl;
    cout << "N after mod " << (N%=2) << endl;

    return 0;
}
