#include <iostream>
#include <vector>
#include <ios>
#include <limits>
#include <sstream>

using namespace std;

int main()
{

    vector<int> arr;
    int value;
    string exitLoop;
    bool x;
    while (1)
    {
        while (!(cin >> value))
        {
            stringstream ss;
            ss << value;
            ss >> exitLoop;
            if (exitLoop=="exit")
            {
                x = false;
                break;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.  Try again: ";
        }
        if(x == false){
            break;
        }
        arr.push_back(value);
    }

    for (int loop = 0; loop < arr.size(); loop++)
    {

    }
    return 0;
}
