#include<iostream>
using namespace std;
int c = 0;
void exc(int *a, int *b) {
	int temp=0;
	temp = *b;
	*b = *a;
	*a = temp;
}
bool cmp(int a,int b) {
	bool flag = false;
	if (a > b) {
		flag = true;
	}
	else {
		flag = false;
	}
	c++;
	return flag;
}
void main() {
	int k[5];
	cout << "�������������" << endl;
	for (int i = 0; i < 5; i++) {
		cin >> k[i];
	}
	if (cmp(k[0], k[1])) {
		exc(&k[0], &k[1]);
	}
	if (cmp(k[2], k[3])) {
		exc(&k[2], &k[3]);
	}
	if (cmp(k[1], k[3])) {//ǰ�ĸ����������k[1]
		exc(&k[1], &k[4]);
		if (cmp(k[0], k[1])) {
			exc(&k[1], &k[1]);
		}
	}
	else {//ǰ�ĸ����������k[3]
		exc(&k[3], &k[4]);
		if (cmp(k[2], k[3])) {
			exc(&k[2], &k[3]);
		}
	}
	if (cmp(k[1], k[3])) {
		if (cmp(k[0], k[3])) {
			exc(&k[0], &k[3]);
		}
	}
	cout << "��λ��Ϊ��" << k[3] << endl;
	cout << "�Ƚ���" << c <<"��"<< endl;
	system("pause");
}