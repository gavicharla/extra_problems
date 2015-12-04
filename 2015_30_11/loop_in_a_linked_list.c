// loop in a linked list.cpp : Defines the entry point for the console application.
//
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data, flag;
	struct node * next;
};
struct test_cases
{
	int a[10], a_size, n, output;
}t[5] = {
		{ {1,2,3,4,5},5,3,5 },
		{ { 1, 2, 3, 4, 5 }, 5, 2, 5 },
		{ { 1, 2, 3, 4, 5 }, 5, 4, 5 },
		{ { 1, 2, 3, 4, 5 }, 5, 5, 5 },
		{ { 1, 2, 3, 4, 5 }, 5, 1, 5 },
		{ { 1, 2, 3 }, 3, 2, 5 }
};

char * validate(int n, int i)
{
	if(t[i].output==n)
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
		head->flag = 0;
		head->next = NULL;
	}
	temp = head;
	i = 1;
	while (i<size)
	{
		temp1 = (struct node *)malloc(sizeof(struct node));
		temp1->data = a[i];
		temp1->flag = 0;
		temp1->next = NULL;
		temp->next = temp1;
		temp = temp1;
		i++;
	}

	return head;
}
int method1(int * arr, struct node * head,int n)
{
	struct node * temp, *temp1;
	int i = 0, check, j = 0;
	temp = head;
	temp1 = head;
	while (temp1->next != NULL)
		temp1 = temp1->next;
	while (n--)
	{
		if (temp->next == NULL)
		{
			break;
		}
		else
			temp = temp->next;
	}
	temp1->next = temp;
	temp = head;
	while (1)
	{
		arr[i++] = (int)temp;
		check = (int)temp->next;
		//searching
		for (j = 0; j < i; j++)
		{
			if (arr[j] == check)
			{
				return temp->data;
			}
		}
		temp = temp->next;
	}
}

int method2(struct node * head, int n)
{
	struct node* temp = head, *temp1;
	temp1 = head;
	while (temp1->next != NULL)
		temp1 = temp1->next;
	while (n--)
	{
		if (n == 0)
			break;
		temp = temp->next;
	}
	temp1->next = temp;
	temp = head;
	while (temp->flag != 1)
	{
		temp->flag = 1;
		temp1 = temp;
		temp = temp->next;
	}
	return temp1->data;
}
int main()
{
	struct node * head = NULL, *temp;
	int i = 0, a[10];
	for (i = 0; i < 5; i++)
	{
		head = NULL;
		printf("%s\n", validate(method1(a, add(t[i].a, t[i].a_size, head), t[i].n), 0));
		head = NULL;
		printf("%s\n", validate(method2(add(t[i].a, t[i].a_size, head), t[i].n), 0));
	}
	return 0;
}

