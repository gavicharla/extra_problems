// merge linked list.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdlib.h>
struct test_cases
{
	int a[10], b[10], size_a, size_b,output[10],output_size;
	
}t[6] = { 
{ { 1, 2, 3, 4, 5 }, { 1, 2, 3, 4, 5 }, 5, 5, { 1, 1, 2, 2, 3, 3, 4, 4, 5, 5 },10 },
{ {1,3,5,7,9}, {2,4,6,8},5 ,4 , {1,2,3,4,5,6,7,8,9},9 } ,
{ {1,1,1}, {1,1,1,1},3 ,4 , {1,1,1,1,1,1,1},7 },
{ {2,4,6}, {3,5},3 ,2 , {2,3,4,5,6},5 },
{ {2,4,5,6,7}, {1,3,8},5 , 3, {1,2,3,4,5,6,7,8},8  },
{ { 1, 2, 3 }, { 4, 5 }, 3, 2, {1,2,3,4,5},6 }

};
struct node
{
	int data, flag;
	struct node * next;
};
char * validate(struct node * head,int i)
{
	int n = t[i].output_size,count=0,flag=0;
	struct node * temp;
	temp = head;
	while (temp != NULL)
	{
		if (t[i].output[count] != temp->data || i >= n)
		{
			flag = 1;
			break;
		}
		i++;
	}
	if (flag == 0 && temp == NULL)
		return "Test Failed";
	else
		return "Test Succeeded";
}
struct node * add(int data, struct node * head)
{
	if (head == NULL)
	{
		head = (struct node *)malloc(sizeof(struct node));
		head->data = data;
		head->flag = 0;
		head->next = NULL;
		return head;
	}
	else
	{
		struct node * temp = (struct node *)malloc(sizeof(struct node));
		temp = head;
		while (temp->next != NULL)
			temp = temp->next;
		struct node * new2 = (struct node *)malloc(sizeof(struct node));
		new2->data = data;
		new2->next = NULL;
		new2->flag = 0;
		temp->next = new2;
		return head;
	}
}
//all the merging happens here
struct node * merge_sorted_sll(struct node * head1, struct node * head2)
{
	struct node *temp2 = NULL, *temp1 = NULL, *temp = NULL;
	int ch;
	if (head2 == NULL)
		return head1;
	temp = head2;
	while (head1 != NULL)
	{
		ch = head1->data;
		while (ch > temp->data)
		{
			temp1 = temp;
			temp = temp->next;
			if (temp == NULL)
				break;
		}
		if (temp1 != NULL)
			temp1->next = head1;
		temp2 = head1->next;
		head1->next = temp;
		if (temp == head2)
			head2 = head1;
		head1 = temp2;
	}
	return head2;
}

int main()
{
	int i, ch = 1, count = 0;
	struct node *head1 = NULL, *head2 = NULL, *temp2 = NULL,*temp1=NULL,*temp=NULL;
	for (i = 0; i < 6; i++)
	{
		head2 = NULL;
		head1 = NULL;
		for (count = 0; count < t[i].size_a; count++)
			head1 = add(t[i].a[count], head1);
		for (count = 0; count < t[i].size_b; count++)
			head2 = add(t[i].b[count], head2);
		temp = merge_sorted_sll(head1, head2);
		printf("%s\n",validate(temp,i));
	}
	return 0;
}

