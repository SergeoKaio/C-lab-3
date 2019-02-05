#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 
#define SIZE 100
#define SIZE2 50

int main()
{
	char buf[SIZE] = { 0 };
	printf("Enter a string:\n");
	fgets(buf, SIZE, stdin);
	int length = strlen(buf);

	int from = 0, count = 0;
	for (int i = 0; i < length; i++)// finding the beginning of the first word (from)
	{
		if (buf[i] != ' ')
			break;
		else
			from++;
	}

	for (int i = 0; i <= length - 1; i++)
	{
		if ((buf[i] != ' ') && (buf[i + 1] == ' '))
		{
			count++;
		}
		else if ((buf[i] != ' ') && (buf[i + 1] == '\n'))
		{
			count++;
		}
		else if ((buf[i] != ' ') && (buf[i] != '\n') && (buf[i + 1] == '\0'))
		{
			count++;
		}
		else
			continue;
	}

	printf("\nThe amount of words is %d\n", count);//first part of the task done

	char arr[SIZE2][SIZE] = { 0 }; //creating array for words
	int i = 0, j = 0;
	for (int k = from; k <= length; k++)
	{
		if (buf[k] != ' ')
		{
			arr[i][j] = buf[k];
			j++;
		}
		else if ((buf[k] == ' ') && (buf[k - 1] != ' '))
		{
			i++;//moving to the next string
			j = 0;
		}
		else if ((buf[k] == ' ') && (buf[k - 1] == ' '))
			continue;
	}
	for (int k = 0; k < count; k++)
	{
		printf("%s\t%d symbol(s)\n", arr[k], strlen(arr[k]));
	}
	return 0;
}