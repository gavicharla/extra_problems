// maximum_subarray.cpp : Defines the entry point for the console application.
//
//A Total of three methods
#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct test_cases
{
	int a[10],n, ans;
}t[10] = {
		{ { 1, -1, -2, 2, 3 }, 5, 5 },
		{ { -1, -1, 0, -1, -1 }, 5, 0 },
		{ { -2, -22, -1, -23, -1 }, 5, -1 },
		{ { 1, -2, 3, -2, 1 }, 5, 3 },
		{ { -2, -3, 4, -1, -2, 1, 5 }, 7, 7 },
		{ {1,2,3,4,5},5,15 },
		{ { 1, -1, 2, -2, 3 },5,3 },
		{ {1,-3,2,-5,7,6,-1,-4,11,-23},10,19 },
		{ {1,-3,2,-5},4,2 }
};
char * validate(int ans, int i)
{
	if (t[i].ans == ans)
		return "Test Succeeded";
	else
		return "Test Failed";
}
int max_subarray(int * a,int n)
{//using single loop O(n))
	int  i, prev_max = INT_MIN, max = a[0];
	for (i = 1; i<n; i++)
	{
		max += a[i];
		if (max <=a[i])
			max=a[i];
		if (max > prev_max)
			prev_max = max;
	}
	return prev_max;
}
int max_subarray1(int *a, int n)
{//using two loops o(n^2))
	int max, prev_max = INT_MIN, i = 0, j = 0;
	for (i = 0; i < n; i++)
	{
		max = a[i];
		if (max > prev_max)
			prev_max = max;
		for (j = i + 1; j < n; j++)
		{ 
			if (max + a[j]>max||max+a[j]>0)
				max += a[j];
			else
				break;
		}
		if (max > prev_max)
			prev_max = max;
	}
	return prev_max;
}
int max_subarray2(int *a, int n)
{//using recursion 
	//recusion takes O(nlogn) and loops take O(n)
	if (n==1)
		return a[0];
	int m = n / 2;
	int left_sub = max_subarray2(a, m);
	int right_sub = max_subarray2(a+m, n-m);
	int i = 0, left_sum = INT_MIN, right_sum = INT_MIN, sum=0, max_sum;
	for (i = m; i <= n; i++)
	{
		sum += a[i];
		if (sum > right_sum)
			right_sum = sum;
	}
	sum = 0;
	for (i = m - 1; i >= 0; i--)
	{
		sum += a[i];
		if (sum > left_sum)
			left_sum = sum;
	}
	if (left_sub >= right_sub)
		max_sum = left_sub;
	else
		max_sum = right_sub;

	if (max_sum >= left_sum + right_sum)
		return max_sum;
	else
		return (left_sum + right_sum);
}
int main()
{
	int i;
	for (i = 0; i < 9; i++)
	{
		printf("%s\n", validate(max_subarray(t[i].a, t[i].n), i));
		printf("%s\n", validate(max_subarray1(t[i].a, t[i].n), i));
		printf("%s\n", validate(max_subarray2(t[i].a, t[i].n-1), i));
	}
	return 0;
}



