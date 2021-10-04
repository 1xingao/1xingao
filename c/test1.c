
#include<stdio.h>
#include<string.h>

int main()
{
	char s1[21];
	char s2[6];
	gets(s1);
	gets(s2);
	int i = 0, j = 0, num = i;
	int sum = 0;
	while (s1[i] != '\0' && s2[j] != '\0')
	{
		if (s1[i] == s2[j])
		{
			i++; j++;
		}
		else
		{
			num++;
			i = num;
			j = 0;
		}
		if (s2[j] == '\0')
		{
			j = 0;
			sum++;
			num += strlen(s2) - 1;
		}

	}
	printf("%d", sum);
}
