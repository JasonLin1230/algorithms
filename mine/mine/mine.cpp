#include <iostream>
#include <algorithm>
using namespace std;
const int N = 20;
void main() {
	int n,m[N],mine[N],r[N][N];//�ֱ��ʾ���׶ѵĸ�������Ӧ���׶��еĵ��׸������ڵ����׵��������洢��ͨ·���ľ���
	cout << "������׶Ѹ�����" << endl;
	cin >> n;
	cout << "����������׶��еĵ��׸�����" << endl;
	for (int i = 0; i < n; i++) {
		cin >> m[i];
		mine[i] = m[i];
	}
	for (int i = 0; i < n; i++) {
	cout << "��������R["<<i+1<<"][j]��" << endl;
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
	cout << "�ڵ��ĵ�������Ϊ��" << final_result << endl;
	system("pause");
}