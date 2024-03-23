#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#define MAXSIZE 20

typedef enum Status
{
	ERROR = 0,
	SUCCESS = 1
} Status;

typedef char ElemType;

typedef  struct StackNode
{
	ElemType data;
	struct StackNode* next;
}StackNode, * LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;

typedef  struct StackNode2
{
	double data;
	struct StackNode* next;
}StackNode2, * LinkStackPtr2;

typedef  struct  LinkStack2
{
	LinkStackPtr2 top;
	int	count;
}LinkStack2;

//��ջ
Status initLStack(LinkStack** s);//��ʼ��ջ
Status isEmptyLStack(LinkStack* s);//�ж�ջ�Ƿ�Ϊ��
Status getTopLStack(LinkStack* s, ElemType* e);//�õ�ջ��Ԫ��
Status pushLStack(LinkStack* s, ElemType data);//��ջ
Status popLStack(LinkStack* s, ElemType* data);//��ջ

Status pushLStack2(LinkStack2* s, double data);//��ջ
Status popLStack2(LinkStack2* s, double* data);//��ջ


#endif 