#include<iostream>
#include<fstream>
#include<string>
#include "stdlib.h"
using namespace std;
typedef struct Node {
	string name;
	long long key;
	string address;
	Node *next;
}*Link_list;
typedef Node HST[8];

int Sum(long long i,int *sum) {//���һ�����ָ�λ��ӵĺ�
	if (i / 10 == 0)
	{
		(*sum) += (i % 10);
		return 0;
	}
	else
	{
		(*sum) += (i % 10);
		return Sum(i / 10, sum);
	}
}
int Hash(int k) {//�����Ӧ�Ĺ�ϣ��ַ
	int addr=0;
	addr = k % 7;
	return addr;
}
Link_list HashSearchChain(HST &hst, long long k) {//�����㷨
	int h, sum = 0;
	Sum(k, &sum);
	h = Hash(sum);
	Link_list p;
	p = hst[h].next;
	//Link_list p = NULL;
	while (p && p->key != k) {
		p = p->next;
	}
	return p;
}
void fread(HST &hst) {//��ȡ�ļ�
	fstream fin("data.txt");
	if (fin) {
		long long key;string name, address;
		while (fin >> key >> name >> address) {
			int sum = 0,addr;
			Sum(key, &sum);
			addr=Hash(sum);

			if (HashSearchChain(hst, key) != NULL) {
				//cout << "�˺����Ѵ��ڣ���" << endl;
				return;
			}
			if (hst[addr].next == NULL) {
				Link_list q = new Node;
				q->key = key;
				q->name = name;
				q->address = address;
				q->next = NULL;
				hst[addr].next = q;
			}
			else {
				Link_list s;
				s = hst[addr].next;
				while (s->key != key && s->next != NULL) {
					s = s->next;
				}
				if (s->key == key) {
					return;
				}
				else {
					Link_list q = new Node;
					q->key = key;
					q->name = name;
					q->address = address;
					q->next = NULL;
					s->next = q;
				}
			}
		}
	}
	//fin.close();
}
void fsave(HST &hst) {//�洢���ļ�
	ofstream fout("data.txt");
	for (int i = 0; i < 8;i++) {
		Link_list s;
		s = hst[i].next;
		while (s) {
			fout <<s->key <<" "<< s->name << " " << s->address << endl;
			s = s->next;
		}
	}
}
void HashInsertChain(HST &hst) {//�����㷨
	string n,a; int h,sum = 0; long long k;
	cout << "��������Ҫ��ӵ��ֻ��ţ�" << endl;
	cin >> k;
	Sum(k, &sum);
	h = Hash(sum);
	cout << "��������Ҫ������" << endl;
	cin >> n;
	cout << "�������ַ��" << endl;
	cin >> a;
	if (HashSearchChain(hst, k) != NULL) {
		cout << "�˺����Ѵ��ڣ���" << endl;
		return;
	}
	if (hst[h].next == NULL) {
		Link_list q=new Node;
		q->key = k;
		q->name = n;
		q->address = a;
		q->next = NULL;
		hst[h].next = q;
	}
	else {
		Link_list s;
		s = hst[h].next;
		while (s->key != k && s->next != NULL) {
			s = s->next;
		}
		if (s->key == k) {
			return;
		}
		else {
			Link_list q =new Node;
			q->key = k;
			q->name = n;
			q->address = a;
			q->next = NULL;
			s->next = q;
		}
	}
}
void HashDeleteChain(HST &hst,long long k) {//ɾ���㷨
	int h,sum=0;
	Sum(k, &sum);
	h = Hash(sum);
	if (HashSearchChain(hst,k)==NULL) {
		cout << "���û���Ϣ������!!" << endl;
		return;
	}
	else {
		Link_list s;
		s = hst[h].next;
		Link_list p;
		p = NULL;
		while (s->key != k && s->next != NULL) {
			p = s;
			s = s->next;
		}
		if (s->key == k) {
			if (p == NULL) {
				hst[h].next = s->next;
			}
			else {
				p->next = s->next;
			}
			delete s;
			cout << "ɾ���ɹ�����" << endl;
		}
	}
}
int main() {
	HST hashTable;
	for (int i = 0; i < 8; i++) {
		hashTable[i].next = NULL;
	}
	fread(hashTable);
	for(;;)
	{
		cout << "********************�ֽ��Ĺ�ϣ��*******************" << endl;
		cout << "***************************************************" << endl;
		cout << "ѡ����Ҫ���еĲ�����1.��ӣ�2.���ң�3ɾ����4.�˳�" << endl;
		int c;
		cin >> c;
		/*if (cin.fail()) {
			c = 5;
			cin.clear();
		}*/
		//if (typeid(c) == typeid(string) || typeid(c) == typeid(char)) {
			//c = 4;
		//}
		switch (c) {
		case 1:
			HashInsertChain(hashTable);
			system("cls");
			break;
		case 2:
			long long  k; Link_list p;
			cout << "��������Ҫ���ҵ��ֻ��ţ�" << endl;
			cin >> k;
			if (HashSearchChain(hashTable, k)) {
				p = HashSearchChain(hashTable, k);
				cout << "���ҽ��Ϊ��[ " << p->key << " " << p->name << " " << p->address << " ]" << endl;
			}
			else {
				cout << "δ���ҵ������Ϣ����" << endl;
			}
			system("pause");
			system("cls");
			break;
		case 3:
			cout << "��������Ҫɾ�����ֻ��ţ�" << endl;
			cin >> k;
			HashDeleteChain(hashTable,k);
			system("pause");
			system("cls");
			break;
		case 4:
			return 0;
		default:
			cout << "ERROR!!" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			system("pause");
			system("cls");
			break;
		}
		fsave(hashTable);
	}
	system("pause");
}