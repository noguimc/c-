#include <bits/stdc++.h>
using namespace std;
int main(){
	string a;
	string b;
	getline(cin,a);
	getline(cin,b);
	for (int i;i<a.size();i++){
		if (islower(a[i])){
			a[i]=toupper(a[i]);
		}
	}
	for (int i;i<b.size();i++){
		if (islower(b[i])){
			b[i]=toupper(b[i]);
		}
	}
	if (a>b){
		cout<<">";
	}else if(a==b){
		cout<<"=";
		
	}else if(a<b){
		cout<<"<";
	}
	return 0;
}
