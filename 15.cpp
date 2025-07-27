#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14;
double yuan(double R, double r){
    return pi * (R * R - r * r);
} 
int main() {
    double R, r,r1,R1,ch;
    cin>>ch;
    for (int i=0;i<ch;i++){
        cin>>R1>>r1;
        
        if (R1<r1){
            R=r1;
            r=R1;
        } else{
            R=R1;
            r=r1;
        }
        cout<<yuan(R,r)<<endl;
    
    }
    return 0;
}