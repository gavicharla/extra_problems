int gcd(int a,int b)
{
	if(a%b==0)
		return b;
	else if(b==1)
		return 1;
	else
		return gcd(b,a%b);
}
int lcm(int a,int b)
{
	if(a<b)
	{
		a+=b;
		b=a-b;
		a-=b;
	}
	return ((a*b)/gcd(a,b);
}
int fun(int n1,int n2,int k)
{
return (k/n1)+(k/n2)-(k/lcm(n1,n2))
}
/*here what is happening is ....
i am using set theory ,simply put the formula for n(AUB)=n(A)+n(B)-n(A^B)
so the index of the k in the mergewd tables is the sum of values of A under k and values of  B under k
minus the repeated values that are under k ...
the repeated values are multiples of lcm(A,B)
this is the simple formula
*/