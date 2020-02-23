#include <iostream>
#include <array>
// DEFINE MAX ARRAY INDEX
#define MAX 10
using namespace std;

void linear_search(int arr[], int value){
    int steps = 0;
    for(int loop = 0; loop < MAX; loop++){
        if(arr[loop] == value){
            cout << "The Value " << value <<  " was found on the index " << loop << " after "<< steps << " Steps";
            break;
        }else {
            steps++;
            if(loop == MAX){
            cout << "The value wasn't found in the given array after " << steps << " Steps";
            }
        }
    }
}

void binary_searchs(int arr[], int value){
    int steps = 0;
    int left = 0;
    int right = MAX;
    int mid = MAX/2;
    if(arr[mid] == value){
        cout << "Wow you got lucky , found from first try";
    }else {
        if(value > arr[mid]){
            left = mid;
            steps++;
        }else {
            right = mid;
            steps++;
        }
    }
    for(int loop = left; loop < right; loop++){
        if(arr[loop] == value){
            cout << "The Value " << value <<  " was found on the index " << loop << " after "<< steps << " Steps";
            break;
        }else {
            steps++;
            if(loop == MAX){
            cout << "The value wasn't found in the given array after " << steps << " Steps";
            }
        }
    }
}
int main()
{
    int xarr[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    binary_searchs(xarr , 5);
    return 0;
}
