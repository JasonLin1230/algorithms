#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int func(string a, string b) {
	int s1 = a.size() + 1;
	int s2 = b.size() + 1;
	int **p = new int*[s1];
	for (int i = 0; i < s1; i++) {
		p[i] = new int[s2];
	}
	for (int i = 0; i < s1; i++) {
		p[i][0] = i;
	}
	for (int i = 0; i < s2; i++) {
		p[0][i] = i;
	}
	for (int i = 1; i < s1; i++) {
		for (int j = 1; j < s2; j++) {
			int d, temp = min(p[i-1][j] + 1, p[i][j - 1] + 1);
			if (a[i - 1] == b[j - 1]) {
				d = 0;
			}
			else {
				d = 1;
			}
			p[i][j] = min(temp, p[i - 1][j - 1] + d);
		}
	}
	int final_result = p[s1-1][s2-1];
	return final_result;
}
void main() {
	string s1, s2;
	cout << "ÇëÊäÈëµÚÒ»¸ö×Ö·û´®£º" << endl;
	cin >> s1;
	cout << "ÇëÊäÈëµÚ¶þ¸ö×Ö·û´®£º" << endl;
	cin >> s2;
	int d = func(s1, s2);
	cout << "±à¼­¾àÀëÎª£º" << d << endl;
	system("pause");
}