#include <iostream>
#include <algorithm>
using namespace std;
const int N = 10;
int num[N][N];
int curr[N][N];
int n;
void func() {
	for (int i = 0; i < n; i++) {
		curr[n - 1][i] = num[n - 1][i];
	}
	int cur_max;
	for (int j = 1; j < n; j++) {
		for (int k = 0; k < j;k++) {
			cur_max = max(curr[j-1][k],curr[j-1][k+1]);
			curr[j][k] = cur_max + num[j][k];
		}
	}
}
void main() {
	cout << "�����������ĸ߶ȣ�";
	cin >> n;
	cout << "��������������������" << endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			cin >> num[i][j];
		}
	}
	func();
	int final_result = 0;
	for (int i = 0; i < n;i++) {
		if (curr[n - 1][i] > final_result) {
			final_result = curr[n - 1][i];
		}
	}
	cout << "���·��֮���ǣ�"<<final_result << endl;
	system("pause");
}