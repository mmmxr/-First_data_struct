#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"
#define TEST_HEADER printf("\n=================%s================\n",__FUNCTION__)
////////////////////////////////
//以下为实现函数
////////////////////////////////
///////////////////////////////
LinkNode* CreatNode(LinkType value)
{
	LinkNode* new_node=(LinkNode*)malloc(sizeof(LinkNode));
	new_node->data=value;
	new_node->next=NULL;
	return new_node;
}
void DestroyNode(LinkNode* head)
{
	free(head);
}
void LinkListInit(LinkNode** phead)
{
	if(phead==NULL)
	{
		return;
		//非法输入
	}
	*phead=NULL;
}

void LinkListDestroy(LinkNode** phead)
{
	//TODO
}

void LinkListPushBack(LinkNode** phead, LinkType value)
{
	if(phead==NULL)
	{
		return;
	}
	if(*phead==NULL)
	{
		//空链表
		LinkNode* new_node=CreatNode(value);
		*phead=new_node;
		return;
	}
	//链表非空的情况
	LinkNode* cur=*phead;
	while(cur->next!=NULL)
	{
		cur=cur->next;
	}
	LinkNode* new_node=CreatNode(value);
	cur->next=new_node;
}
void LinkListPopBack(LinkNode** phead)
{
	if(phead==NULL)
	{
		return;
	}
	if(*phead==NULL)
	{
		//空链表无法删除
		return;
	}
	if((*phead)->next==NULL)
	{
		DestroyNode(*phead);
		*phead=NULL;
		return;
	}
	LinkNode* cur=*phead;
	LinkNode* pre=NULL;
	while(cur->next!=NULL)
	{
		pre=cur;
		cur=cur->next;
	}
	DestroyNode(cur);
	pre->next=NULL;

}

void LinkListPushFront(LinkNode** phead, LinkType value)
{
	if(phead==NULL)
	{
		return;
	}
	LinkNode* new_node=CreatNode(value);
	new_node->next=*phead;
	*phead=new_node;
}

void LinkListPopFront(LinkNode** phead)
{
	if(phead==NULL)
	{
		return;
	}
	LinkNode* cur=*phead;
	*phead=(*phead)->next;
	DestroyNode(cur);
}

LinkNode* LinkListFind(LinkNode* head, LinkType to_find)
{
	if(head==NULL)
	{
		return NULL;
	}
	LinkNode* cur=head;
	for(;cur!=NULL;cur=cur->next)
	{
		if(cur->data==to_find)	
		{
			return cur;
		}
	}
	return NULL;
}

void LinkListInsert(LinkNode** phead, LinkNode* pos, LinkType value)
{
	if(phead==NULL||pos==NULL)
	{
		return;
	}
	if(*phead==pos)
	{
		LinkListPushFront(phead,value);
		return;
	}
	LinkNode* cur=*phead;
	while(cur!=NULL)
	{
		//printf("进入此\n");
		if(cur->next==pos)
		{
			LinkNode* new_node=CreatNode(value);
			cur->next=new_node;
			new_node->next=pos;
			return;
		}
		cur=cur->next;
	}
}
void LinkListInsertAfter(LinkNode* pos, LinkType value)
{
	if(pos==NULL)
	{
		return;
	}
	LinkNode* new_node=CreatNode(value);
	new_node->next=pos->next;
	pos->next=new_node;
}

void LinkListErase(LinkNode** phead, LinkNode* pos)
{
	if(phead==NULL||pos==NULL)
	{
		return;
	}
	if(*phead==NULL)
	{
		return;//空链表
	}
	if(*phead==pos)
	{
		LinkListPopFront(phead);
		return;
	}
	LinkNode* cur=*phead;
	while(cur!=NULL)
	{
		if(cur->next==pos)
			break;
		cur=cur->next;
	}
	if(cur->next==NULL)
	{
		return;
	}
	cur->next=pos->next;
	DestroyNode(pos);
}



void LinkListRemove(LinkNode** phead, LinkType to_delete)
{
	if(phead==NULL)
	{
		return;
	}
	if(*phead==NULL)
	{
		return;//空链表
	}
	LinkNode* pos=NULL;
	pos=LinkListFind(*phead,to_delete);
	LinkListErase(phead,pos);
		
}
void LinkListRemoveAll(LinkNode** phead, LinkType value)
{
	if(phead==NULL)
	{
		return;
	}
	if(*phead==NULL)
	{
		return;
	}
	LinkNode* cur=NULL;
    while(1)
    {
     cur=LinkListFind(*phead,value);
        if(cur==NULL)
        {
            return;
        }
        LinkListErase(phead,cur);
    }
}
int LinkListEmpty(LinkNode* head)
{
	if(head==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

size_t LinkListSize(LinkNode* head)
{
	size_t count=0;
	LinkNode* cur=head;
	for(;cur!=NULL;cur=cur->next)
	{
		count++;
	}
	return count;
}


void LinkListPrintChar(LinkNode* head,const char* msg)
{
	printf("%s\n",msg);
	LinkNode* cur=head;
	for(;cur!=NULL;cur=cur->next)
	{
		printf("[%c|%p] ",cur->data,cur);
	}
	printf("\n");
}
///////////////////////////////
//以下为面试题
///////////////////////////////

void LinkListReversePrint(LinkNode* head)
{
	if(head==NULL)
	{
		return;
	}
	if(head==NULL)
	{
		return;
	}
	LinkListReversePrint(head->next);
	printf("[%c|%p] ",head->data,head);
}
void LinkListErase2(LinkNode** phead, LinkNode* pos)
{
	if(phead==NULL)
	{
		return;
	}
	if(*phead==NULL)
	{
		return;
	}
	LinkNode* to_destroy=pos->next;
	pos->data=pos->next->data;
	pos->next=pos->next->next;
	DestroyNode(to_destroy);

}

void LinkListInsert2(LinkNode** phead, LinkNode* pos, LinkType value)
{
	if(phead==NULL)
	{
		return;
	}
	LinkListInsertAfter(pos,value);
	LinkType tmp=pos->data;
	pos->data=pos->next->data;
	pos->next->data=tmp;
}

LinkNode* JosephCycle(LinkNode* head, size_t food) //实现约瑟芬环
{
    if(head==NULL)
    {
        return NULL;//空链表
    }
    size_t count=0;
    LinkNode* cur=head;
    LinkNode* tmp=NULL;
    while(cur->next!=cur)
    {
        count++;
        tmp=cur;
        cur=cur->next;
        if(count==food)
        {
            printf("[%c]\n",tmp->data);
            //DestroyNode(tmp);
            LinkListErase2(&tmp,tmp);

            count=0;
        }
    }
    return  cur;
}

void LinkListReverse(LinkNode** phead)
{
    if(phead==NULL)
    {
        return;
    }
    if((*phead)->next==NULL)
    {
        return;
    }
    LinkNode* cur=*phead;
    LinkNode* to_delete=NULL;
    while(cur->next!=NULL)
    {
         to_delete=cur->next;
         cur->next=to_delete->next;
         LinkListPushFront(phead,to_delete->data);
    }
}
//////////////////////////////////
//以下为面试题测试函数
//////////////////////////////////
void TestReverse()
{
    TEST_HEADER;
	LinkNode* head;
	LinkListInit(&head);
	LinkListPushBack(&head,'a');
	LinkListPushBack(&head,'b');
	LinkListPushBack(&head,'c');
	LinkListPushBack(&head,'d');
	LinkListPushBack(&head,'e');
	LinkListPushBack(&head,'f');
	LinkListPrintChar(head,"当前链表\n");
    LinkListReverse(&head);
	LinkListPrintChar(head,"逆置链表\n");

}
void TestJosephCircle()
{
    TEST_HEADER;
    LinkNode* a=CreatNode('a'); 
    LinkNode* b=CreatNode('b'); 
    LinkNode* c=CreatNode('c'); 
    LinkNode* d=CreatNode('d'); 
    LinkNode* e=CreatNode('e'); 
    LinkNode* f=CreatNode('f'); 
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    e->next=f;
    f->next=a;
    LinkNode* survive=JosephCycle(a,5);
    printf("survive is %c\n",survive->data);

}
void TestReversePrint()
{
	TEST_HEADER;
	LinkNode* head;
	LinkListInit(&head);
	LinkListPushFront(&head,'a');
	LinkListPushFront(&head,'b');
	LinkListPushFront(&head,'c');
	LinkListPushFront(&head,'d');
	LinkListPushFront(&head,'e');
	LinkListPushFront(&head,'f');
	LinkListPrintChar(head,"当前链表\n");
	printf("逆序打印单链表\n");
	LinkListReversePrint(head);
	printf("\n");
}
void TestErase2()
{	
	TEST_HEADER;
	LinkNode* head;
	LinkListInit(&head);
	LinkListPushFront(&head,'a');
	LinkListPushFront(&head,'b');
	LinkListPushFront(&head,'c');
	LinkListPushFront(&head,'d');
	LinkListPushFront(&head,'e');
	LinkListPrintChar(head,"当前链表\n");
	LinkListErase2(&head,head->next);
	LinkListPrintChar(head,"删除d\n");
	LinkListErase2(&head,head->next->next);
	LinkListPrintChar(head,"删除b\n");
	LinkListErase2(&head,head);
	LinkListPrintChar(head,"删除e\n");
}
void TestInsert2()
{
	TEST_HEADER;
	LinkNode* head;
	LinkListInit(&head);
	LinkListPushFront(&head,'a');
	LinkListPrintChar(head,"当前链表\n");
	LinkListInsert2(&head,head,'x');
	LinkListPrintChar(head,"在a前面插入x\n");
	LinkListPushFront(&head,'b');
	LinkListPushFront(&head,'c');
	LinkListPushFront(&head,'d');
	LinkListPushFront(&head,'e');
	LinkListPrintChar(head,"当前链表\n");
	LinkListInsert2(&head,head->next->next,'y');
	LinkListPrintChar(head,"在c前面插入y\n");


}

//////////////////////////////
//以下为测试函数
/////////////////////////////

void TestInit()
{
	TEST_HEADER;
	LinkNode* head;
	LinkListInit(&head);
	LinkListPrintChar(head,"初始化链表\n");
}
void TestPushBack()
{
	TEST_HEADER;
	LinkNode* head;
	LinkListInit(&head);
	LinkListPushBack(&head,'a');
	LinkListPrintChar(head,"对空链表尾插\n");
	LinkListPushBack(&head,'b');
	LinkListPushBack(&head,'c');
	LinkListPushBack(&head,'d');
	LinkListPushBack(&head,'e');
	LinkListPrintChar(head,"尾插五个元素\n");
}
void TestPopBack()
{
	TEST_HEADER;
	LinkNode* head;
	LinkListInit(&head);
	LinkListPushBack(&head,'a');
	LinkListPushBack(&head,'b');
	LinkListPushBack(&head,'c');
	LinkListPushBack(&head,'d');
	LinkListPushBack(&head,'e');
	LinkListPrintChar(head,"当前链表\n");
	LinkListPopBack(&head);
	LinkListPopBack(&head);
	LinkListPrintChar(head,"尾删两个元素\n");
}
void TsetPushFront()
{
	TEST_HEADER;
	LinkNode* head;
	LinkListInit(&head);
	LinkListPushFront(&head,'a');
	LinkListPrintChar(head,"对空链表头插一个元素\n");
	LinkListPushFront(&head,'b');
	LinkListPushFront(&head,'c');
	LinkListPushFront(&head,'d');
	LinkListPushFront(&head,'e');
	LinkListPrintChar(head,"头插五个元素\n");
}
void TestPushFront()
{
	TEST_HEADER;
	LinkNode* head;
	LinkListInit(&head);
	LinkListPushFront(&head,'a');
	LinkListPushFront(&head,'b');
	LinkListPushFront(&head,'c');
	LinkListPushFront(&head,'d');
	LinkListPushFront(&head,'e');
	LinkListPrintChar(head,"当前链表\n");
	LinkListPopFront(&head);
	LinkListPopFront(&head);
	LinkListPopFront(&head);
	LinkListPrintChar(head,"头删三个元素\n");
}
void TestFind()
{
	TEST_HEADER;
	LinkNode* head;
	LinkNode* pos;
	LinkListInit(&head);
	LinkListPushFront(&head,'a');
	LinkListPushFront(&head,'b');
	LinkListPushFront(&head,'c');
	LinkListPushFront(&head,'d');
	LinkListPushFront(&head,'e');
	LinkListPrintChar(head,"当前链表\n");
	pos=LinkListFind(head,'a');
	printf("[a]:%p\n",pos);
	pos=LinkListFind(head,'e');
	printf("[e]:%p\n",pos);
	pos=LinkListFind(head,'x');
	printf("[x]:%p\n",pos);
}
void TestListInsert()
{
	TEST_HEADER;
	LinkNode* head;
	LinkListInit(&head);
	LinkListPushFront(&head,'a');
	LinkListPrintChar(head,"当前链表\n");
	LinkListInsert(&head,head,'x');
	LinkListPrintChar(head,"在a前面插入x\n");
	LinkListPushFront(&head,'b');
	LinkListPushFront(&head,'c');
	LinkListPushFront(&head,'d');
	LinkListPushFront(&head,'e');
	LinkListPrintChar(head,"当前链表\n");
	LinkListInsert(&head,head->next->next,'y');
	LinkListPrintChar(head,"在c前面插入y\n");
}
void TestInsertAfter()
{
	TEST_HEADER;
	LinkNode* head;
	LinkListInit(&head);
	LinkListPushFront(&head,'a');
	LinkListPrintChar(head,"当前链表\n");
	LinkListInsertAfter(head,'x');
	LinkListPrintChar(head,"在a后面插入x\n");
	LinkListPushFront(&head,'b');
	LinkListPushFront(&head,'c');
	LinkListPushFront(&head,'d');
	LinkListPushFront(&head,'e');
	LinkListPrintChar(head,"当前链表\n");
	LinkListInsertAfter(head->next->next,'y');
	LinkListPrintChar(head,"在c后面插入y\n");
}
void TestErase()
{	
	TEST_HEADER;
	LinkNode* head;
	LinkListInit(&head);
	LinkListPushFront(&head,'a');
	LinkListPushFront(&head,'b');
	LinkListPushFront(&head,'c');
	LinkListPushFront(&head,'d');
	LinkListPushFront(&head,'e');
	LinkListPrintChar(head,"当前链表\n");
	LinkListErase(&head,head->next);
	LinkListPrintChar(head,"删除d\n");
	LinkListErase(&head,head->next->next);
	LinkListPrintChar(head,"删除b\n");
	LinkListErase(&head,head);
	LinkListPrintChar(head,"删除e\n");
}
void TestEmpty()
{
	TEST_HEADER;
	LinkNode* head;
	int count;
	LinkListInit(&head);
	count=LinkListEmpty(head);
	printf("空链表expect 1,actual %d\n",count);
	LinkListPushFront(&head,'a');
	LinkListPushFront(&head,'b');
	LinkListPushFront(&head,'c');
	LinkListPushFront(&head,'d');
	LinkListPushFront(&head,'e');
	LinkListPrintChar(head,"当前链表\n");
	count=LinkListEmpty(head);
	printf("非空链表expect 0,actual %d\n",count);
}
void TestSize()
{
	TEST_HEADER;
	LinkNode* head;
	int count;
	LinkListInit(&head);
	count=LinkListSize(head);
	printf("空链表size:expect 0,actual %d\n",count);
	LinkListPushFront(&head,'a');
	LinkListPushFront(&head,'b');
	LinkListPushFront(&head,'c');
	LinkListPushFront(&head,'d');
	LinkListPushFront(&head,'e');
	LinkListPrintChar(head,"当前链表\n");
	count=LinkListSize(head);
	printf("非空链表size:expect 5,actual %d\n",count);
}
void TestRemove()
{
	TEST_HEADER;
	LinkNode* head;
	LinkListInit(&head);
	LinkListPushFront(&head,'a');
	LinkListPushFront(&head,'b');
	LinkListPushFront(&head,'c');
	LinkListPushFront(&head,'d');
	LinkListPushFront(&head,'e');
	LinkListPrintChar(head,"当前链表\n");
	LinkListRemove(&head,'a');
	LinkListPrintChar(head,"删除a\n");
	LinkListRemove(&head,'e');
	LinkListPrintChar(head,"删除e\n");
}
void TestRemoveAll()
{
	TEST_HEADER;
	LinkNode* head;
	LinkListInit(&head);
	LinkListPushFront(&head,'a');
	LinkListPushFront(&head,'b');
	LinkListPushFront(&head,'a');
	LinkListPushFront(&head,'b');
	LinkListPushFront(&head,'c');
	LinkListPushFront(&head,'d');
	LinkListPrintChar(head,"当前链表\n");
	LinkListRemoveAll(&head,'b');
	LinkListPrintChar(head,"删除b\n");
	//LinkListRemoveAll(&head,'e');
	//LinkListPrintChar(head,"删除e\n");
}

int main()
{
	TestInit();
	TestPushBack();
	TestPopBack();
	TsetPushFront();
	TestPushFront();
	TestFind();
	TestListInsert();
	TestInsert2();
	TestInsertAfter();
	TestErase();
	TestErase2();
	TestEmpty();
	TestSize();
	TestRemove();
	TestRemoveAll();
	TestReversePrint();
    TestJosephCircle();
    TestReverse();
	return 0;
}
