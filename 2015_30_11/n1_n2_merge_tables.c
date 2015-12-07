// n1,n2.cpp : Defines the entry point for the console application.
//There are two types of problems in this same problem 
/*READ 
	THE 
		COMMENTS 
``1.given a value ,returning the index of the value in the merged
``2.given an index returning the value 
``n1_n2 function takes the index vaalue and return the value in the index
``n1_n2_problem_2 returns the index ,when given a value
*/
#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
struct test_cases
{
	int a;
	int b;
	int k;
	int ans;
}t[10] = {
		{2,3,6,9},
		{2,3,1,2},
		{2,3,-2,-1},
		{2,3,2,3},
		{3,5,10,21},
		{ 123, 478, 999, 97785 },
		{3,5,0,-1},
		{4,5,10,25},
		{60,40,5,160},
		{20,30,4,60}
};
int n1_n2(int a, int b,int k)
{
	if (a == 0 || b == 0)
		return -1;
	if (k <= 2)
	{//corner cases 
		int min, max;
		if (a < b)
		{
			min = a;
			max = b;
		}
		else
		{
			min = b;
			max = a;
		}
		if (k == 1)
			return min;
		else if(k == 2)
			return max;
		else
		return -1;
	}
	else
	{
		int i = 1, j = 1, count = 2;
		//main code ....
		int temp = a, temp2 = b;
		while (count < k)
		{
			if (a < b)
			{
				a = (temp * (++i));
				if (a!=b)
				count++;
				if (count == k)
					return a;
			}
			else if (a > b)
			{
				b = (temp2 * (++j));
				if (a!=b)
				count++;
				if (count == k)
					return b;
			}
			else
			{
				a = (temp * (++i));
				b = (temp2*(++j));
				if (a != b)
					count += 2;
				if (count == k)
				{
					if (a < b)
						return b;
					else
						return a;
				}
				else if (count - 1 == k)
				{
					if (a < b)
						return a;
					else
						return b;
				}
			}
		}
	}
}
int main()
{
	int ans;
	for (int i = 0; i < 9; i++)
	{
		ans = n1_n2(t[i].a, t[i].b, t[i].k);
		ans == t[i].ans ? printf("Test Succeeded\n") : printf("Test Failed\n");
	}
	return 0;
}

