#include <bits/stdc++.h>
using namespace std;
int main() {
	int a[] = {1, 2, 3, 4, 5};
	int n = sizeof(a) / sizeof(a[0]); 
	
	int b = a[0];
	for (int i = 0; i < n - 1; i++) {
		a[i] = a[i + 1]; 
	}
	a[n - 1] = b; 

	

	for (int i = 0; i < n; i++) {
		cout<<a[i];
	}
	return 0;
}

