#pragma once
typedef char LinkType;
typedef struct LinkNode{
	LinkType data;
	struct LinkNode* next;
}LinkNode;

void LinkListInit(LinkNode** phead);//初始化链表

void LinkListDestroy(LinkNode** phead);//销毁链表

void LinkListPrintChar(LinkNode* head,const char* msg);//打印链表

void LinkListPushBack(LinkNode** phead, LinkType value);//尾插 

void LinkListPopBack(LinkNode** phead);//尾删 

void LinkListPushFront(LinkNode** phead, LinkType value); //头插

void LinkListPopFront(LinkNode** phead); //头删

LinkNode* LinkListFind(LinkNode* head, LinkType to_find);//查找元素地址 

void LinkListInsert(LinkNode** head, LinkNode* pos, LinkType value);//pos前插入

void LinkListInsertAfter(LinkNode* pos, LinkType value); //pos后插入

void LinkListErase(LinkNode** phead, LinkNode* pos); //删除指定地址的元素

void LinkListRemove(LinkNode** phead, LinkType to_delete); //删除指定值的元素

void LinkListRemoveAll(LinkNode** phead, LinkType value); //指定值的所有元素都删掉

int LinkListEmpty(LinkNode* phead); // 判定链表为空 

size_t LinkListSize(LinkNode* phead); //求链表的元素个数 

//以下为面试题
void LinkListReversePrint(LinkNode* phead); //逆序打印单链表

void LinkListInsert2(LinkNode** phead, LinkNode* pos, LinkType value);//不允许遍历链表, 在 pos之前插入 

void LinkListErase2(LinkNode** phead, LinkNode* pos);//删除一个无头单链表的非尾结点（不遍历） 

LinkNode* JosephCycle(LinkNode* head, size_t food); //实现约瑟芬环

void LinkListReverse(LinkNode** head); //逆置单链表
void LinkListReverse2(LinkNode** head); 

