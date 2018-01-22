#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 14
#define n 3
#define fee 10
using namespace std;
struct car//��ų���״̬�����룬ʱ����Ϣ
{
	int bb;
	int num;
	int time;
};
typedef struct stack {//ģ��ͣ������ջ
	struct car G[n];
	int top;
}SqStack;
struct rangweicar//�����ʱ�ó��ĳ����ĺ����ʱ����Ϣ
{
	int num;
	int time;
};
typedef struct stackk {//ģ����ʱ�ó��ĳ���ͣ�ŵĳ���
	struct rangweicar H[MAXSIZE];
	int top;
}SqStackk;
typedef struct QNODE {//�������ĳ����ĳ��ƺ�
	int data;
	QNODE *next;
}QNODE;
typedef struct linkqueue {//ģ�����Ķ���
	QNODE *front, *rear;
	int geshu;
}LinkQueue;
void A_cars(SqStack *s, LinkQueue *q, struct car a) {
	QNODE *t;
	if (s->top != n - 1) {
		(s->top)++;
		(s->G[s->top]).bb = a.bb;
		(s->G[s->top]).num = a.num;
		(s->G[s->top]).time = a.time;
	}
	else {
		cout << "ͣ�����������ó�������������"<<endl;
		system("pause");
		t = (QNODE*)malloc(sizeof(QNODE));
		t->data = a.num;
		t->next = NULL;
		q->rear->next = t;
		q->rear = t;
		q->geshu++;
	}
}
int D_cars(SqStack *s,LinkQueue *q,struct car d){
	int i,j,l,x,y;
	QNODE *p;
	SqStackk *k;
	if (d.time < (s->G[s->top]).time) {
		cout << "ERROR���������뿪ʱ���ڽ���ʱ��֮ǰ�������������룡��" << endl;
			return -1;
	}else if (d.num == (s->G[s->top]).num) {
		x = d.time - (s->G[s->top]).time;
		y = fee*x;
		cout << "ͣ��ʱ��Ϊ��" << x << "��ͣ������Ϊ��" << y << endl;
		if (q->geshu == 0) {
			cout << "���Ϊ��" << endl;
			s->top = s->top - 1;
			return 0;
		}
		else {
			p = q->front->next;
			q->front->next = p->next;
			(s->G[s->top]).num = p->data;
			(s->G[s->top]).time = d.time;
			free(p);
			q->geshu++;
			if (q->front->next == NULL) {
				q->rear = q->front;
				return 1;
			}
		}
	}
	else {
		for (i = 0; i < (s->top); i++) {
			if ((s->G[i]).num != d.num) {
				continue;
			}
			else {
				break;
			}
		}
		if (i >= (s->top)) {
			cout << "ERROR����δ�ҵ�����������Ϣ���� " << endl;
			return -1;
		}
		x = d.time - (s->G[i]).time;
		y = fee*x;
		cout << "ͣ��ʱ��Ϊ��" << x << "��ͣ������Ϊ��" << y << endl;
		k = (SqStackk*)malloc(sizeof(SqStackk));
		k->top = -1;
		for (j = (s->top); j > i; j--) {
			k->top++;
			(k->H[k->top]).num = (s->G[j]).num;
			(k->H[k->top]).time = (s->G[j]).time;
			s->top--;
		}
		cout << "��ʱ�ó��ĳ�����ϢΪ��(���ź�ʱ��)" << endl;
		for (l = 0; l <= (k->top); l++) {
			cout << k->H[l].num << " " << k->H[l].time << endl;
		}
		s->top--;
		while (k->top>=0)//����ʱ�ó��ĳ����ٴν���ͣ����
		{
			s->top++;
			(s -> G[s->top]).bb = 1;
			(s->G[s->top]).num = (k->H[k->top]).num;
			(s->G[s->top]).time = (k->H[k->top]).time;
			k->top--;
		}
		if (q->geshu == 0) {
			cout << "���Ϊ��" << endl;
			return 2;
		}
		else {//�ñ�����ж�ͷ��һ��������ͣ����
			s->top++;
			p = q->front->next;
			q->front->next = p->next;
			(s->G[s->top]).num = p->data;
			(s->G[s->top]).time = d.time;
			free(p);
			q->geshu--;
			if (q->front->next == NULL) {
				q->rear = q->front;
			}
			return 3;
		}
	}
}
int main() {
	SqStack *s;
	LinkQueue *q;
	QNODE *p;
	struct car aa[MAXSIZE];
	int i;
	s = (SqStack*)malloc(sizeof(SqStack));
	s->top = -1;
	q = (LinkQueue*)malloc(sizeof(LinkQueue));
	p = (QNODE*)malloc(sizeof(QNODE));
	p->next = NULL;
	q->front = q->rear = p;
	q->geshu = 0;
	for (i = 0; i < MAXSIZE; i++) {
		cout << "***********************************ͣ��������ϵͳ***********************" << endl;
		cout << "************************************************************************" << endl;
		cout << "1���������2�������뿪��3��ͣ��������������4���������������5���˳���" << endl;
		cout << "������ָ�" << endl;
		cin >> aa[i].bb;
		switch (aa[i].bb)
		{
		case 5:
			return 0;
		case 4:
			cout << "�������������Ϊ��" << q->geshu << endl;
			system("pause");
			system("cls");
			break;
		case 3:
			cout << "ͣ��������������Ϊ��" << (s->top) + 1 << endl;
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "�����복�ƺţ�" << endl;
			cin >> aa[i].num;
			cout << "������ʱ��" << endl;
			cin >> aa[i].time;
			D_cars(s, q, aa[i]);
			system("pause");
			break;
		case 1:
			cout << "�����복�ƺţ�" << endl;
			cin >> aa[i].num;
			cout << "������ʱ��" << endl;
			cin >> aa[i].time;
			A_cars(s, q, aa[i]);
			break;
		default:
			cout << "ERROR����ָ����󣡣����������룡��" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			system("pause");
			system("cls");
			i = -1;
			break;
		}
		system("cls");
	}
}