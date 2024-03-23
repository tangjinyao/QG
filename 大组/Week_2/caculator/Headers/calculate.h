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

//链栈
Status initLStack(LinkStack** s);//初始化栈
Status isEmptyLStack(LinkStack* s);//判断栈是否为空
Status getTopLStack(LinkStack* s, ElemType* e);//得到栈顶元素
Status pushLStack(LinkStack* s, ElemType data);//入栈
Status popLStack(LinkStack* s, ElemType* data);//出栈

Status pushLStack2(LinkStack2* s, double data);//入栈
Status popLStack2(LinkStack2* s, double* data);//出栈


#endif 