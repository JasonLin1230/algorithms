#include <iostream>
using namespace std;
const int Max_num = 100;
void main() {
	int n;
	int num[Max_num];
	cout << "�������Ŷӵ�������n(0~100)��"<< endl;
	cin >> n;
	if (n > 100 || n < 0) {
		cout << "������0~100������Ŷ��" << endl;
		cin >> n;
	}
	cout << "����������ÿ������Ҫ�����ʱ�䣺" << endl;
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
	cout << "�Ŷ�ʱ������ʱ�Ĵ���" << endl;
	for (int x = 0; x < n;x++) {
		cout << num[x] << " ";
		final_result += num[x]*(n-x);
	}
	cout << endl << "����ʱ��Ϊ��" << final_result << endl;
	system("pause");
}