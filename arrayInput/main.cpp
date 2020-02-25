#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int size, value;
    cout << "Please enter max array size" << endl;
    cin >> size;
    cout << "Your array MAX will be " << size << "Enter this amount of indexes next" << endl;
    int arr[size];
    for(int loop = 0; loop < size; loop++){
        cin >> value;
        arr[loop] = value;
    }

    for(int loop = 0; loop < size; loop++){
        if(loop == 0){
            cout << "You entered this array : ";
        }
        cout << arr[loop] << ", ";
    }
    system("pause");
    return 0;
}
