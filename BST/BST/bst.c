#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct node
{
	element key;
	struct node *left;
	struct node *right;
}TreeNode;

typedef struct
{
	TreeNode *root;
}BST;

BST* create()
{
	BST *T = (BST*)malloc(sizeof(BST));
	T->root = NULL;
	return T;
}

TreeNode* search1(TreeNode *p, element key)
{
	if (p == NULL) return NULL; //key 값이 BST 존재하지 않는 경우
	if (p->key == key) return p; //key 값을 찾은 경우

	if (p->key > key) return search1(p->left, key);
	else if (p->key < key) return search1(p->right, key);

}

TreeNode* search2(BST *T, element key)
{
	TreeNode *p = T->root;

	while (p != NULL)
	{
		if (p->key == key) return p;
		else if (p->key > key) p = p->left;
		else p = p->right;
	}
	return p; //null
}


int insert(BST *T, element key)
{
	TreeNode *p = T->root;
	TreeNode *parent = NULL;
	//탐색
	while (p != NULL)
	{
		parent = p;
		if (p->key == key) return 0;
		else if (p->key > key) p = p->left;
		else p = p->right;
	}
	p = (TreeNode*)malloc(sizeof(TreeNode));
	p->key = key;
	p->left = p->right = NULL;

	if (parent == NULL) T->root = p;

	else if (p->key < parent->key) parent->left = p;
	else parent->right = p;

	return 1;
}

void delete()
{

}

void preorder(TreeNode *p)
{
	if (p == NULL) return;

	printf("%d ", p->key);
	preorder(p->left);
	preorder(p->right);
}

int main()
{
	BST *T1, *T2;
	TreeNode *n;
	T1 = create();
	T2 = create();
	
	insert(T1, 10);
	insert(T1,  5);
	insert(T1, 15);
	insert(T1,  7);
	insert(T1, 13);
	preorder(T1->root);

	n = search1(T1->root, 15);
	if (n == NULL) printf("해당하는 key 값이 없습니다.");
	else printf("\n%d", n->key);
	system("pause");
	return 0;
}