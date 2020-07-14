//-----------------------------
// SNUMs60161656	:
// MAME Kim min suk  	:
//-----------------------------

#include <stdio.h>
#include <stdlib.h>

//연결리스트를 구현할 구조체
typedef struct NODE{
	int data;
	struct NODE* next;
}node;

typedef struct {
	struct NODE* next;
}H_node;

int main(void) {
	
	H_node* head = (H_node*)malloc(sizeof(H_node)); //헤드(시작)노드의 메모리 공간 할당  malloc 이용
	head->next = NULL;  //초기 값으로 head 가 가리키는 곳은  NULL 설정;

	node* node1 = (node*)malloc(sizeof(node)); // 새 노드 의 메모리 공간 할당  malloc 이용
	node1->next =head->next; //  새 노드의  next 값을 head 가 가리키는 곳으로 설정;
	node1->data = 10;
	head->next = node1; //  head 노드를 새노드로 가리키키 ;

	node* node2 = (node*)malloc(sizeof(node)); // 새 노드 의 메모리 공간 할당  malloc 이용
	node2->next =node1; //  node2 next 값을 node1 으로 설정;
	node2->data = 20;
	head->next =node2; // node1 을 새로운 노드로 가리키키 

	node* curr = head->next; //순회용 노드 생성
	//curr의  next 가 널이 아닐때 까지 순환하기 
	while(curr!=NULL){
		printf("%d\n", curr->data);
		curr=curr->next;//curr 을 curr의 next 가 가리키는 곳으로 가리키키 
	}

	free(head);
	free(node1);
	free(node2);
	return 0;
}
