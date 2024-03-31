
#ifndef LINKSTACKTOOL_H_INCLUDE
#define LINKSTACKTOOL_H_INCLUDE

#define MAXSIZE 200000

typedef enum Status
{
	ERROR = 0,
	SUCCESS = 1
} Status;

typedef int ElemType;

typedef  struct StackNode
{
	ElemType begin;
	ElemType end;
	struct StackNode* next;
}StackNode, * LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;

//链栈
Status initLStack(LinkStack** s);//初始化栈
Status pushLStack(LinkStack* s, ElemType begin, ElemType end);//入栈
Status popLStack(LinkStack* s, ElemType* begin, ElemType* end);//出栈

#endif // !LINKSTACKTOOL_H_INCLUDE
