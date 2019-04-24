#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct Node
{
	int data;

	int position;
};

struct BinaryHeap
{

	struct Node *  nodes;

	int size;
};

struct BinaryHeap insert(struct BinaryHeap heap, struct Node node);
struct BinaryHeap moveUp(struct BinaryHeap heap, struct Node node);
struct BinaryHeap moveDown(struct BinaryHeap heap, struct Node node);
struct BinaryHeap extractMin(struct BinaryHeap heap);
int getParentIndex(struct Node node);
void printHeap(struct BinaryHeap heap);
struct BinaryHeap swap(struct BinaryHeap heap, struct Node n1, struct Node n2);
int minChildIndex(struct BinaryHeap heap, struct Node node);



struct BinaryHeap insert(struct BinaryHeap heap, struct Node node)
{
	heap.size++;
	node.position = heap.size;
	heap.nodes[heap.size] = node;
	heap = moveUp(heap, node);
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
		heap = swap(heap, heap.nodes[parentIndex], node);
	}
	return moveUp(heap, heap.nodes[parentIndex]);
}

struct BinaryHeap moveDown(struct BinaryHeap heap, struct Node node)
{
	int minIndex = minChildIndex(heap, node);
	if (minIndex == -1)
	{
		return heap;
	}
	if (heap.nodes[minIndex].data < node.data)
	{
		heap = swap(heap, heap.nodes[minIndex], node);
	}
	return moveDown(heap, heap.nodes[minIndex]);
}

struct BinaryHeap extractMin(struct BinaryHeap heap)
{
	heap = swap(heap, heap.nodes[1], heap.nodes[heap.size]);
	heap = moveDown(heap,heap.nodes[1]);
	heap.size--;
	return heap;
}

int minChildIndex(struct BinaryHeap heap, struct Node node)
{
	int leftChildIndex = node.position * 2;
	int rightChildIndex = (node.position * 2) + 1;

	if (leftChildIndex > heap.size && rightChildIndex > heap.size)
	{
		return -1;
	}
	if (rightChildIndex > heap.size)
	{
		return leftChildIndex;
	}
	if (leftChildIndex > heap.size)
	{
		return rightChildIndex;
	}
	if (heap.nodes[leftChildIndex].data > heap.nodes[rightChildIndex].data)
	{
		return rightChildIndex;
	}
	else
	{
		return leftChildIndex;
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
	int i;
	for (i = 0; i < 500; i++)
	{
		printf("\n");
	}
	printf("\nindices: \n");
	for (i = 1; i <= heap.size; i++)
	{
		printf("%d\t", i);
	}
	printf("\nheap: \n{");
	for (i = 1; i <= heap.size; i++)
	{
		if (i == heap.size)
		{
			printf("%d",heap.nodes[i].data);
		}
		else
		{
			printf("%d\t",heap.nodes[i].data);
		}
	}
	printf("}\n");
}

int main()
{
	struct BinaryHeap heap;
	heap.size = 0;
	heap.nodes= (struct Node *) malloc(500);
	int i;
	for (i = 0; i < 500; i++)
	{
		printf("\n");
	}
	printf("\nWhat would you like to insert in the empty heap?\n\nValue to insert: ");

	int userInput;

	scanf(" %d",&userInput);

	struct Node nodeToInsert;

	nodeToInsert.data = userInput;

	heap = 	insert(heap, nodeToInsert);

	int userExit = 0;
	int printMin = 0;
	int min;

	while (!userExit)
	{
		printHeap(heap);
		if (printMin)
		{
			printf("\nMin: %d\n",min);
			printMin = 0;
		}
		printf("\nPlease input a command.\n");
		printf("1. Insert\n2. Find Min\n3. Extract Min\n4. Exit\nCommand: ");
		scanf(" %d", &userInput);
		switch(userInput)
		{
			case 1:
				printf("\nWhat would you like to insert into the heap?\n\nValue to insert: ");
				scanf(" %d",&userInput);
				nodeToInsert.data = userInput;
				heap = insert(heap,nodeToInsert);
				break;
			case 2:
				min = heap.nodes[1].data;
				printMin = 1;
				break;
			case 3:
				min = heap.nodes[1].data;
				printMin = 1;
				heap = extractMin(heap);
				break;
			case 4:
				userExit = 1;
				free(heap.nodes);
			default:
				break;
		}
	}

	printf("\nExiting...\n");

	return 0;
}


