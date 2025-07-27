#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[1000], n = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int b=a[1]-a[0];
    for(int i=0;i<n-1;i++){
        if(a[i+1]-a[i]<b){
            b=a[i+1]-a[i];
        }
    }
    cout<< b;
    return 0;
}