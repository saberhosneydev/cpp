#include <iostream>
using namespace std;

int main(){
    int g;
    cout << "Enter a number please ." << endl;
    cin >> g;
    if (g%2 == 0){
        cout << g << " is even";
    }else {
        cout << g << " is odd";
    }
}
