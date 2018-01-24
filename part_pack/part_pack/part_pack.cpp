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
	float m;//����������
	int n;//��Ʒ������
	int flag[100];
	cout << "�����뱳��������" << endl;
	cin >> m;
	cout << "��������Ʒ������" << endl;
	cin >> n;
	while (n<0 || n > 99) {
		cout << "������0--99��������" << endl;
		cin >> n;
	}
	cout << "������������Ʒ��������" << endl;
	for (int i = 1; i<=n; i++) {
		cin >> w[i];
		flag[i] = i;
	}
	cout << "������������Ʒ�ļ�ֵ��" << endl;
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
		cout << "��" << flag[i] << "����Ʒȡ��" << x[i] << endl;
	}
	system("pause");
	return 0;
}
//��������
//C 50
//w 20  30  10
//v 100 120 60
//��λ 5 4 6