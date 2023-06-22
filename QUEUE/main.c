#include <stdio.h>
#include <stdlib.h>
#include "Circular.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Queue myQueue;
	int choice, num;
	String menuOption[10] = {"Enqueue", "Dequeue", "isEmpty", "isFull", "Display", "Visualize", "Front", "RemoveItem", "RemoveEven", "DoubleTheValue"};
	int i, value;
	initQueue(&myQueue);
	
	do{
		system("cls");
		printf("MENU\n");
		for(i=0;i < 10;++i){
			printf("[%d] %s\n", i+1, menuOption[i]);
		}
		printf("Enter your choice <0 to Exit>: ");
		scanf("%d", &choice);
		switch(choice){
			case 1: 
				printf("Enqueue\n");
				printf("Enter a number: ");
				scanf("%d", &value);
				enqueue(&myQueue, value);
				visualize(myQueue);
				break;
			case 2:
				printf("Dequeue\n");
				dequeue(&myQueue);
				visualize(myQueue);
				break;
			case 3:
				printf("Check if Empty\n");
				if(isEmpty(myQueue)){
					printf("It is empty");
				}else{
					printf("Not empty.");
				}
				break;
			case 4:
				printf("Check if Full\n");
				if(isFull(myQueue)){
					printf("It is full");
				}else{
					printf("Not full.");
				}
				break;
			case 5:
				printf("Display Queue\n");
				display(myQueue);
				break;
			case 6:
				printf("Visualize Queue\n");
				visualize(myQueue);
				break;
			case 7:
				printf("Front\n");
				printf("%d ", front(myQueue));
				break; 
			case 8:
				printf("Remove Item\n");
				printf("Enter a number: ");
				scanf("%d", &value);
				removeItem(&myQueue, value);
				break;
			case 9:
				printf("Remove All Even\n");
				Queue evens;
				evens = removeEven(&myQueue);
				display(evens);
				break;
			case 10:
				printf("Double The Value\n");
				printf("Enter a number to be doubled: ");
				scanf("%d", &value);
				num = doubleTheValue(&myQueue, value);
				printf("There are %d numbers doubled.\n", num);
				break;
			case 0:
				printf("Thank you!\n");
			default:
				printf("Invalid choice...\n");
		}
		printf("\n");
		system("pause");
	} while(choice!=0);
	printf("Bye!!\n");
	return 0;
}
