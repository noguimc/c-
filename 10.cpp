#include <bits/stdc++.h>
using namespace std;
int main(){
    // 定义一个整型数组a，并初始化
    int a[]={45,12,53,2,35};
    // 计算数组a的长度
    int b=sizeof(a)/4,n;
    // 外层循环，控制比较的轮数
    for (int w=0;w<b-1;w++){
        // 内层循环，控制每一轮比较的次数
        for (int i=0;i<b-1;i++){
            // 如果前一个元素大于后一个元素，则交换它们的位置
            if (a[i]>a[i+1]){
                n=a[i];
                a[i]=a[i+1];
                a[i+1]=n;
            }
        }
    }
    // 输出排序后的数组
    for (int i=0;i<b;i++){
        cout<<a[i]<<endl;
    }
    return 0;
}
