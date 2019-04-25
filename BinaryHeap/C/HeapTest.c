#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//Heap will consist of nodes
struct Node
{
	int data;

	int position;
};

//Actual heap struct only contains an array of nodes and int size.
//Size will be used to update position of nodes when they are inserted.
struct BinaryHeap
{

	struct Node *  nodes;

	int size;
};

/////////////////////////////////////////////////////////
//
// insert: insert a node into the heap, adjust heap as necessary
// moveUp: used in insertion to move a node up the heap
// moveDown: used when extracting the min (the first node) from the heap
// extractMin: remove and return the min (first node) from the heap
// getParentIndex: used in moveUp
// printHeap: prints the heap
// swap: used in move functions
// minChildIndex: used in moveDown
//
/////////////////////////////////////////////////////////

struct BinaryHeap insert(struct BinaryHeap heap, struct Node node);
struct BinaryHeap moveUp(struct BinaryHeap heap, struct Node node);
struct BinaryHeap moveDown(struct BinaryHeap heap, struct Node node);
struct BinaryHeap extractMin(struct BinaryHeap heap);
int getParentIndex(struct Node node);
void printHeap(struct BinaryHeap heap);
struct BinaryHeap swap(struct BinaryHeap heap, struct Node n1, struct Node n2);
int minChildIndex(struct BinaryHeap heap, struct Node node);



//Inserts a node into a heap and returns the heap
//
//@params heap: the heap to insert the node into
//	  node: the node to insert into the heap
struct BinaryHeap insert(struct BinaryHeap heap, struct Node node)
{
	heap.size++;
	node.position = heap.size;
	heap.nodes[heap.size] = node;
	heap = moveUp(heap, node);
	return heap;
}

//Moves a node up a heap recursively and returns the heap

//@params heap: the heap to be modified
//	  node: the starting point for the recursive moveUps
struct BinaryHeap moveUp(struct BinaryHeap heap, struct Node node)
{
	int currentIndex = node.position;
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

//Moves a node down the heap recursively and returns the heap
//
//@params heap: the heap to be modified
//	  node: the starting point for the recursive moveDowns
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

//Removes a node from the top of the heap and returns the modified heap.
//use 
//
//    int min = heap.nodes[1];
//
//before calling to store the min
//
//@params heap: the heap to be modified
struct BinaryHeap extractMin(struct BinaryHeap heap)
{
	if (heap.size == 0)
	{
		return heap;
	}
	heap = swap(heap, heap.nodes[1], heap.nodes[heap.size]);
	heap.size--;
	heap = moveDown(heap,heap.nodes[1]);
	return heap;
}

//returns the index of the smallest child of a node
//returns -1 if the node is a leaf
//
//@params heap: the heap to be inspected
//	  node: the parent node
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

//returns the index of the parent of a node
//returns 1 if the node is in position 1.
//
//@params node: the node whose parent's index is desired
int getParentIndex(struct Node node)
{
	if (node.position == 1)
	{
		//node has no parent
		return 1;
	}

	return node.position / 2;
}

//swaps two nodes within a heap
//
//@params heap: the heap to be modified
//	    n1: the first node to be swapped
//     	    n2: the second node to be swapped
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


//prints a heap
//
//@params heap: the heap to be printed
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
	heap.nodes = (struct Node * ) malloc(500);
	int i;
	struct Node nodeToInsert;
	for (i = 0; i < 100; i+=5)
	{
		nodeToInsert.data = i;
		if (i % 2 == 0)
		{
			nodeToInsert.data *= -1;
		}
		heap = insert(heap, nodeToInsert);
	}

	printHeap(heap);

	for (int i  = 0; i < 5; i++)
	{
		heap = extractMin(heap);
	}

	printHeap(heap);

	
	return 0;
}
