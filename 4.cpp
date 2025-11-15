#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char a[1000], b[100];
	cin.getline(a, 1000);
	cin.getline(b, 100);
	int lenA = strlen(a);
	int lenB = strlen(b);
	
	if (lenB == 0) {
		cout << 0 << endl;
		return 0;
	}
	
	if (lenB > lenA) {
		cout << -1 << endl;
		return 0;
	}
	
	for (int i = 0; i <= lenA - lenB; i++) {
		if (a[i] == b[0]) {
			bool match = true;
			for (int j = 1; j < lenB; j++) {
				if (a[i + j] != b[j]) {
					match = false;
					break;
				}
			}
			if (match) {
				cout << i << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
	return 0;
}
