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
	cout << "--------顺序栈--------" << endl;
	cout << "1.初始化栈" << endl;
	cout << "2.销毁栈" << endl;
	cout << "3.清空栈" << endl;
	cout << "4.栈判空" << endl;
	cout << "5.求栈长度" << endl;
	cout << "6.获取栈顶元素" << endl;
	cout << "7.插入一个元素" << endl;
	cout << "8.删除一个元素" << endl;
	cout << "9.输出所有元素" << endl;
	cout << "10.进制转换" << endl;
	cout << "退出，请输入一个负数！！" << endl;
	cout << "请输入您的选择：" << endl;
	int judge = 0;
	int choose;
	cin >> choose;
	while (judge == 0) {
		if (choose == 1) {
			judge++;
		}
		else {
			cout << "请先初始化栈！！！" << endl;
			cout << "请输入选择：" << endl;
			cin >> choose;
		}
	}
	while (judge) {
		if (choose > 0 && choose < 11) {
			switch (choose) {
			case 1:
				SqStack S;
				if (InitStack(S))
					cout << "初始化成功" << endl;
				else
					cout << "初始化失败！！！！！" << endl;
				break;
			case 2:
				if (DestoryStack(S))
					cout << "该栈已销毁！！！！" << endl;
				break;
			case 3:
				if (JudegDestroy(S))
					cout << "该栈已被销毁，请重新初始化！！" << endl;
				else
					ClearStack(S);
				cout << "已清空！！！" << endl;
				break;
			case 4:
				if (JudegDestroy(S))
					cout << "该栈已被销毁，请重新初始化！！" << endl;
				else
					if (StackEmpty(S))
						cout << "栈空" << endl;
					else
						cout << "该栈不为空！" << endl;
				break;
			case 5:
				if (JudegDestroy(S))
					cout << "该栈已被销毁，请重新初始化！！" << endl;
				else
					cout << "该栈的长度为：" << StackLength(S) << endl;
				break;
			case 6:
				if (JudegDestroy(S))
					cout << "该栈已被销毁，请重新初始化！！" << endl;
				else
					cout << "该栈顶元素为：" << GetTop(S) << endl;
				break;
			case 7:
				SElemType e;
				if (JudegDestroy(S))
					cout << "该栈已被销毁，请重新初始化！！" << endl;
				else

					cout << "请输入您要插入的元素：" << endl;
				cin >> e;
				while (e >= 0) {
					Push(S, e);
					cout << "请输入您要插入的元素(退出请输入一个负数！)：" << endl;
					cin >> e;
				}
				cout << "插入完成！！！" << endl;
				break;
			case 8:
				if (JudegDestroy(S))
					cout << "该栈已被销毁，请重新初始化！！" << endl;
				else
					Pop(S, e);
				StackTraverse(S);
				break;
			case 9:
				if (JudegDestroy(S))
					cout << "该栈已被销毁，请重新初始化！！" << endl;
				else
					StackTraverse(S);
				break;
			case 10:
				if (JudegDestroy(S))
					cout << "该栈已被销毁，请重新初始化！！" << endl;
				else
					cout << "请输入您要进行进制转换的数：" << endl;
				cin >> e;
				cout << "请输入您要转换的进制：" << endl;
				cout << "1.2进制" << endl;
				cout << "2.8进制" << endl;
				cout << "3.16进制" << endl;
				int i;
				cin >> i;
				Transfer(S, i, e);
				break;
			}
		}
		else if (choose < 0) {
			cout << "已退出" << endl;
			return 0;
		}
		else {
			cout << "输入有误！！！" << endl;
			cout << "请重新输入！！！" << endl;
		}
		cout << endl;
		cout << "请输入接下来您的操作：" << endl;
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
		cout << "栈已满！！！" << endl;
	else
		*S.top++ = e;
	return TRUE;
}

Status Pop(SqStack& S, SElemType e) {
	if (S.base == S.top)
		cout << "栈空！！" << endl;
	else
		e = *--S.top;
	return e;

}

Status StackTraverse(SqStack S) {
	SElemType* p;
	if (S.base == S.top) {
		cout << "栈空！！" << endl;
	}
	else {
		cout << "栈顶->";
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
		cout << "输入有误!!!!" << endl;
		break;
	}
	while (e != 0) {
		Push(A, e % i);
		e = e / i;
	}
	SElemType* q;
	cout << "转换后的数为：";
	for (q = A.top - 1; q >= A.base; q--) {
		cout << *q;
	}
	cout << endl;
}


















