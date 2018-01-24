#include<iostream>
using namespace std;
void MatrixChian(int *p, int n, int **m, int **s) {//计算最优值
	for (int i = 1; i <= n; i++) {
		m[i][i] = 0;
	}
	for (int r = 2; r <= n; r++) {//r为问题的规模
		for (int i = 1; i <= n - r + 1; r++) {//规模为r的子问题个数
			int j = i + r - 1;
			m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
			s[i][j] = i;
			for (int k = i + 1; k < j; k++) {
				int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (t < m[i][j]) {
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}
	}
};
void Traceback(int i, int j, int **s) {//构造最优解
	if (i == j) {
		return;
	}
	Traceback(i, s[i][j], s);
	Traceback(s[i][j] + 1, j, s);
	cout << "Multiply A" << i << "," << s[i][j];
	cout << "and A" << (s[i][j]+1) << "," << j << endl;
};
void main() {
	int **s,n,**m;
	cout << "请输入矩阵的个数n：" << endl;
	cin >> n;
	int *p = new int[n];
	for (int i = 0; i <= n;i++) {//初始化数组p
		cout << "请输入对应矩阵的维数p" << i << +"："<< endl;
		cin >> p[i];
	}
	m = new int *[n];//动态创建二维数组m
	for (int i = 0; i <= n;i++) {
		m[i] = new int[n];
	}
	s = new int *[n];//动态创建二维数组m
	for (int i = 0; i <= n; i++) {
		s[i] = new int[n];
	}
	MatrixChian(p, n, m, s);
	Traceback(1, n, s);
}
//int RecurMatrixChain(int i, int j) {//普通递归算法
//	if (i == j) {
//		return 0;
//	}
//	int u = RecurMatrixChain(i, i) + RecurMatrixChain(i + 1, j) + p[i - 1] * p[i] * p[j];
//	s[i][j] = i;
//	for (int k = 1; k < j; k++) {
//		int t= RecurMatrixChain(i, k) + RecurMatrixChain(k + 1, j) + p[i - 1] * p[k] * p[j];
//		if (t < u) {
//			u = t;
//			s[i][j] = k;
//		}
//	}
//	return u;
//}