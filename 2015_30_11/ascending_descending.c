// ascending_descending_sll.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node * next;
};
struct test_cases
{
	int a[10], a_size, output_size, output[10];
}t[10] = {
		{ { 1, 2, 3,5,3,2}, 6, 6, { 1,2,2,3,3,5 } },
		{ { 1, 1, 2, 1 }, 4, 4, { 1, 1, 1, 2 } },
		{ { 1, 3, 6, 5 }, 4, 4, { 1,3,5,6 } },
		{ { 1,4, 3, 2, 1 }, 5, 5, {1, 1, 2, 3, 4 } },
		{ { 0, 1, 2, 0 }, 4, 4, { 0, 0, 1 ,2} },
		{ { 1, 3, 5, 9, 7 }, 5, 5, { 1, 3, 5, 7, 9 } },
		{ { 2, 3, 4, 5, 56 }, 5, 5, { 2,3, 4, 5, 56 } },
		{ { 1, 1, 2, 1 }, 4, 4, { 1, 1, 1, 2 } }
};
char* validate(struct node * head, int n)
{
	struct node * temp = head;
	int i = 0, flag = 0;;
	while (temp != NULL)
	{
		if (temp->data != t[n].output[i] || i >= t[n].output_size)
		{
			flag = 1;
			break;
		}
		temp = temp->next;
		i++;
	}
	if (flag == 0 && temp == NULL)
		return "Test Succeeded";
	else
		return "Test Failed";
}

struct node * add(int * a, int size, struct node *head)
{
	struct node *temp1 = NULL, *temp = NULL;
	int i;
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
struct node * merge_sorted_sll(struct node * head1, struct node * head2)
{
	struct node *temp2 = NULL, *temp1 = NULL, *temp = NULL;
	int ch;
	if (head2 == NULL)
		return head1;
	temp = head2;
	while (head1 != NULL)
	{
		if (temp==NULL)
		temp = head2;
		ch = head1->data;
		while (ch > temp->data)
		{
			temp1 = temp;
			temp = temp->next;
			if (temp == NULL)
			{
				break;
			}
		}
		if (temp1 != NULL)
			temp1->next = head1;

		temp2 = head1->next;
		head1->next = temp;
		
		if (temp == head2)
			head2 = head1;
		head1 = temp2;
		temp1 = NULL;
	}
	return head2;
}

struct node * reverse_sll(struct node * temp)
{
	struct node * head = NULL;
	if (temp->next != NULL)
		head = reverse_sll(temp->next);
	else
		return temp;
	temp->next->next = temp;
	temp->next = NULL;
	return head;
}
struct node * asc_descending(struct node * head)
{
	struct node * temp = NULL, *temp1 = NULL;
	temp = head;
	while (temp->next != NULL)
	{
		if (temp->data > temp->next->data)
			break;
		temp1 = temp;
		temp = temp->next;
	}
	temp1->next = NULL;
	temp = reverse_sll(temp);
	temp = merge_sorted_sll(temp,head);
	return temp;
}

int main()
{
	struct node * head = NULL;
	int i = 0;
	for (i = 0; i < 8; i++)
	{
		head = NULL;
		printf("%s\n", validate(asc_descending(add(t[i].a, t[i].a_size, head)), i));
	}
	return 1;
}


