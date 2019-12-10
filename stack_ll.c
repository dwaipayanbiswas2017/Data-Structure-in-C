#include<stdio.h>
#include<stdlib.h>

struct node
{
	int item;
	struct node *next;
};
struct node *head = NULL;

void push(int item){
	struct node *p = (struct node *)malloc(sizeof(struct node *));
	if(p == NULL){
		printf("Error in malloc\n");
		return;
	}
	p->item = item;
	p->next = head;
	head = p;
}

int pop(){
	if(head == NULL){
		printf("Stack is empty.\n");
		return -1;
	}else{
		int item = head->item;
		head = head->next;
		return item;
	}
}

void print_stack(){
	if(head == NULL)
		printf("Stack is empty.\n");
	else{
		struct node *elem = head;
		while(elem){
			printf("%d\n",elem->item);
			elem = elem->next;
		}
	}
}

void main(){
	int choice, item;
	do{
		printf("\n\n\t***STACK APPLICATION***\n1.Show Stack\n2.Push element\n3.Pop element\n\n 0.Exit\n\nEnter choice : ");
		scanf("%d",&choice);

		switch(choice){

			case 1:
				system("clear");
				printf("The data in the Stack are as follow : \n");
				print_stack();
				break;
			case 2:
				system("clear");
				printf("Enter data to add : ");
				scanf("%d",&item);
				push(item);
				break;
			case 3:
				system("clear");
				item = pop();
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