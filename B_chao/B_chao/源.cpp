#include <iostream>
using namespace std;
const int Max_num = 100;
void main() {
	int n;
	int num[Max_num];
	cout << "请输入排队的总人数n(0~100)："<< endl;
	cin >> n;
	if (n > 100 || n < 0) {
		cout << "请输入0~100的数字哦：" << endl;
		cin >> n;
	}
	cout << "请依次输入每个人需要处理的时间：" << endl;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	for (int j = 0; j < n; j++) {
		for (int k = j + 1; k < n; k++) {
			if (num[k] < num[j]) {
				int temp = num[k];
				num[k] = num[j];
				num[j] = temp;
			}
		}
	}
	int final_result = 0;
	cout << "排队时间最少时的次序：" << endl;
	for (int x = 0; x < n;x++) {
		cout << num[x] << " ";
		final_result += num[x]*(n-x);
	}
	cout << endl << "最少时间为：" << final_result << endl;
	system("pause");
}