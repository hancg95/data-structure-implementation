#include<stdio.h>
#include<stdlib.h>
typedef int element;


typedef struct Node
{
	element data;
	struct Node *link;
}Node;

typedef struct Stack
{
	int length;
	Node *top;
}Stack;


Stack* create()
{
	Stack *S = (Stack*)malloc(sizeof(Stack));
	S->length = 0;
	S->top = NULL;

	return S;
}

int isEmtpy(Stack *S)
{
	if (S->length == 0) return 1;
	return 0;
}

void push(Stack *S, element item)
{
	Node *NewNode;
	if (S == NULL) exit(1);
	NewNode = (Node*)malloc(sizeof(Node));
	NewNode->data = item;
	NewNode->link = S->top;
	S->top = NewNode;
	S->length++;
}

element pop(Stack *S)
{
	element item = S->top->data;
	Node *tmp = S->top;
	if (S == NULL) exit(1);
	if (isEmtpy(S)) exit(1);
	S->top = S->top->link;
	free(tmp);
	S->length--;
	return item;
}

element peek(Stack *S)
{
	if (S == NULL) exit(1);
	if (isEmtpy(S)) exit(1);
	return S->top->data;
}

void display(Stack *S)
{
	if (S == NULL) exit(1);
	Node *N = S->top;
	while (N != NULL)
	{
		printf("%d ", N->data);
		N = N->link;
	}
}

int main()
{
	Stack *S1 = create();
	push(S1, 10);
	push(S1, 20);
	push(S1, 30);

	display(S1);
	pop(S1);
	printf("\n");
	display(S1);

	system("pause");
	return 0;
}