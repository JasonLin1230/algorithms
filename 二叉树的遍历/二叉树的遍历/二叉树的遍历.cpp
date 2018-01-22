#include "iostream"
#include "stdlib.h"
using namespace std;
typedef struct TreeNode {
	int data;
	struct TreeNode *lchild, *rchild;
}*TNode;
void CreateBtr(TNode &t) {
	cout << "�밤���������ݣ�" << endl;
	int a;
	cin >> a;
	if (a == 0) {
		t = NULL;
	}
	else {
		TNode p = new TreeNode;
		p->data = a;
		t = p;
		CreateBtr(t->lchild);
		CreateBtr(t->rchild);
	}
}
void Preorder(TNode t) {
	if (t != NULL) {
		cout << t->data<<" ";
		Preorder(t->lchild);
		Preorder(t->rchild);
	}
}
void Inorder(TNode t) {
	if (t != NULL) {
		Inorder(t->lchild);
		cout << t->data<<" ";
		Inorder(t->rchild);
	}
}
void Postorder(TNode t) {
	if (t != NULL) {
		Postorder(t->lchild);
		Postorder(t->rchild);
		cout << t->data<<" ";
	}
}
void main() {
	TNode t;
	CreateBtr(t);
	system("cls");
	for (;;) {
		cout << "���������ѡ�������ʽ��" << endl;
		cout << "1.ǰ�������2.���������3.���������4.�˳�" << endl;
		int m;
		cin >> m;
		switch (m)
		{
		case 1:
			cout << "��������Ľ��Ϊ��";
			Preorder(t);
			break;
		case 2:
			cout << "��������Ľ��Ϊ��";
			Inorder(t);
			break;
		case 3:
			cout << "��������Ľ��Ϊ��";
			Postorder(t);
			break;
		case 4:
			return;
		default:
			cout << "ERROR!!����������" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		system("pause");
		system("cls");
	}
}