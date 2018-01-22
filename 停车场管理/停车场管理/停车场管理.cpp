#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 14
#define n 3
#define fee 10
using namespace std;
struct car//存放车的状态，号码，时间信息
{
	int bb;
	int num;
	int time;
};
typedef struct stack {//模拟停车场的栈
	struct car G[n];
	int top;
}SqStack;
struct rangweicar//存放临时让出的车辆的号码和时间信息
{
	int num;
	int time;
};
typedef struct stackk {//模拟临时让出的车辆停放的场地
	struct rangweicar H[MAXSIZE];
	int top;
}SqStackk;
typedef struct QNODE {//进入便道的车辆的车牌号
	int data;
	QNODE *next;
}QNODE;
typedef struct linkqueue {//模拟便道的队列
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
		cout << "停车场已满，该车辆将进入便道。"<<endl;
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
		cout << "ERROR！！车辆离开时间在进入时间之前！！请重新输入！！" << endl;
			return -1;
	}else if (d.num == (s->G[s->top]).num) {
		x = d.time - (s->G[s->top]).time;
		y = fee*x;
		cout << "停车时长为：" << x << "，停车费用为：" << y << endl;
		if (q->geshu == 0) {
			cout << "便道为空" << endl;
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
			cout << "ERROR！！未找到该辆车的信息！！ " << endl;
			return -1;
		}
		x = d.time - (s->G[i]).time;
		y = fee*x;
		cout << "停车时间为：" << x << "，停车费用为：" << y << endl;
		k = (SqStackk*)malloc(sizeof(SqStackk));
		k->top = -1;
		for (j = (s->top); j > i; j--) {
			k->top++;
			(k->H[k->top]).num = (s->G[j]).num;
			(k->H[k->top]).time = (s->G[j]).time;
			s->top--;
		}
		cout << "临时让出的车辆信息为：(车号和时间)" << endl;
		for (l = 0; l <= (k->top); l++) {
			cout << k->H[l].num << " " << k->H[l].time << endl;
		}
		s->top--;
		while (k->top>=0)//让临时让出的车辆再次进入停车场
		{
			s->top++;
			(s -> G[s->top]).bb = 1;
			(s->G[s->top]).num = (k->H[k->top]).num;
			(s->G[s->top]).time = (k->H[k->top]).time;
			k->top--;
		}
		if (q->geshu == 0) {
			cout << "便道为空" << endl;
			return 2;
		}
		else {//让便道队列队头的一辆车进入停车场
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
		cout << "***********************************停车场管理系统***********************" << endl;
		cout << "************************************************************************" << endl;
		cout << "1：车辆到达；2：车辆离开：3：停车场车辆总数；4：便道车辆总数；5：退出。" << endl;
		cout << "请输入指令：" << endl;
		cin >> aa[i].bb;
		switch (aa[i].bb)
		{
		case 5:
			return 0;
		case 4:
			cout << "便道中汽车辆数为：" << q->geshu << endl;
			system("pause");
			system("cls");
			break;
		case 3:
			cout << "停车场中汽车辆数为：" << (s->top) + 1 << endl;
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "请输入车牌号：" << endl;
			cin >> aa[i].num;
			cout << "请输入时间" << endl;
			cin >> aa[i].time;
			D_cars(s, q, aa[i]);
			system("pause");
			break;
		case 1:
			cout << "请输入车牌号：" << endl;
			cin >> aa[i].num;
			cout << "请输入时间" << endl;
			cin >> aa[i].time;
			A_cars(s, q, aa[i]);
			break;
		default:
			cout << "ERROR！！指令错误！！请重新输入！！" << endl;
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