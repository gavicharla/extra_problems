// median  _sll.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdlib.h>

struct node
{
	int data, flag;
	struct node * next;
}*new1 = NULL, *temp = NULL, *temp1 = NULL;
struct test_cases
{
	int a[10];
	int size_a;
	int median_data;
}t[10] = {
		{ { 5, 2, 3, 4, 1 }, 5, 3 },
		{ { 1, 4, 3, 2, 5 }, 5,3 },
		{ { 1, 3, 2 }, 3,3 },
		{ { 2, 1 }, 2,1 },
		{ { 1, 3, 2, 4 }, 4,2 },
		{ { 4 }, 1, 4 },
		{ { 1,1,1,1 }, 4, 1 },
		{ { 1, 2, 1, 2 }, 4, 1 },
		{ { 1, 2, 4, 3, 5 }, 5, 4 },
		{ { 1, 2, 5, 4, 3 }, 5,  5 }
};

char* validate(struct node * head, int n)
{
	if (head->data == t[n].median_data)
		return "Test Succeeded";
	else
		return "Test Failed";
}

struct node * add(int * a, int size, struct node *head)
{
	struct node *temp1 = NULL, *temp = NULL;
	int i;
	if (size == 0)
	{
		head = (struct node *)malloc(sizeof(struct node));
		head->data = 0;
		head->next = NULL;
		return head;
	}
	if (head == NULL)
	{
		head = (struct node *)malloc(sizeof(struct node));
		head->data = a[0];
		head->next = NULL;
	}
	temp = head;
	i = 1;
	while (i<size)
	{
		temp1 = (struct node *)malloc(sizeof(struct node));
		temp1->data = a[i];
		temp1->next = NULL;
		temp->next = temp1;
		temp = temp1;
		i++;
	}
	return head;
}
struct node * median_method1(struct node * head)
{
	struct node * temp = head;
	int count = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	temp = head;
	count /= 2;
	while (count--)
		temp = temp->next;
	return temp;
}
struct node * median_method2(struct node * head)
{
	struct node * temp = head,*temp1=temp;
	while (temp1 != NULL)
	{
		if (temp1->next != NULL)
		{
			temp1 = temp1->next->next;
			temp = temp->next;
		}
		else
			temp1 = temp1->next;
		
	}
	return temp;
}
int main()
{
	struct node * head1 = NULL;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%s\n", validate(median_method1(add(t[i].a, t[i].size_a, head1)), i));
		head1 = NULL;
		printf("%s\n", validate(median_method2(add(t[i].a, t[i].size_a, head1)), i));
	}

	
}

