#include<stdio.h>
#include<string.h>
void reserve(char *arr)
{
	int len = strlen(arr);
	int left = 0;
	int right = len - 1;
	while(left < right)
	{
		char temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
		left++;
		right--;
	}
}
int turn(char c)
{
	if(c >= 'A' && c <= 'F')
		return c - 'A' + 10;
	else
		return c - '0';
}
char r_turn(int num)
{
	if(num > 9)
		return num - 10 + 'A';
	else
		return num + '0';
}
void add(char *n, char *m, char *res)
{
	int lenN = strlen(n);
	int lenM = strlen(m);
	char cn, cm;
	int j = 0;
	int count;
	for(count = 0; count < lenN || count < lenM || j; count++)
	{
		if(count >= lenN)
			cn = 0;
		else
			cn = turn(n[count]);
		if(count >= lenM)
			cm = 0;
		else
			cm = turn(m[count]);
		int temp = cn + cm + j;
		if(temp > 15)
		{
			temp -= 16;
			j = 1;
		}
		else
			j = 0;
		char cres = r_turn(temp);
		res[count] = cres;
	}
	res[count] = '\0';
}
int main()
{
	char res[10][202];
	int T;
	scanf("%d", &T);
	for(int i = 0; i < T; i++)
	{
		char n[201];
		char m[201];
		scanf("%s %s", n, m);
		reserve(n);
		reserve(m);
		add(n, m, res[i]);
		reserve(res[i]);
	}
	for(int i = 0; i < T; i++)
	{
		printf("case #%d:\n", i);
		printf("%s\n", res[i]);
	}
	return 0;
}