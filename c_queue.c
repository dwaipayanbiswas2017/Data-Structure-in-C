// Circular queue

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define SIZE 10

int cq[SIZE];
int front=0, rear=0;

void print_queue(){
	if(front == rear){
		printf("Queue is empty\n");
	}else{
		printf("Front : %d, Rear : %d\n",front, rear);
		for(int tmp = 0; tmp < SIZE; tmp++){
			printf("%d\n",cq[tmp]);
		}
	}
}

void enqueue(int item){
	rear = (rear + 1) % SIZE;
	if(front == rear){
		printf("Queue is overflow\n");
		if(rear == 0)
			rear = SIZE - 1;
		else
			rear--;
	}else{
		cq[rear] = item;
	}
}

int dequeue(){
	if(front == rear){
		printf("Queue is empty\n");
		return -1;
	}else{
		front = (front + 1) % SIZE;
		int item = cq[front];
		cq[front] = 0;
		return item;
	}
}


void main(){
	int choice, item;
	do{
		printf("\n\n\t***CIRCULAR QUEUE APPLICATION***\n1.Show Queue,\n2.Push element\n3.Pop element\n0.Exit\n\nEnter choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				system("clear");
				printf("The data in the Queue are as follow : \n");
				print_queue();
				break;
			case 2:
				system("clear");
				printf("Enter data to add : ");
				scanf("%d",&item);
				enqueue(item);
				break;
			case 3:
				system("clear");
				item = dequeue();
				printf("The poped data is : %d",item);
				break;
			case 0:
				printf("\n...Good bye...\n");
				break;
			default:
				printf("Please enter a valid option...\n");
		}
	}while(choice != 0);
}