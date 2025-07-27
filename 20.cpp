#include <iostream>
using namespace std;
int cnt[101],num[100010];
int main() {
    int n,index=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i];
        cnt[num[i]]++;
    }
    for(int i=0;i<101;i++){
        for(int j=0;j<cnt[i];j++){
            num[index]=i;
            index++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<num[i]<<endl;
    }

    return 0;
}