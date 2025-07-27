#include <bits/stdc++.h>
using namespace std;
bool compare(int a, int b){
   
    if (a % 3 != b % 3){
        
        return a % 3 < b % 3;
    }
        
        return a<b;
        
    
}

int main(){
    int arr[9]={2,5,3,4,1,9,7,8,6};
    sort(arr,arr+9,compare);
    for (int i = 0; i < 9; i++)
    {
        cout<<arr[i]<<endl;
    }
    
}