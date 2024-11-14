#include <stdlib.h> 
#include <cstdlib>
#include <iostream> 
using namespace std;

#define MAXSIZE 100
constexpr auto TRUE = 1;
#define FALSE 0
//ABC##DE#G##F###
typedef char TElemType;
typedef int Status;

typedef struct BiTNode {
	TElemType date;
	struct BiTNode* LNode;
	struct BiTNode* RNode;
}BiTNode, * BiTree;
typedef struct QNode {
	BiTree date;
	struct QNode* next;
}QNode, * QueuePtr;

typedef struct {
	QueuePtr head;
	QueuePtr rear;
}LinkQueue;

typedef struct {
	BiTree base;
	BiTree top;
	int stacksize;
}SqStack;

Status InitStack(SqStack& S);
Status StackEmpty(SqStack S);
Status Pop(SqStack& S, BiTree &q);
Status Push(SqStack& S, BiTree q);
Status CreateBiTree(BiTree& T);
void visit(BiTree T);
Status PreOrderTraverse(BiTree T);
Status InOrderTraverse(BiTree T);
Status InOrderTraverseF(BiTree T);
void PostOrderTraverse(BiTree T);
Status LevelOrderTraverse(BiTree T);
Status InitQueue(LinkQueue& Q);
Status EnQueue(LinkQueue& Q, BiTree q);
Status DeQueue(LinkQueue& Q, BiTree& q);
Status QueueEmpty(LinkQueue Q);
int Depth(BiTree T);
int LeadCount(BiTree T);
#pragma once

BiTree T = NULL;
//声明为全局变量！！！！！

int main() {
	int choose;
	int judge = 0;
	cout << "------------二叉树------------" << endl;
	cout << "1.创建二叉树" << endl;
	cout << "2.先序遍历二叉树" << endl;
	cout << "3.中序遍历二叉树" << endl;
	cout << "4.中序遍历二叉树(非递归方法)" << endl;
	cout << "5.后序遍历二叉树" << endl;
	cout << "6.层序遍历二叉树" << endl;
	cout << "7.求二叉树的深度" << endl;
	cout << "8.求二叉树中非叶子结点的个数" << endl;
	cout << "退出！！(输入一个负数)" << endl;
	cout << "请输入您的选择：" << endl;
	cin >> choose;
	while (judge == 0) {
		if (choose == 1) {
			judge++;
		}
		else {
			cout << "请先创建一棵树！！" << endl;
			cin >> choose;
		}
	}
	while (judge) {
		/*BiTree T = NULL;*/
		if (choose >= 1 && choose <= 8) {
			switch (choose) {
			case 1:
				CreateBiTree(T);
				break;
			case 2:
				cout<<"先序遍历为：" << endl;
				PreOrderTraverse(T);
				break;
			case 3:
				cout << "中序遍历为：" << endl;
				InOrderTraverse(T);
				break;
			case 4:
				cout << "非递归中序遍历为：" << endl;
				InOrderTraverseF(T);
				break;
			case 5:
				cout << "后序遍历为：" << endl;
				PostOrderTraverse(T);
				break;
			case 6:
				cout << "层序遍历为：" << endl;
				LevelOrderTraverse(T);
				break;
			case 7:
				cout<<"该树的深度为：" << Depth(T)<<endl;
				break;
			case 8:
				cout << "该树的叶子数为：" << LeadCount(T) << endl;
				break;
			}
		}
		else if (choose < 0) {
			return 0;
		}
		else {
			cout << "输入有误！！！" << endl;
		}
		cout << endl;
		cout << "请输入您的选择：" << endl;
		cin >> choose;
	}
}

Status CreateBiTree(BiTree& T) {
	char ch;
	//	ch = getchar(c);
	cout << "请输入根结点的值：" << endl;
	cin >> ch;
	if (ch == '#') {
		T = NULL;
	}
	else {
		T = new BiTNode;
		T->date = ch;
		cout << "进入左子树" << endl;
		CreateBiTree(T->LNode);
		cout << "进入右子树" << endl;
		CreateBiTree(T->RNode);
	}
	return TRUE;
}
void visit(BiTree T) {
	if (T) {
		cout << T->date << " ";
	}
}

Status PreOrderTraverse(BiTree T) {
	if (T == NULL) return TRUE;
	else {
		visit(T);
		PreOrderTraverse(T->LNode);
		PreOrderTraverse(T->RNode);
	}
}

Status InOrderTraverse(BiTree T) {
	if (T == NULL) {
		return TRUE;
	}
		
	else {
		InOrderTraverse(T->LNode);
		visit(T);
		InOrderTraverse(T->RNode);
	}
}

Status InitStack(SqStack& S) {
	S.base = new BiTNode[MAXSIZE];
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return TRUE;
}

Status StackEmpty(SqStack S) {
	if (S.base == S.top) return TRUE;
	return FALSE;
}

Status Push(SqStack& S, BiTree q) {
	if (S.base - S.top == S.stacksize) {
		return FALSE;
	}
	*(S.top) = *q;
	S.top++;
	return TRUE;
}
Status Pop(SqStack& S, BiTree& q) {
	if (S.base == S.top)
		return FALSE;
	S.top--;
	BiTree temp = S.top;
	q = temp;
	return TRUE;
}

Status InOrderTraverseF(BiTree T) {
	SqStack S;
	InitStack(S);
	BiTree current = T;
	while (current != NULL || !StackEmpty(S)) {
		while (current != NULL) {
			Push(S, current);
			current = current->LNode;
		}

		if (!StackEmpty(S)) {
			if (Pop(S, current)) {
				visit(current);
				current = current->RNode;
			}
		}
	}
	return TRUE;
	
}
//SqStack s;
	//InitStack(s);
	//Push(s, T);
	//while (T->LNode) {
	//	Push(s, T->LNode);
	//	T = T->LNode;
	//}

	//while (!StackEmpty(s)) {
	//	BiTree Node;
	//	Pop(s, Node);
	//	visit(Node);
	//	if (Node->RNode) {
	//		Node = Node->RNode;
	//		Push(s, Node);
	//		while (Node->LNode) {
	//			Node = Node->LNode;
	//			Push(s, Node);
	//		}
	//	}
	//}
	//return true;
void PostOrderTraverse(BiTree T) {
	if (T == NULL) return;
	else {
		PostOrderTraverse(T->LNode);
		PostOrderTraverse(T->RNode);
		visit(T);
	}
}

Status InitQueue(LinkQueue& Q) {
	Q.head = new QNode;
	Q.rear = Q.head;
	Q.head->next = NULL;
	return TRUE;
}

Status EnQueue(LinkQueue& Q, BiTree q) {
	QNode* p = new QNode;
	p->date = q;
	Q.rear->next = p;
	Q.rear = p;
	p->next = NULL;
	return TRUE;
}

Status DeQueue(LinkQueue& Q, BiTree& p) {
	QNode* q;
	q = Q.head->next;
	if (Q.rear == q) {
		Q.rear = Q.head;
	}
	if (QueueEmpty(Q)) {
		return FALSE;
	}
	else {
		QNode* q;
		q = Q.head->next;
		p = q->date;
		Q.head->next = q->next;
	}
	delete q;
	//	if(Q.rear == q){
	//		Q.rear = Q.head;
	//	}
	//	free(q);
	//c中是free（），c++是delete 
	return TRUE;
}

Status QueueEmpty(LinkQueue Q) {
	if (Q.head->next == NULL) return TRUE;
	return FALSE;
}


Status LevelOrderTraverse(BiTree T) {
	if (T == NULL) return TRUE;
	LinkQueue Q;
	InitQueue(Q);
	EnQueue(Q, T);
	BiTree p;
	while (!QueueEmpty(Q)) {
		if (DeQueue(Q, p)) {
			cout << p->date << " ";
		}
		if (p->LNode != NULL) {
			EnQueue(Q, p->LNode);
		}
		if (p->RNode != NULL) {
			EnQueue(Q, p->RNode);
		}
	}
	return TRUE;
}

int Depth(BiTree T) {
	if (T == NULL) return 0;
	return Depth(T->LNode) > Depth(T->RNode) ? Depth(T->LNode)+1 : Depth(T->RNode)+1;
}

int LeadCount(BiTree T) {
	if (T == NULL) return 0;
	if (LeadCount(T->LNode) == NULL && LeadCount(T->RNode) == NULL)
		return 1;
	else return LeadCount(T->LNode) + LeadCount(T->RNode);
}