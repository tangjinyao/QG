/***************************************************************************************
 *	File Name				:	DbLinkedList.h
 *	CopyRight				:	2020 QG Studio
 *	SYSTEM					:   win10
 *	Create Data				:	2020.3.28
 *
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 *
 ***************************************************************************************/

 /**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/
#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

/**************************************************************
*	Macro Define Section
**************************************************************/

#define OVERFLOW -1

/**************************************************************
*	Struct Define Section
**************************************************************/

// define element type
typedef int ElemType;

// define struct of linked list
typedef struct LNode {
	ElemType data;
	struct LNode* pre;
	struct LNode* next;
} LNode, * LinkedList;

// define Status
typedef enum Status {
	ERROR,
	SUCCESS
} Status;


/**************************************************************
*	Prototype Declare Section
**************************************************************/

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList* L);

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList* L);

/**
 *  @name        : Status InsertList(LNode* L, ElemType p, LNode* q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status insertBeforeNode(LNode* L, ElemType p, LNode* q);

/**
 *  @name        : Status InsertList(LNode* L, ElemType p, LNode* q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status insertAfterNode(LNode* L, ElemType p, LNode* q);

/**
 *  @name        : Status DeleteList(LNode *L, ElemType p)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode* L, ElemType p);

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e));

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e);



/**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif
