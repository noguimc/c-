#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c=0;
    cin>>a>>b;

    for(int i=a;i<=b;i++){
        if(i%5==0){
            int temp = i; // 创建临时变量存储i的值，避免修改循环变量
            while(temp > 0){
                if(temp % 5 == 0){ // 修正判断条件，统计5的因子个数
                    temp = temp / 5;
                    c++;
                }else{
                    break;
                }
            }
        }
    }
    
    cout<<c;
    return 0;
}