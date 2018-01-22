#include "iostream"
#include "stdlib.h"
using namespace std;
typedef struct TreeNode {
	int data;
	struct TreeNode *lchild, *rchild;
}*TNode;
void CreateBtr(TNode &t) {
	cout << "请挨个输入数据：" << endl;
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
		cout << "请输入序号选择遍历方式：" << endl;
		cout << "1.前序遍历；2.中序遍历；3.后序遍历；4.退出" << endl;
		int m;
		cin >> m;
		switch (m)
		{
		case 1:
			cout << "先序遍历的结果为：";
			Preorder(t);
			break;
		case 2:
			cout << "中序遍历的结果为：";
			Inorder(t);
			break;
		case 3:
			cout << "后序遍历的结果为：";
			Postorder(t);
			break;
		case 4:
			return;
		default:
			cout << "ERROR!!请重新输入" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		system("pause");
		system("cls");
	}
}