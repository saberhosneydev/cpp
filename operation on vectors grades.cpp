#include <iostream>
#include <vector>
using namespace std;

int findAverage(vector<int> arr){
int total = 0;
    for(auto x = 0; x < arr.size(); x++){
        total += arr.at(x);
    }
    return total/arr.size();
}
int studentsHigherThanAverage(vector<int> arr, int avg){
int totalStudents = 0;
    for(auto x = 0; x < arr.size(); x++){
        if(arr.at(x) >= avg){
            totalStudents++;
        }
    }
    return totalStudents;
}
int findBestMark(vector<int> arr){
int best = arr.at(0);
    for(auto x = 1; x < arr.size(); x++){
        if(arr.at(x) > best){
            best = arr.at(x);
        }
    }
    return best;
}
int main(){
    vector<int> grades;
    grades.push_back(75);
    grades.push_back(80);
    grades.push_back(85);
    grades.push_back(70);
    int avgMark = findAverage(grades);
    cout << "Average Mark is: " << avgMark << endl;
    cout << "No. of students with mark higher than avg: " << studentsHigherThanAverage(grades, avgMark) << endl;
    cout << "Best student mark was: " << findBestMark(grades) << endl;
    return 0;
}
