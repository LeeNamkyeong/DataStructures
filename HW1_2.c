/*
HW1_2 이남경 20180349 중어중국학과 4학년
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_STRING 100

typedef struct Stack {
	char word[MAX_STRING];
	int top;

}Stack;

void init(Stack* s)
{
	s->top = -1;
}

int is_empty(Stack* s)
{
	return s->top == -1;
}

int is_full(Stack* s)
{
	return (s->top + 1) == MAX_STRING;
}

void push(Stack* s, char word)
{
	if (is_full(s))
	{
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else
	{
		s->top++;
		s->word[s->top] = word;
	}
}

char pop(Stack* s)
{
	int temp;
	if (is_empty(s))
	{
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	temp = s->word[s->top];
	s->top--;
	return temp;
}

int palindrome(char str[])
{
	Stack s;
	int i;

	init(&s);
	for (i = 0; str[i] != 0; i++) {
		if (str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
		push(&s, str[i]);
	}
	for (i = 0; str[i] != 0; i++) {
		if (str[i] != pop(&s))
			return 0;
	}
	return 1;

}

int main(void)
{
	char word[MAX_STRING];

	printf("Enter a word to check palindrome: ");
	scanf("%s", word);

	if (palindrome(word))
		printf("palindrome 입니다.\n");
	else
		printf("palindrome이 아닙니다.\n");
}