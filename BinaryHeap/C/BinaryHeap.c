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
void printHeap(struct BinaryHeap heap);

void insert(struct BinaryHeap heap, struct Node node)
{
	int size = heap.size;
	//todo
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


