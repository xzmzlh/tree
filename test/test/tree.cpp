#include<iostream>
#include<cstdlib>
#include<stdlib.h>
using namespace std;

#define MAXSIZE 100
#define TRUE 1
#define FALSE 0

typedef int SElemType;
typedef int Status;

typedef struct {
	SElemType* base;
	SElemType* top;
	int stacksize;
}SqStack;

Status InitStack(SqStack& S);
Status DestoryStack(SqStack& S);
Status JudegDestroy(SqStack S);
Status ClearStack(SqStack& S);
Status StackEmpty(SqStack S);
Status StackLength(SqStack S);
Status GetTop(SqStack S);
Status Push(SqStack& S, SElemType e);
Status Pop(SqStack& S, SElemType e);
Status StackTraverse(SqStack S);
Status Transfer(SqStack S, int i, SElemType e);

int main() {
	cout << "--------˳��ջ--------" << endl;
	cout << "1.��ʼ��ջ" << endl;
	cout << "2.����ջ" << endl;
	cout << "3.���ջ" << endl;
	cout << "4.ջ�п�" << endl;
	cout << "5.��ջ����" << endl;
	cout << "6.��ȡջ��Ԫ��" << endl;
	cout << "7.����һ��Ԫ��" << endl;
	cout << "8.ɾ��һ��Ԫ��" << endl;
	cout << "9.�������Ԫ��" << endl;
	cout << "10.����ת��" << endl;
	cout << "�˳���������һ����������" << endl;
	cout << "����������ѡ��" << endl;
	int judge = 0;
	int choose;
	cin >> choose;
	while (judge == 0) {
		if (choose == 1) {
			judge++;
		}
		else {
			cout << "���ȳ�ʼ��ջ������" << endl;
			cout << "������ѡ��" << endl;
			cin >> choose;
		}
	}
	while (judge) {
		if (choose > 0 && choose < 11) {
			switch (choose) {
			case 1:
				SqStack S;
				if (InitStack(S))
					cout << "��ʼ���ɹ�" << endl;
				else
					cout << "��ʼ��ʧ�ܣ���������" << endl;
				break;
			case 2:
				if (DestoryStack(S))
					cout << "��ջ�����٣�������" << endl;
				break;
			case 3:
				if (JudegDestroy(S))
					cout << "��ջ�ѱ����٣������³�ʼ������" << endl;
				else
					ClearStack(S);
				cout << "����գ�����" << endl;
				break;
			case 4:
				if (JudegDestroy(S))
					cout << "��ջ�ѱ����٣������³�ʼ������" << endl;
				else
					if (StackEmpty(S))
						cout << "ջ��" << endl;
					else
						cout << "��ջ��Ϊ�գ�" << endl;
				break;
			case 5:
				if (JudegDestroy(S))
					cout << "��ջ�ѱ����٣������³�ʼ������" << endl;
				else
					cout << "��ջ�ĳ���Ϊ��" << StackLength(S) << endl;
				break;
			case 6:
				if (JudegDestroy(S))
					cout << "��ջ�ѱ����٣������³�ʼ������" << endl;
				else
					cout << "��ջ��Ԫ��Ϊ��" << GetTop(S) << endl;
				break;
			case 7:
				SElemType e;
				if (JudegDestroy(S))
					cout << "��ջ�ѱ����٣������³�ʼ������" << endl;
				else

					cout << "��������Ҫ�����Ԫ�أ�" << endl;
				cin >> e;
				while (e >= 0) {
					Push(S, e);
					cout << "��������Ҫ�����Ԫ��(�˳�������һ��������)��" << endl;
					cin >> e;
				}
				cout << "������ɣ�����" << endl;
				break;
			case 8:
				if (JudegDestroy(S))
					cout << "��ջ�ѱ����٣������³�ʼ������" << endl;
				else
					Pop(S, e);
				StackTraverse(S);
				break;
			case 9:
				if (JudegDestroy(S))
					cout << "��ջ�ѱ����٣������³�ʼ������" << endl;
				else
					StackTraverse(S);
				break;
			case 10:
				if (JudegDestroy(S))
					cout << "��ջ�ѱ����٣������³�ʼ������" << endl;
				else
					cout << "��������Ҫ���н���ת��������" << endl;
				cin >> e;
				cout << "��������Ҫת���Ľ��ƣ�" << endl;
				cout << "1.2����" << endl;
				cout << "2.8����" << endl;
				cout << "3.16����" << endl;
				int i;
				cin >> i;
				Transfer(S, i, e);
				break;
			}
		}
		else if (choose < 0) {
			cout << "���˳�" << endl;
			return 0;
		}
		else {
			cout << "�������󣡣���" << endl;
			cout << "���������룡����" << endl;
		}
		cout << endl;
		cout << "��������������Ĳ�����" << endl;
		cin >> choose;
	}
}

Status InitStack(SqStack& S) {
	S.base = new SElemType[MAXSIZE];
	if (!S.base)
		exit(FALSE);
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return TRUE;
}

Status DestoryStack(SqStack& S) {
	delete S.base;
	S.base = NULL;
	S.top = S.base;
	S.stacksize = 0;
	return TRUE;
}

Status JudegDestroy(SqStack S) {
	if (S.base == S.top && S.base == NULL)
		return TRUE;
	else
		return FALSE;
}

Status ClearStack(SqStack& S) {
	S.top = S.base;
	return TRUE;
}

Status StackEmpty(SqStack S) {
	if (S.base == S.top)
		return TRUE;
	else
		return FALSE;
}

Status StackLength(SqStack S) {
	return (S.top - S.base);
}

Status GetTop(SqStack S) {
	return *(S.top - 1);
}

Status Push(SqStack& S, SElemType e) {
	if (S.top - S.base == S.stacksize)
		cout << "ջ����������" << endl;
	else
		*S.top++ = e;
	return TRUE;
}

Status Pop(SqStack& S, SElemType e) {
	if (S.base == S.top)
		cout << "ջ�գ���" << endl;
	else
		e = *--S.top;
	return e;

}

Status StackTraverse(SqStack S) {
	SElemType* p;
	if (S.base == S.top) {
		cout << "ջ�գ���" << endl;
	}
	else {
		cout << "ջ��->";
		for (p = S.top - 1; p >= S.base; p--)
			cout << *p << " ";
		cout << endl;
	}
	return TRUE;
}


Status Transfer(SqStack S, int i, SElemType e) {
	SqStack A;
	InitStack(A);
	switch (i) {
	case 1:
		i = 2;
		break;
	case 2:
		i = 8;
		break;
	case 3:
		i = 16;
		break;
	default:
		cout << "��������!!!!" << endl;
		break;
	}
	while (e != 0) {
		Push(A, e % i);
		e = e / i;
	}
	SElemType* q;
	cout << "ת�������Ϊ��";
	for (q = A.top - 1; q >= A.base; q--) {
		cout << *q;
	}
	cout << endl;
}


















