#include <iostream>
using namespace std;

int digitSum(int year) {
    int sum = 0;
    while (year > 0) {
        sum += year % 10; 
        year /= 10;       
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    int year = n + 1;
    while (true) {
        if (digitSum(year) == 20) {
            cout<<year<<endl;
            break;
        }
        year++;
    }
    return 0;
}