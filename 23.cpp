#include <iostream>
using namespace std;


int run(int a[5]) {
    for (int i = 1; i < 5; i++) {
        int b = a[i]; 
        int j = i - 1;

        
        while (j >= 0 && a[j] > b) {
            a[j + 1] = a[j];
            j--;
        }

        
        a[j + 1] = b;
    }
    return 0;
}

int main() {
    int a[5] = {45, 12, 53, 2, 35};

    run(a);

    for (int i = 0; i < 5; i++) {
        cout << a[i] << endl;
    }
    return 0;
}