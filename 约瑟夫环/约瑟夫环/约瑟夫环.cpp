#include<iostream>
#define MaxNum 100
using namespace std;
typedef struct Node
{
	int num; //代表编号结点的数据
	Node *next;//代表后一个结点的地址
}*node;
typedef struct
{
	int data[MaxNum];
	int length;
}SqList;
void lianbiao(int n, int m)
{
	node p = NULL;
	node q = NULL;
	node first = NULL;
	for (int i = 1; i <= n; i++)
	{
		if (i == 1)
		{
			p = new Node;
			first = p;
		}
		else
		{
			q = new Node;
			p->next = q;
			p = q;
		}
		p->num = i;
	}
	p->next = first; //让表尾指向表头形成循环链表
	p = first;
	cout << "出列顺序为: ";
	for (int j = 1; j <= n; j++)
	{
		for (int i = 1; i < m; i++) {
			p = p->next;
		}
		cout << p->num << " ";
		p->num = p->next->num;
		p->next = p->next->next;
	}
	cout << endl;
	cout << endl;
}
void shunxubiao(int n, int m) {
	SqList L;
	int i=0, j, e;
	L.length = n;
	for (int k = 0; k < L.length; k++) {
		L.data[k] = k + 1;
	}
	cout << "出队顺序为：";
	while (L.length != 0)
	{
		i = (i + m - 1) % (L.length);
		cout << L.data[i] << " ";
		for (j = i; j<L.length - 1; j++)
		{
			L.data[j] = L.data[j + 1];
		}
		L.length--;
	}
	cout << endl;
}
void main() {
	int n, m;
	cout << "请输入人数n：";
	cin >> n;
	cout << "请输入m的值：";
	cin >> m;
	cout << "单向循环链表存储结构：" << endl;
	lianbiao(n, m);
	cout << "顺序存储结构：" << endl;
	shunxubiao(n, m);
	system("pause");
}