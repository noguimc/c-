#include <bits/stdc++.h>
int main(){
    int h,m,s;
    cin>>h>>m>>s;
    int lh,lm,ls;
    cin>>lh>>lm>>ls;
    h=h+lh;
    m=m+lm;
    s=s+ls;
    if (h>48){
        h=h-48;
    }else if (h>24&&h<48){
        h=h-24;

    }if (m>120){
        m=m-120;

    }if (m>60&&m<120){
        m=m-60;

    }
    if (s>120){
        s=s-120;

    }if (s>60&&s<120){
        s=s-60;
        
    }
    cout<<h<<m<<s;
    return 0;
}