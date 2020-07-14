
#include<stdio.h>
#include<stdlib.h>
void push(int *a, int *n);
void pop( int *stack,int *top);
void display(int *stack, int top);
int isFull(int top);
int isEmpty(int *top);


int main()
{

	int stack[100],choice,n,top,x,i;

	top=-1;

	printf("\n Enter the size of STACK[MAX=100]:");
	
	scanf("%d",&n);
	printf("\n\t STACK OPERATIONS USING ARRAY");
	printf("\n\t--------------------------------");
	printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT");
	int * stackptr = stack;
	do
	{
		printf("\n Enter the Choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				push(stackptr,&top);
				printf("%d", top);
				break;
			}
		
			case 2:
			{
				pop(stack,&top);
				break;
			}
			case 3:
			{
				display(stackptr,top);
				break;
			}
			case 4:
			{
				printf("\n\t EXIT POINT ");
				break;
			}
			default:
			{
				printf ("\n\t Please Enter a Valid Choice(1/2/3/4)");
			}
                 
		}	
	}while(choice!=4);

	return 0;
}

int isFull(int top)
{
	if(top==99)return 1;
	else return 0; 
}

int isEmpty(int* top)
{
	if(*top== -1)return 1;

	else return 0;
}

void push(int *stack, int *top)
{
	int x;
	
	if(isFull(*top)){//CHECK STACK IS OVER FLOW OR NOT
        	printf("\n\tSTACK is over flow");
	}
	else
	{
		printf(" Enter a value to be pushed:");
        	scanf("%d",&x);
		++(*top);
		stack[*top]=x;// TOP POSITION IS CHANGED 
		// PUSH x to Stack
	}
}

void pop(int *stack,int *top)
{
	//CHECK STACK IS EMPTY OR NOT
	if(isEmpty(top)){	
        	printf("\n\t Stack is under flow");
			}
	else{
		stack[(*top)--]=0;// TOP POSITION IS CHANGED 
        	//POP from STACK
    	}
}

void display(int *stack, int top)
{
	int i;
	printf("%d", top);
	//CHECK STACK IS EMPTY OR NOT
	if(isEmpty(&top))
		printf("STACK IS EMPTY ");		
	else
    	{
	        printf("\n The elements in STACK \n");
		printf("\n stack[");
		for(i=0;i<=top;i++){
			printf("%d",stack[i]);
			printf("]");		}
//PRINT FROM TOP TO BOTTOM 
		
 	}
    
}
 
