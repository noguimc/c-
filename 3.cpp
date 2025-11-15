#include <bits/stdc++.h>
using namespace std;
int main(){
	int a, c = 0;
	cin >> a;
	int b = a;
	while(b != 0){
		b = b / 3;
		c += b;
	}
	c = a + c;
	cout << c;
	return 0;
}
