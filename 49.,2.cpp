#include <bits/stdc++.h>
using namespace std;
int main(){
    int ans=0;
    for(int i=0;i<1<<14;i++){
        int tot_1=0;
        int tot_0=0;
        int num=2;
        for(int j=0;j<14;++j){
            if(i&(1<<j)){
                tot_1++;
            }else{
                tot_0++;
                num=num-1;
            }


        }
        if(tot_1==5&&tot_0==9&&num==1){
            ++ans;
        }


    }
    return 0;
}