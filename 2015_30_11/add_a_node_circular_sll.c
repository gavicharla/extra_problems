// add_ a _node_ circular_linked_list.cpp : Defines the entry point for the console application.
//

#include<stdio.h>
#include<stdlib.h>
struct test_cases
{
	int a[10];
	int a_size;
	int data;
	int output[11];
	int output_size;
}t[10] = {
		{ { 1, 2, 3, 4, 5 }, 5, 5, {1,2,3,4,5,5},6 },
		{ { 1, 2, 3, 4, 5 }, 5, 1, {1,1,2,3,4,5},6 },
		{ { 1, 1, 1, 1, 1 }, 5, 1, {1,1,1,1,1,1},6 },
		{ { 1, 3, 4, 5 }, 4, 2, {1,2,3,4,5},5 },
		{ { 1, 1, 2, 2, 3, 3 }, 6, 2, {1,1,2,2,2,3,3},7 },
		{ { 1 }, 1, 1, {1,1},2 },
		{ {}, 0, 1, { 1 },1 },
		{ { 1 }, 1, 2, {1,2},2 },
		{ { 1 }, 1, 0, {0,1},2 },
		{ { 0, 2 }, 2, 1, {0,1,2},3 }

};
struct node
{
	int data, flag;
	struct node * next;
}*new1 = NULL, *temp = NULL, *temp1 = NULL;
char * validate(struct node * head, int i)
{
	struct node * temp = head;
	int size = t[i].output_size, j, flag=0;
	for (j = 0; j < size; j++)
	{
		if (t[i].output[j] != temp->data)
		{
			return "Test Failed";
		}
		temp = temp->next;
	}
	if (temp == head)
		return "Test Succeeded";
	else
		return "Test Failed";

}

struct node * add(int * a, int size, struct node *head)
{
	struct node *temp1 = NULL, *temp = NULL;
	int i;
	if (size == 0)
		return NULL;
	if (head == NULL)
	{
		head = (struct node *)malloc(sizeof(struct node));
		head->data = a[0];
		head->next = head;
	}
	temp = head;
	i = 1;
	while (i<size)
	{
		temp1 = (struct node *)malloc(sizeof(struct node));
		temp1->data = a[i];
		temp1->next = head;
		temp->next = temp1;
		temp = temp1;
		i++;
	}
	
	return head;
}
struct node *  fun2(struct node * head, int data)
{
	new1 = (struct node *)malloc(sizeof(struct node));
	new1->data = data;
	if (head == NULL)
	{
		head = new1;
		new1->next = new1;
		return new1;
	}
	temp = head;
	temp1 = head->next;
	while (1)
	{
		if (temp->data >= data&&temp==head)
		{
			while (temp1->next != head)
				temp1 = temp1->next;

			new1->next = temp;
			temp1->next = new1;
			head = new1;
			break;
		}
		else if (temp->data <= data &&temp1->data >= data)
		{
			new1->next = temp1;
			temp->next = new1;
			break;
		}
		else if (temp->data <= data&&temp1->data <= data&&temp1 == head)
		{

			new1->next = temp->next;
			temp->next = new1;
			break;
		}
		temp = (temp->next);
		temp1 = (temp->next);
	}
	return head;
}
int main()
{
	struct node * head=NULL,*temp=NULL;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		head = NULL;
		head = add(t[i].a, t[i].a_size, head);
		head = fun2(head, t[i].data);
		printf("%s\n",validate(head, i));
	}
	return 1;
}