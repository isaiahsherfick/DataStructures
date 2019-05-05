#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct Node
{
	int data;
};

struct Tree
{
	struct Node* data;
	struct Tree* left;
	struct Tree* right;
};

struct Tree insert(struct Tree into, int data);
struct Tree delete(struct Tree from, int data);
struct Tree rebalance(struct Tree t);
struct Tree rotateLeft(struct Tree t);
struct Tree rotateRight(struct Tree t);
struct Tree easyLeft(struct Tree t);
struct Tree easyRight(struct Tree t);
int height(struct Tree t);
int max(int a, int b);


struct Tree insert(struct Tree into, int data)
{
	if (&into == NULL)
	{
		struct Tree newTree;
		struct Node newNode;
		newTree.data = &newNode;
		newNode.data = data;
		return newTree;
	}
	if (data < (*into.data).data)
	{
		struct Tree newLeft = insert(*into.left, data);
		into.left = &newLeft;
	}
	else if (data > (*into.data).data)
	{
		struct Tree newRight = insert(*into.right, data);
		into.right = &newRight;
	}
	into = rebalance(into);
	return into;
}

struct Tree delete(struct Tree from, int data)
{
	if ((*from.data).data == data)
	{
		//This is the hard case
		//Just returning a brand new Tree now
		struct Tree newTree;
		struct Node newNode;
		newTree.data = &newNode;
		newNode.data = 0;
		return newTree;
	}
	else if (data < (*from.data).data)
	{
		struct Tree newLeft = delete(*from.left, data);
		from.left = &newLeft;
	}
	else
	{
		struct Tree newRight = delete(*from.right, data);
		from.right = &newRight;
	}
	from = rebalance(from);
	return from;
}

struct Tree rebalance(struct Tree t)
{
	int leftHeight = height(*t.left);
	int rightHeight = height(*t.right);
	if (leftHeight - rightHeight > 1)
	{
		t = rotateRight(t);
	}
	else if (rightHeight - leftHeight > 1)
	{
		t = rotateLeft(t);
	}
	return t;
}

struct Tree rotateRight(struct Tree t)
{
	int leftHeight = height(*t.left);
	int rightHeight = height(*t.right);
	if (leftHeight > rightHeight)
	{
		return easyRight(t);
	}
	struct Tree newLeft = easyLeft(*t.left);
	t.left = &newLeft;
	return easyRight(t);
}

struct Tree rotateLeft(struct Tree t)
{
	int leftHeight = height(*t.left);
	int rightHeight = height(*t.right);
	if (leftHeight < rightHeight)
	{
		return easyLeft(t);
	}
	struct Tree newRight = easyRight(*t.right);
	t.left = &newRight;
	return easyLeft(t);
}

struct Tree easyLeft(struct Tree t)
{
	struct Tree currentLeft = *t.left;
	struct Tree currentRight = *t.right;

	struct Tree newLeftTree;
	struct Node newLeftNode;
	int newLeftData;
	newLeft.data = newLeftData;
	newLeftTree.data = newLeftNode;

	struct Tree newRightTree;
	struct Node newRightNode;
	int newRightData;
	newRight.data = newRightData;
	newRightTree.data = newRightNode;

	struct Tree newTree;
	struct Node newTreeNode;
	int newTreeNodeData;
	newTreeNode = newTreeNodeData;

	newTreeNodeData = (*currentRight.data).data;
	newTreeNode.data = newTreeNodeData;
	newTree.data = &newTreeNode;

}

int height(struct Tree t)
{
	if (&t == NULL)
	{
		return 0;
	}
	return 1 + max(height(*t.left),height(*t.right));
}

int max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int main()
{
	struct Node myNode;
	int data = 1;
	myNode.data = data;
	struct Tree myTree;
	myTree.data = &myNode;
	return 0;
}
