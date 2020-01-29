#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct Node
{
	element data;
	struct Node *left;
	struct Node *right;
}TreeNode;

typedef struct
{
	TreeNode *root;
	int length;
}Tree;

Tree* create()
{
	Tree *T = (Tree*)malloc(sizeof(Tree));
	return T;
}

void preorder(TreeNode *subroot) //전위순회
{
	if (subroot == NULL) return ;
	printf("%c ", subroot->data);
	preorder(subroot->left);
	preorder(subroot->right);
}

void inorder(TreeNode *subroot) //중위순회
{
	if (subroot == NULL) return;
	inorder(subroot->left);
	printf("%c ", subroot->data);
	inorder(subroot->right);
}

void postorder(TreeNode *subroot) //후위순회
{
	if (subroot == NULL) return;
	postorder(subroot->left);
	postorder(subroot->right);
	printf("%c ", subroot->data);
}

void createSampleTree(Tree* T)
{
	TreeNode* n[8];
	int i;

	if (T == NULL) exit(1);

	for (int i = 1; i < 8; i++)
	{
		n[i] = (TreeNode*)malloc(sizeof(TreeNode));
		n[i]->data = 'A' - 1 + i;
		n[i]->left = NULL;
		n[i]->right = NULL;
		T->length++;
	}

	n[1]->left = n[2];
	n[1]->right = n[3];
	n[2]->left = n[4];
	n[2]->right = n[5];
	n[3]->left = n[6];
	n[3]->right = n[7];

	T->root = n[1];
}

int main()
{
	Tree *T1, *T2;
	T1 = create();
	T2 = create();
	/*
	TreeNode *parent, *child;
	
	
	child = (TreeNode*)malloc(sizeof(TreeNode));
	child->data = 'A';
	child->left = NULL;
	child->right = NULL;
	T1->root = child;
	T1->length++;

	parent = child;
	child = (TreeNode*)malloc(sizeof(TreeNode));
	child->data = 'B';
	child->left = NULL;
	child->right = NULL;
	parent->left = child;
	T1->length++;

	child = (TreeNode*)malloc(sizeof(TreeNode));
	child->data = 'C';
	child->left = NULL;
	child->right = NULL;
	parent->right = child;
	T1->length++;
	*/
	createSampleTree(T1);
	preorder(T1->root); printf("\n");
	inorder(T1->root); printf("\n");
	postorder(T1->root);

	system("pause");
	return 0;
}