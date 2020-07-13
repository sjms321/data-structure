#include<stdio.h>
#include<malloc.h>
#include<time.h>
#include<stdlib.h>

typedef struct DQNode{
	int  data;
	struct DQNode *llink;
	struct DQNode *rlink;
}DQNode;

typedef struct{
	DQNode *front,*rear;
}DQueType;

DQueType *createDQue(){
	DQueType *DQ;
	DQ=(DQueType*)malloc(sizeof(DQueType));
	DQ -> front = NULL;
	DQ -> rear =  NULL;
	return DQ;
}

int isEmpty(DQueType *DQ){
	if(DQ->front==NULL){
		printf("\n LINKED QUEUE IS EMPTY! \n");
		return 1;
	}
	else return 0;
}

void insertFront(DQueType *DQ, int  item){
	DQNode *newNode = (DQNode*)malloc(sizeof(DQNode));
	newNode->data=item;
	if(DQ->front == NULL){
		DQ->front = newNode;
		DQ->rear = newNode;
		newNode->rlink=NULL;
		newNode->llink=NULL;
	}
	else{
		DQ->front->llink=newNode;
		newNode->rlink=DQ->front;
		newNode->llink=NULL;
		DQ->front=newNode;
	}		
}

void insertRear(DQueType *DQ,int  item){
	DQNode *newNode = (DQNode*) malloc(sizeof(DQNode));
	newNode->data=item;
	if(DQ->rear == NULL){
		DQ->front = newNode;
		DQ->rear=newNode;
		newNode->rlink=NULL;
		newNode->llink=NULL;	
	}
	else{
		DQ->rear->rlink=newNode;
		newNode->rlink=NULL;
		newNode->llink=DQ->rear;
		DQ->rear=newNode;	
	}
}


void printDQ(DQueType *DQ){
	DQNode *temp = DQ->front;
	printf("DeQue : [");
	while(temp){
		printf("%3d",temp->data);
		temp=temp->rlink;
	}
	printf("]\n");
}

int deleteFront(DQueType *DQ){
	DQNode *old=DQ->front;
	int item;
	if(isEmpty(DQ))return 0;
	else{
		item=old->data;
		if(DQ->front->rlink==NULL){
			DQ->front=NULL;
			DQ->rear=NULL;
		}	
		else{
			DQ->front=DQ->front->rlink;
			DQ->front->llink=NULL;
		}
		free(old);
		return item;
	}
}

int deleteRear(DQueType *DQ){
	DQNode *old = DQ->rear;
	int item;
	if(isEmpty(DQ))return 0;
	else{
		item=old->data;
		if(DQ->rear->llink==NULL){
			DQ->front==NULL;
			DQ->rear=NULL;
		}
		else{
			DQ->rear=DQ->rear->llink;
			DQ->rear->rlink=NULL;
		}
		free(old);
		return item;
	}
}

void main(){

	DQueType *DQ1 = createDQue();
	int data,a,seed=0,count=0,b,c,temp;
	seed=time(0);
	srand(seed);
	b=rand()%100+1;
	c=rand()%100+1;
	if(c>b){
		temp=c;
		c=b;
		b=temp;
	}
	insertFront(DQ1,c);
	insertRear(DQ1,b);
	while(count<3){
		a=rand()%100+1;
		if(a<DQ1->front->data){
			insertFront(DQ1,a);
			count++;
		}
		else if(a>DQ1->rear->data){
			insertRear(DQ1,a);
			count++;
		}
		else continue;
	}

	printDQ(DQ1);
	printf("성적이제일나쁜 학생점수를 뺀 리스트\n");
	data=deleteFront(DQ1);
	printDQ(DQ1);
	printf("성적이 제일 좋은 학생점수를 뺀 리스트\n");
	data=deleteRear(DQ1);
	printDQ(DQ1);	
}
