#include <bits/stdc++.h>
using namespace std;
int main(){
	string a;
	cin>>a;
	if (a.find("53")!=string::npos){
		a.insert(a.find("53"),"xiaofeng");
	}
	cout<<a<<endl;
	return 0;
}
