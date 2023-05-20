#include<stdio.h>
#include<malloc.h>
#include<stdio.h>
struct Node {
	int data;
	struct Node* next;
};
struct Node *Creat_headNode() {//创建头结点，结构体函数。
	struct Node *head;
	head = malloc(sizeof(struct Node));
	if (!head)
		head = 1;
	head->data = 0;
	head->next = NULL;
	return head;
};
void print_list(struct Node *phead)
{
	struct Node *p = phead;
	while (p)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
}
void create_node(struct Node* HeadNode);//直接在链表尾部创建一个新节点
void delete_node(struct Node* head, int flag);
void clear_list(struct Node** pphead);
struct Node* Creat_singleNode(int x);//创建一个单结点，并作为函数返回值
void Insert_node(struct Node* Head);
void search_node(struct Node* Head);
void delete_data(struct Node* Head);
int main()
{
	struct Node* node1 = NULL;
	struct Node node2 = { 25,NULL };
	struct Node node3 = { 30,NULL };
	struct Node *Head=Creat_headNode();
	print_list(Head);
	create_node(Head);
	create_node(Head);
	create_node(Head);
	//delete_node(Head, 4);
	print_list(Head);
	Insert_node(Head);
	print_list(Head);
	//search_node(Head);

	delete_data(Head);
	print_list(Head);

	return 0;
}
void create_node(struct Node* HeadNode)
{
	struct Node* p = HeadNode;
	struct Node* newnode = malloc(sizeof(struct Node));
	if (!newnode)
		newnode = 1;
	printf("请输入新结点的data:");
	scanf_s("%d", &newnode->data);
	while (p->next!=NULL)
	{
		p = p->next;
	}
	p->next = newnode;
	newnode->next = NULL;
	//
}
void delete_node(struct Node* head, int flag)//删除指定位次的结点
{
	struct Node *p = head,*cur=head;
	for (int i = 1; i < flag-1; i++)
	{
		p = p->next;
	}
	if (p == NULL )
		printf("this flag is error!\n");
/*	else if (p->next == NULL)
	{
		free(p);
	}*/
	else
	{
		cur = p->next;
		p->next=cur->next;
		free(cur);
	}

}
void clear_list(struct Node** pphead)//传递头指针的地址，这样才能改变头指针。
{
	struct Node* p = *pphead,*cur=NULL;
	while (p)
	{
		cur = p->next;
		free(p);
		p = cur;
	}
	*pphead = NULL;
}
void delete_data(struct Node* Head);//删除指定数值的结点
struct Node* Creat_singleNode(int x)
{
	struct Node* newnode = malloc(sizeof(struct Node));
	if (!newnode)
		newnode = 1;
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
void Insert_node(struct Node* Head)
{
	int x, flag;
	printf("请输入想要插入的新结点的data值：");
	scanf_s("%d", &x);
	printf("请输入结点插入的位次：");
	scanf_s("%d", &flag);
	struct Node* newnode = Creat_singleNode(x);
	struct Node* p = Head;
	for (int i = 1; i < flag - 1; i++)
	{
		p = p->next;
	}
	struct Node* cur = p -> next;
	p->next = newnode;
	newnode->next = cur;
}
void search_node(struct Node* Head)
{
	int x,i=1;
	struct Node* p = Head;
	printf("请输入要寻找的值：");
	scanf_s("%d", &x);
	while (p)
	{
		if (p->data == x)
			break;
		p = p->next;
		i++;
	}
	if (!p)
		printf("你要找的数据不存在！");
	else
		printf("你要找的数据在第%d个", i);
}
void delete_data(struct Node* Head)
{
	struct Node* p=Head, * cur=p->next;
	if (!cur)
		cur = 1;

	int x;
	printf("请输入你要删除的数据：");
	scanf_s("%d", &x);
	while (p)
	{
		cur = p->next;
		if (!cur)
			break;
		if (cur->data==x)
		{
			if (cur->next == NULL)
			{
				p->next = NULL;
				free(cur);
			}
			else
			{
				p->next = cur->next;
				free(cur);
			}
		}
		p = p->next;
	}
}