#include<iostream>
#include<stdio.h>
using namespace std;
void sort(int n,float v[],float w[],int flag[]) {
	float r[100];
	for (int i = 1; i<=n; i++) {
		r[i] = v[i] * 1.0 / w[i];
	}
	for (int i = 1; i<n; i++) {
		for (int j = 1; j<=n - i; j++) {
			if (r[j]<r[j + 1]) {
				float y;
				y = r[j]; r[j] = r[j + 1];
				r[j + 1] = y;
				y = w[j]; w[j] = w[j + 1];
				w[j + 1] = y;
				y = v[j]; v[j] = v[j + 1];
				v[j + 1] = y;
				y = flag[j]; flag[j] = flag[j + 1];
				flag[j + 1] = y;
			}
		}
	}
}
int main() {
	float w[100], v[100];
	float x[100];
	float m;//背包的容量
	int n;//物品的数量
	int flag[100];
	cout << "请输入背包容量：" << endl;
	cin >> m;
	cout << "请输入物品数量：" << endl;
	cin >> n;
	while (n<0 || n > 99) {
		cout << "请输入0--99的整数：" << endl;
		cin >> n;
	}
	cout << "请依次输入物品的重量：" << endl;
	for (int i = 1; i<=n; i++) {
		cin >> w[i];
		flag[i] = i;
	}
	cout << "请依次输入物品的价值：" << endl;
	for (int i = 1; i<=n; i++) {
		cin >> v[i];
	}
	sort(n, v, w, flag);
	int i = 1;
	for (i = 1; i <= n; i++) {
		x[i] = 0;
	}
	float cu = m; i = 1;
	while ((i <= n) && w[i] <= cu) {
		x[i] = 1;
		cu = cu - w[i];
		i = i + 1;
	}
	if (i <= n) {
		x[i] = cu / w[i];
	}
	for (int i = 1; i <= n; i++) {
		cout << "第" << flag[i] << "个商品取：" << x[i] << endl;
	}
	system("pause");
	return 0;
}
//样例输入
//C 50
//w 20  30  10
//v 100 120 60
//单位 5 4 6