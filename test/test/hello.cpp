
#include <stdlib.h> 
#include <cstdlib>
#include <iostream> 


using namespace std;

#define MAXSIZE 100
#define TRUE 1
#define FALSE 0
//ABC$$DE$G$$F$$$
typedef char TElemType;
typedef int Status;
//typedef Ҫ��; 

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

Status InitBiTree(BiTree& T);
Status InitStack(SqStack& S);
Status StackEmpty(SqStack S);
Status Pop(SqStack& S, BiTree q);
Status Push(SqStack& S, BiTree &q);
Status CreateBiTree(BiTree& T);
void visit(BiTree T);
Status PreOrderTraverse(BiTree T);
Status InOrderTraverse(BiTree T);
Status InOrderTraverseF(BiTree T);
Status PostOrderTraverse(BiTree T);
Status LevelOrderTraverse(BiTree T);
Status InitQueue(LinkQueue& Q);
Status EnQueue(LinkQueue& Q, BiTree q);
Status DeQueue(LinkQueue& Q, BiTree& q);
Status QueueEmpty(LinkQueue Q);

int main() {
	BiTree T;
	int choose;
	int judge = 0;
	cout << "------------������------------" << endl;
	cout << "1.����������" << endl;
	cout << "2.�������������" << endl;
	cout << "3.�������������" << endl;
	cout << "4.�������������(�ǵݹ鷽��)" << endl;
	cout << "5.�������������" << endl;
	cout << "6.�������������" << endl;
	cout << "7.������������" << endl;
	cout << "8.��������з�Ҷ�ӽ��ĸ���" << endl;
	cout << "�˳�����(����һ������)" << endl;
	cout << "����������ѡ��" << endl;
	cin >> choose;
	while (judge == 0) {
		if (choose == 1) {
			judge++;
		}
		else {
			cout << "���ȴ���һ��������" << endl;
			cin >> choose;
		}
	}
	while (judge) {
		if (choose >= 1 && choose <= 7) {
			switch (choose) {
			case 1:
				CreateBiTree(T);
				break;
			case 2:
				PreOrderTraverse(T);
				break;
			case 3:
				InOrderTraverse(T);
				break;
			case 4:
				InOrderTraverseF(T);
				break;
			case 5:
				PostOrderTraverse(T);
				break;
			case 6:
				LevelOrderTraverse(T);
				break;
			case 7:
				break;
			case 8:
				break;
			}
		}
		else if (choose < 0) {
			return 0;
		}
		else {
			cout << "�������󣡣���" << endl;
		}
		cout << endl;
		cout << "����������ѡ��" << endl;
		cin >> choose;
	}
}

//Status InitBiTree(BiTree &T){
//	//���� C++ �У����Ƽ�ʹ�� new �ؼ��������ж�̬�ڴ���䣬������ malloc
//	T = new BiTNode;
//	T->LNode = NULL;
//	T->RNode =NULL;
//	//ָ����-> �ṹ����. 
//	return TRUE;
//}

Status InitStack(SqStack& S) {
	S.base = new BiTNode[MAXSIZE];
	S.base = S.top;
	S.stacksize = MAXSIZE;
	return TRUE;
}

Status StackEmpty(SqStack S) {
	if (S.base == S.top) return TRUE;
	return FALSE;
}

Status Push(SqStack& S, BiTree q) {
	S.top = q;
	S.top++;
	return TRUE;
}
Status Pop(SqStack &S, BiTree& q) {
	if (S.base == S.top) {
		return FALSE;
	}
	--S.top = q;
	return TRUE;
}

Status InitQueue(LinkQueue& Q) {
	Q.head = new QNode;
	Q.rear = Q.head;
	Q.head->next = NULL;
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
	//c����free������c++��delete 
	return TRUE;
}

Status QueueEmpty(LinkQueue Q) {
	if (Q.head->next == NULL) return TRUE;
	return FALSE;
}


Status CreateBiTree(BiTree& T) {
	char ch;
	//	ch = getchar(c);
	cout << "�����������ֵ��" << endl;
	cin >> ch;
	if (ch == '#') {
		T = NULL;
	}
	else {
		T = new BiTNode;
		T->date = ch;
		cout << "����������" << endl;
		CreateBiTree(T->LNode);
		cout << "����������" << endl;
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
	if (T == NULL) return TRUE;
	else {
		InOrderTraverse(T->LNode);
		visit(T);
		InOrderTraverse(T->RNode);
	}
}

Status InOrderTraverseF(BiTree T) {
	if (T == NULL) return TRUE;
	else {
		SqStack S;
		BiTree q;
		q = T;
		InitStack(S);
		Pop(S, q);
		while (StackEmpty(S) == FALSE) {
			if (q->LNode != NULL) {
				Push(S, q->LNode);
				q = q->LNode;
			}
			else {
				Pop(S, q);
				Push(S, q->RNode);
				cout << q->date << " ";
			}
		}
	}
}

Status PostOrderTraverse(BiTree T) {
	if (T == NULL) return TRUE;
	else {
		PostOrderTraverse(T->LNode);
		PostOrderTraverse(T->RNode);
		visit(T);
	}
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




















using namespace std;

#define MAXSIZE 100
#define TRUE 1
#define FALSE 0
//ABC$$DE$G$$F$$$
typedef char TElemType;
typedef int Status;
//typedef Ҫ��; 

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

Status InitBiTree(BiTree& T);
Status InitStack(SqStack& S);
Status StackEmpty(SqStack S);
Status Pop(SqStack& S, BiTree q);
Status Push(SqStack& S, BiTree& q);
Status CreateBiTree(BiTree& T);
void visit(BiTree T);
Status PreOrderTraverse(BiTree T);
Status InOrderTraverse(BiTree T);
Status InOrderTraverseF(BiTree T);
Status PostOrderTraverse(BiTree T);
Status LevelOrderTraverse(BiTree T);
Status InitQueue(LinkQueue& Q);
Status EnQueue(LinkQueue& Q, BiTree q);
Status DeQueue(LinkQueue& Q, BiTree& q);
Status QueueEmpty(LinkQueue Q);

int main() {
	BiTree T;
	int choose;
	int judge = 0;
	cout << "------------������------------" << endl;
	cout << "1.����������" << endl;
	cout << "2.�������������" << endl;
	cout << "3.�������������" << endl;
	cout << "4.�������������(�ǵݹ鷽��)" << endl;
	cout << "5.�������������" << endl;
	cout << "6.�������������" << endl;
	cout << "7.������������" << endl;
	cout << "8.��������з�Ҷ�ӽ��ĸ���" << endl;
	cout << "�˳�����(����һ������)" << endl;
	cout << "����������ѡ��" << endl;
	cin >> choose;
	while (judge == 0) {
		if (choose == 1) {
			judge++;
		}
		else {
			cout << "���ȴ���һ��������" << endl;
			cin >> choose;
		}
	}
	while (judge) {
		if (choose >= 1 && choose <= 7) {
			switch (choose) {
			case 1:
				CreateBiTree(T);
				break;
			case 2:
				PreOrderTraverse(T);
				break;
			case 3:
				InOrderTraverse(T);
				break;
			case 4:
				InOrderTraverseF(T);
				break;
			case 5:
				PostOrderTraverse(T);
				break;
			case 6:
				LevelOrderTraverse(T);
				break;
			case 7:
				break;
			case 8:
				break;
			}
		}
		else if (choose < 0) {
			return 0;
		}
		else {
			cout << "�������󣡣���" << endl;
		}
		cout << endl;
		cout << "����������ѡ��" << endl;
		cin >> choose;
	}
}

//Status InitBiTree(BiTree &T){
//	//���� C++ �У����Ƽ�ʹ�� new �ؼ��������ж�̬�ڴ���䣬������ malloc
//	T = new BiTNode;
//	T->LNode = NULL;
//	T->RNode =NULL;
//	//ָ����-> �ṹ����. 
//	return TRUE;
//}

Status InitStack(SqStack& S) {
	S.base = new BiTNode[MAXSIZE];
	S.base = S.top;
	S.stacksize = MAXSIZE;
	return TRUE;
}

Status StackEmpty(SqStack S) {
	if (S.base == S.top) return TRUE;
	return FALSE;
}

Status Push(SqStack& S, BiTree q) {
	S.top = q;
	S.top++;
	return TRUE;
}
Status Pop(SqStack& S, BiTree& q) {
	if (S.base == S.top) {
		return FALSE;
	}
	--S.top = q;
	return TRUE;
}

Status InitQueue(LinkQueue& Q) {
	Q.head = new QNode;
	Q.rear = Q.head;
	Q.head->next = NULL;
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
	//c����free������c++��delete 
	return TRUE;
}

Status QueueEmpty(LinkQueue Q) {
	if (Q.head->next == NULL) return TRUE;
	return FALSE;
}


Status CreateBiTree(BiTree& T) {
	char ch;
	//	ch = getchar(c);
	cout << "�����������ֵ��" << endl;
	cin >> ch;
	if (ch == '#') {
		T = NULL;
	}
	else {
		T = new BiTNode;
		T->date = ch;
		cout << "����������" << endl;
		CreateBiTree(T->LNode);
		cout << "����������" << endl;
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
	if (T == NULL) return TRUE;
	else {
		InOrderTraverse(T->LNode);
		visit(T);
		InOrderTraverse(T->RNode);
	}
}

Status InOrderTraverseF(BiTree T) {
	if (T == NULL) return TRUE;
	else {
		SqStack S;
		BiTree q;
		q = T;
		InitStack(S);
		Pop(S, q);
		while (StackEmpty(S) == FALSE) {
			if (q->LNode != NULL) {
				Push(S, q->LNode);
				q = q->LNode;
			}
			else {
				Pop(S, q);
				Push(S, q->RNode);
				cout << q->date << " ";
			}
		}
	}
}

Status PostOrderTraverse(BiTree T) {
	if (T == NULL) return TRUE;
	else {
		PostOrderTraverse(T->LNode);
		PostOrderTraverse(T->RNode);
		visit(T);
	}
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



















