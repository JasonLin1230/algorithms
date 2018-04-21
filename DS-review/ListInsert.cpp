#include <iostream>
#define MaxSize 100
using namespace std;
typedef struct {
	int data[MaxSize];
	int length;
}SqList;
int m;
void InitList() {
	cout << "请输入个数：" << endl;
	cin >> m;
	if (m > 100) {
		cout << "个数过多，异常" << endl;
		return;
	}
	SqList L;
	L.length = m;
	for (int k = 0; k < m; k++) {
		cin >> L.data[k];
	}
}
bool ListInsert(SqList &L,int i,int e) {
	if (i<1 || i>L.length + 1) {
		return false;
	}
	if (L.length >= MaxSize) {
		return false;
	}
	for (int j = L.length; j > i; j--) {
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.length++;
	return true;
}
int main() {
	InitList();
	system("pause");
	return 0;
}