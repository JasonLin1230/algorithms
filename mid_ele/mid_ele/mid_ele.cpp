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
	cout << "请输入五个数：" << endl;
	for (int i = 0; i < 5; i++) {
		cin >> k[i];
	}
	if (cmp(k[0], k[1])) {
		exc(&k[0], &k[1]);
	}
	if (cmp(k[2], k[3])) {
		exc(&k[2], &k[3]);
	}
	if (cmp(k[1], k[3])) {//前四个数中最大是k[1]
		exc(&k[1], &k[4]);
		if (cmp(k[0], k[1])) {
			exc(&k[1], &k[1]);
		}
	}
	else {//前四个数中最大是k[3]
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
	cout << "中位数为：" << k[3] << endl;
	cout << "比较了" << c <<"次"<< endl;
	system("pause");
}