#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct Node
{
	//This could be any data type 
	int data;

	//The Node's position in the heap
	int position;
};

struct BinaryHeap
{

	struct Node *  nodes;

	int size;
};

//Function prototypes
struct BinaryHeap insert(struct BinaryHeap heap, struct Node node);
struct BinaryHeap moveUp(struct BinaryHeap heap, struct Node node);
int getParentIndex(struct Node node);
void printHeap(struct BinaryHeap heap);
struct BinaryHeap swap(struct BinaryHeap heap, struct Node n1, struct Node n2);

struct BinaryHeap insert(struct BinaryHeap heap, struct Node node)
{
	heap.size++;
	node.position = heap.size;
	heap.nodes[heap.size] = node;
	moveUp(heap, node);

	return heap;
}

struct BinaryHeap moveUp(struct BinaryHeap heap, struct Node node)
{
	int parentIndex = getParentIndex(node);
	if (node.position == 1)
	{
		return heap;
	}
	if (heap.nodes[parentIndex].data > node.data)
	{
		swap(heap, heap.nodes[parentIndex], node);
	}
	return heap;
}

int getParentIndex(struct Node node)
{
	if (node.position == 1)
	{
		//node has no parent
		return 1;
	}

	return node.position / 2;
}

struct BinaryHeap swap(struct BinaryHeap heap, struct Node n1, struct Node n2)
{
	int swap;
	swap = n1.position;
	n1.position = n2.position;
	n2.position = swap;
	heap.nodes[n1.position] = n1;
	heap.nodes[n2.position] = n2;
	return heap;
}


void printHeap(struct BinaryHeap heap)
{
	printf("\nheap: \n{");
	int i;
	for (i = 1; i <= heap.size; i++)
	{
		if (i == heap.size)
		{
			printf("%d",heap.nodes[i].data);
		}
		else
		{
			printf("%d ",heap.nodes[i].data);
		}
	}
	printf("}\n");
}

int main()
{
	struct BinaryHeap heap;
	heap.size = 0;
	heap.nodes= (struct Node *) malloc(500);
	printf("\nheap.nodes memory address: %p\n\n",heap.nodes);

	printf("\nWhat would you like to insert in the empty heap?\n\nValue to insert: ");

	int userInput;

	scanf(" %d",&userInput);

	struct Node nodeToInsert;

	nodeToInsert.data = userInput;

	heap = 	insert(heap, nodeToInsert);

	printf("%d",heap.size);

	printHeap(heap);

	int userExit = 0;

	while (!userExit)
	{
		printf("\nPlease input a command.\n");
		printf("1. Insert\n2.Find Min\n3.Extract Min\n4. Exit\nCommand: ");
		scanf(" %d", &userInput);
		switch(userInput)
		{
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				userExit = 1;
				free(heap.nodes);
			default:
				break;
		}
	}

	return 0;
}


