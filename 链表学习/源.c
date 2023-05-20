#include<stdio.h>
#include<malloc.h>
#include<stdio.h>
struct Node {
	int data;
	struct Node* next;
};
struct Node *Creat_headNode() {//����ͷ��㣬�ṹ�庯����
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
void create_node(struct Node* HeadNode);//ֱ��������β������һ���½ڵ�
void delete_node(struct Node* head, int flag);
void clear_list(struct Node** pphead);
struct Node* Creat_singleNode(int x);//����һ������㣬����Ϊ��������ֵ
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
	printf("�������½���data:");
	scanf_s("%d", &newnode->data);
	while (p->next!=NULL)
	{
		p = p->next;
	}
	p->next = newnode;
	newnode->next = NULL;
	//
}
void delete_node(struct Node* head, int flag)//ɾ��ָ��λ�εĽ��
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
void clear_list(struct Node** pphead)//����ͷָ��ĵ�ַ���������ܸı�ͷָ�롣
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
void delete_data(struct Node* Head);//ɾ��ָ����ֵ�Ľ��
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
	printf("��������Ҫ������½���dataֵ��");
	scanf_s("%d", &x);
	printf("������������λ�Σ�");
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
	printf("������ҪѰ�ҵ�ֵ��");
	scanf_s("%d", &x);
	while (p)
	{
		if (p->data == x)
			break;
		p = p->next;
		i++;
	}
	if (!p)
		printf("��Ҫ�ҵ����ݲ����ڣ�");
	else
		printf("��Ҫ�ҵ������ڵ�%d��", i);
}
void delete_data(struct Node* Head)
{
	struct Node* p=Head, * cur=p->next;
	if (!cur)
		cur = 1;

	int x;
	printf("��������Ҫɾ�������ݣ�");
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