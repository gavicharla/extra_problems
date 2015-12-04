// numbers_exchanged_sll.cpp : Defines the entry point for the console application.
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
	int a[10], a_size, output[10], output_size;
}t[10] = {
		{ { 5, 2, 3, 4, 1 }, 5,  { 1, 2, 3, 4, 5 },5 },
		{ { 1, 4, 3, 2, 5 }, 5, { 1, 2, 3, 4, 5 },5 },
		{ { 1,3,2 }, 3,  { 1, 2, 3 },3 },
		{ { 2, 1 }, 2, { 1, 2 }, 2 },
		{ { 1, 3, 2, 4 }, 4, { 1, 2, 3, 4 }, 4 },
		{ { 4, 2, 3, 1 }, 4, { 1, 2, 3, 4 }, 4 },
		{ { 3, 2, 1, 4 }, 4, { 1, 2, 3, 4 }, 4 },
		{ { 1, 2, 1, 2 }, 4, { 1, 1, 2, 2 }, 4 },
		{ { 1, 2, 4, 3 }, 4, { 1, 2, 3, 4 }, 4 },
		{ { 1, 2, 5, 4, 3 }, 5, { 1, 2, 3, 4, 5 }, 5 }
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
struct node * fun(struct node * head)
{
	struct node * temp = head,*first=NULL,*first_prev=NULL,*temp1=NULL;
	int count = 0;
	if (head->next)
		temp1 = head->next;
	while (count != 2&&temp1!=NULL)
	{
		if (temp1->data < temp->data&&count==0)
		{
			first = temp;
			count++;
		}
		else if (temp1->data < temp->data)
		{
			count++;
			break;
		}
		temp = temp1;
		temp1 = temp1->next;
	}
	//first has the first of the interchanged nodes
	//temp1 has the second of the interchanged nodes 
	//if the nodes exchanged are adjacent to each other
	if (count == 1)
	{
		temp1 = first->next;
		if (first != head)
		{//if the nodes dosent contain head node
			first_prev = head;
			while (first_prev->next != first)
			{
				first_prev = first_prev->next;
			}
			first->next = first->next->next;
			temp1->next = first;
			first_prev->next = temp1;
		}
		else
		{//if the nodes contain head node

			first->next = first->next->next;
			temp1->next = first;
			head = temp1;
		}
	}
	else
	{//if the nodes exchanged are not adjacent
		if (first != head)
		{//if the nodes dosent have head node 
			struct node * temp2;
			first_prev = head;
			while (first_prev->next != first)
			{
				first_prev = first_prev->next;
			}
			first_prev->next = temp1;
			first_prev = temp1->next;
			temp2 = first->next;
			first->next = first_prev;
			temp->next = first;
			temp1->next = temp2;

		}
		else
		{//if the have a head node 
			temp->next = head;
			first_prev = head->next;
			head->next = temp1->next;
			temp1->next = first_prev;
			head = temp1;
		}
	}
	return head;
}
int main()
{
	int i=0;
	struct node * head = NULL,*temp=NULL;
	for (i = 0; i < 10; i++)
	{
		printf("%s\n", validate(fun(add(t[i].a, t[i].a_size, head)), i));
	}
	return 0;
}

