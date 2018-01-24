#include <iostream>
#include<algorithm>
using namespace std;
int w[100],v[100],x[100];//��Ʒ��ѡȡ״̬
int V[100][100];//ǰi����Ʒװ������Ϊj�ı����л�õ�����ֵ
int Knapsack(int v[], int w[], int C, int n)
{
	int i = 0, j = 0;
	for (i = 0; i <= n; i++)
		V[i][0] = 0;
	for (j = 0; j <= C; j++)
		V[0][j] = 0;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= C; j++) {
			if (j < w[i]) {
				V[i][j] = V[i - 1][j];
			}
			else {
				V[i][j] = max(V[i - 1][j], V[i - 1][j - w[i]] + v[i]);
			}
		}
	}
	return V[n][C];
}
int Traceback(int w[], int C, int n, int x[])
{
	int i = 0;
	for (i = n; i>0; i--)
	{
		if (V[i][C] == V[i - 1][C]) {
			x[i] = 0;
		}
		else {
			x[i] = 1;
			C -= w[i];
		}
	}
	return x[i];
}
void printArray(int n, int C) {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= C; j++) {
			if (V[i][j] < 10) {//Ϊʹ�����ά��������ۣ�С��10������ǰ�油0
				cout << "0" << V[i][j] << "  ";
			}
			else {
				cout << V[i][j] << "  ";
			}
		}
		cout << endl;
	}
}
int main()
{
	int s = 0;//��õ�����ֵ
	int n = 0, i = 0;
	int C = 0;//��������
	cout << "��������Ʒ����" << endl;
	cin >> n;
	while (n < 0 || n > 99) {
		cout << "������0--99��������" << endl;
		cin >> n;
	}
	cout << "�����뱳�����������" << endl;
	cin >> C;
	cout << "��ֱ�������Ʒ��������" << endl;
	for (i = 1; i <= n; i++) {
		cin >> w[i];
	}
	cout << "��ֱ�������Ʒ�ļ�ֵ��" << endl;
	for (i = 1; i <= n; i++) {
		cin >> v[i];
	}
	s = Knapsack(v, w, C, n);
	cout << "��õ�����ֵΪ��" << s << endl;
	Traceback(w, C, n, x);
	cout << "��ά������Ϊ��" << endl;
	printArray(n, C);
	system("pause");
	return 0;
}
//��������
//C 10
//w 2 2 6 5 4
//v 6 3 5 4 6