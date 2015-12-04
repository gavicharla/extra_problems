// last_k_lines_of_a_file.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
struct test_cases
{
	char input[30];
	char output[30];
	int lines;
}t[5] = {
		{ "i\nhave\na\ncute\ncat", "cute\ncat",2 },
		{ "i\nam\having\a\nvery\ngood\nday", "very\ngood\nday",3 },
		{ "i\nhave\nonly\n5\nlines", "have\nonly\n5\nlines", 4 },
		{ "this\nis\nsmall", "small",1 },
		{ "Files\nare\nboring", "boring",1 }

};
char * validate(char * output, int i)
{
	int index = 0;
	while (output[index] != '\0'&&t[i].output[index] != '\0')
	{
		if (output[index] != t[i].output[index])
			return "Test Failed";
		index++;
	}
	if (output[index] == '\0'&&t[i].output[index] == '\0')
		return "Test Succeeded";
	else
		return "Test Failed";
}
char * last_k_lines(char * input,int lines)
{
	FILE *fp = fopen("D:\hello.txt", "w"),a[10];
	fprintf(fp, input, "%s");
	fcloseall();
	fp = fopen("D:\hello.txt", "r");
	int count = 0;
	char ch;
	fseek(fp, 0, SEEK_SET);
	a[count++] = *fp;
	rewind(fp);
	while (!(feof(fp)))
	{	
			ch = fgetc(fp);
			if (ch == '\n')
				a[count++] = *(fp);
		
	}
	if (lines > count)
		lines = count;
	*fp = a[count - lines];
	char * ans;
	ans = (char *)malloc(sizeof(char) * 100);
	int i = 0;
	while (!(feof(fp)))
	{
		ans[i] = fgetc(fp);
		i++;
	}
	ans[i-1] = '\0';
	return ans;
}
int main()
{
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		printf("%s\n", validate(last_k_lines(t[i].input, t[i].lines),i));
	}
	return 1;
}

