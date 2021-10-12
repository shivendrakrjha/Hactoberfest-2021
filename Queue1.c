//Implementation of queue using array
#include <stdio.h>

struct queue
{
	int arr[5];  //array to store elements of structure
	int F;   //front 
	int R;   //rear
};

struct queue Q;
void initQ(struct queue Q)
{
	Q.F=-1;
	Q.R=-1;
	Q.arr[5];
}

void enqueue(int val)
{	
	printf("Enter the element to be inserted in the queue:");
	scanf("%d",&val);
	
	if (Q.F==4)
	{
		printf("No more elements can be inserted in the Queue :(");
	}
	else 
	{
		Q.arr[Q.F]=val;
		printf("Element %d inserted in the queue at index %d!!",val,Q.F);
		Q.F=Q.F+1;
	}
}

int dequeue()
{
	int val;
	if (Q.R==-1 | Q.R>4)
	{
		printf("\nQueue is empty, no element to remove!!");
		return 0;
	}
	else
	{
		val=Q.arr[Q.R];
		printf("\nElement %d is removed from the index %d!!",val,Q.R);
		Q.R=Q.R+1;
		return val;	
	}
}

int main()
{
	int x,n,y;
	
		printf("_____________Program to perform Queue operations______________________");
		printf("\nEnter 1 to insert an element and 2 to remove an element :-)");
		
		while (n<10)
		{
			printf("\n\nEnter your choice: ");
			scanf("%d",&y);
			
			switch(y)
			{
				case 1: enqueue(x);  //calling the function to insert element in queue
					break;
						
				case 2: dequeue();  //calling function to remove the element from queue
					break;
			}	
		}
}
