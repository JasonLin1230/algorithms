#include <iostream>
#include<algorithm>
using namespace std;
int w[100],v[100],x[100];//物品的选取状态
int V[100][100];//前i个物品装入容量为j的背包中获得的最大价值
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
			if (V[i][j] < 10) {//为使输出二维数组更美观，小于10的数在前面补0
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
	int s = 0;//获得的最大价值
	int n = 0, i = 0;
	int C = 0;//背包容量
	cout << "请输入物品数：" << endl;
	cin >> n;
	while (n < 0 || n > 99) {
		cout << "请输入0--99的整数：" << endl;
		cin >> n;
	}
	cout << "请输入背包最大容量：" << endl;
	cin >> C;
	cout << "请分别输入物品的重量：" << endl;
	for (i = 1; i <= n; i++) {
		cin >> w[i];
	}
	cout << "请分别输入物品的价值：" << endl;
	for (i = 1; i <= n; i++) {
		cin >> v[i];
	}
	s = Knapsack(v, w, C, n);
	cout << "获得的最大价值为：" << s << endl;
	Traceback(w, C, n, x);
	cout << "二维数组输为：" << endl;
	printArray(n, C);
	system("pause");
	return 0;
}
//样例输入
//C 10
//w 2 2 6 5 4
//v 6 3 5 4 6