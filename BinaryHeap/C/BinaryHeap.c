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
void insert(struct BinaryHeap heap, struct Node node);
void moveUp(struct BinaryHeap heap, struct Node node);
int getParentIndex(struct Node node);
void printHeap(struct BinaryHeap heap);
void swap(struct BinaryHeap heap, struct Node n1, struct Node n2);

void insert(struct BinaryHeap heap, struct Node node)
{
	node.position = heap.size;
	heap.nodes[heap.size] = node;
	heap.size++;
	moveUp(heap, node);
}

void moveUp(struct BinaryHeap heap, struct Node node)
{
	int parentIndex = getParentIndex(node);
	if (node.position == 1)
	{
		//nothing to do
		return;
	}
	if (heap.nodes[parentIndex].data > node.data)
	{
		swap(heap, heap.nodes[parentIndex], node);
	}
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

void swap(struct BinaryHeap heap, struct Node n1, struct Node n2)
{
	int swap;
	swap = n1.position;
	n1.position = n2.position;
	n2.position = swap;
	heap.nodes[n1.position] = n1;
	heap.nodes[n2.position] = n2;
}


void printHeap(struct BinaryHeap heap)
{
	printf("\nheap: \n{");
	int i;
	for (i = 0; i < heap.size; i++)
	{
		printf("%d ",heap.nodes[i]);
	}
	printf("}\n");
}

int main()
{
	//Create the heap
	
	struct BinaryHeap heap;
	heap.size = 0;
	heap.nodes= (struct Node *) malloc(500);
	printf("\nheap.nodesmemory address: %p\n\n",heap.nodes);


	printf("\nWhat would you like to insert in the empty heap?\n\nValue to insert: ");

	int userInput;

	scanf(" %d",&userInput);

	struct Node nodeToInsert;

	insert(heap, nodeToInsert);

	printHeap(heap);

	return 0;
}


