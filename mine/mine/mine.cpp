#include <iostream>
#include <algorithm>
using namespace std;
const int N = 20;
void main() {
	int n,m[N],mine[N],r[N][N];//分别表示地雷堆的个数，相应地雷堆中的地雷个数，挖到地雷的数量，存储连通路径的矩阵
	cout << "输入地雷堆个数：" << endl;
	cin >> n;
	cout << "依次输入地雷堆中的地雷个数：" << endl;
	for (int i = 0; i < n; i++) {
		cin >> m[i];
		mine[i] = m[i];
	}
	for (int i = 0; i < n; i++) {
	cout << "依次输入R["<<i+1<<"][j]：" << endl;
		for (int j = i; j < n; j++) {
			cin >> r[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (r[i][j] && r[i][j]==1)//&& mine[j]>mine[i]
			{
				if (mine[i]+m[j]>=mine[j]) {
					mine[j] = mine[i] + m[j];
				}
			}
		}
	}
	int final_result = 0;
	for (int i = 0; i < n; i++) {
		if (mine[i]>final_result){
			final_result = mine[i];
		}
	}
	cout << "挖到的地雷总数为：" << final_result << endl;
	system("pause");
}