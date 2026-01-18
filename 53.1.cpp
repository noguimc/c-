#include <bits/stdc++.h>
using namespace std;
int main(){
    int train[5]={0,10,20,30,40};
    int next[5]={-1,-1,-1,-1,-1};
    int head;
    cin>>head;
    int now =head;
    for(int i=1;i<=3;i++){
        int next_v;
        cin>>next_v;
        next[now]=next_v;
        now =next_v;
    }
    now =head;
    while(now!=-1){
        cout << now <<train[now]<<" ";
        now =next[now];
    }



    return 0;
}