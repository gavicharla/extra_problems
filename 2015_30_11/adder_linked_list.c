// adder_linked_list.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
struct test_cases
{
	int a[10],b[10];
	int a_size,b_size, output[10], output_size;

}t[10] = {

		{ { 1, 2, 3, 4, 5 }, { 1, 2, 3, 4, 5 }, 5, 5, {2,4,6,9,0},5 },
		{ { 1, 2, 3, 4, 5, 6 }, { 1, 2, 3, 4, 5 }, 6, 5, {1,3,5,8,0,1},6 },
		{ { 1 }, { 9, 9, 9 }, 1, 3, {1,0,0,0},4 },
		{ { 9, 9, 9, 9 }, { 1 }, 4, 1, {1,0,0,0,0},5 },
		{ {}, { 1 }, 0, 1, { 1 },1 },
		{ { 1, 2 }, { 8 }, 2, 1, {2,0},2 },
		{ { 1, 2 }, {}, 2, 0, {1,2},2 },
		{ { 1, 1, 1 }, { 9, 9, 9 }, 3, 3,{1,1,1,0},4 },
		{ { 1, 0 }, { 9 }, 2, 1, {1,9},2 }

};
struct node {
	int data;
	struct node * next;
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
struct node * fun(struct node * head1, struct node * head2)
{
	head1 = reverse_sll(head1);
	head2 = reverse_sll(head2);
	struct node * temp1 = head1, *temp2 = head2,*temp3=NULL,*temp4=NULL,*temp5=NULL;
	int carry = 0;
	while (temp1 != NULL&&temp2 != NULL)
	{
		temp2->data += carry+temp1->data;
		carry = 0;
		if (temp2->data > 9)
		{
			carry = temp2->data / 10;
			temp2->data %= 10;
		}
		temp3 = temp1;
		temp4 = temp2;
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	temp5 = temp4;
	if (temp1 != NULL)
	{
		while (temp1 != NULL)
		{
			temp1->data += carry;
			carry = 0;
			if (temp1->data > 9)
			{
				carry = temp1->data/10;
				temp1->data %= 10;
			}
			temp4->next = temp1;
			temp5 = temp4;
			temp4 = temp4->next;
			temp1 = temp1->next;
		}
	}
	if (temp2 != NULL)
	{
		while (temp2 != NULL)
		{
			temp2->data += carry;
			carry = 0;
			if (temp2->data > 9)
			{
				carry = temp2->data / 10;
				temp2->data %= 10;
			}
			temp5 = temp2;
			temp2 = temp2->next;
		}
	}
	if (carry > 0)
	{
		struct node * new1 = (struct node *)malloc(sizeof(struct node));
		new1->data = carry;
		temp5->next = new1;
		new1->next = NULL;
	}
	return reverse_sll(head2);
}
int main()
{
	
	struct node * head1 = NULL, *head2 = NULL,*temp;
	int i = 0;
	for (i = 0; i < 9; i++)
	{
		head1 = NULL, head2 = NULL;
		printf("%s\n", validate(fun(add(t[i].a, t[i].a_size, head1), add(t[i].b, t[i].b_size, head2)),i));
	}
	return 0;
}

