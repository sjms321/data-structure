#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

typedef struct student
{
	char name[5];
	int korea;
	int math;
	int eng;
	int avg;
	int total;
	struct student *link;
}student;

typedef struct {
	student *head;
}student_h;

student_h *create(void)
{
	student_h *L;
	L = (student_h*)malloc(sizeof(student_h));
	L->head = NULL;
	return L;
}

void print(student_h*L) {
	student *p;
	p = L->head;
	printf("이름 국어 수학 영어 평균 총점수\n");
	while (p != NULL) {
		printf("%s %3d %4d %4d %4d %5d\n", p->name,p->korea,p->math,p->eng,p->avg,p->total);
		p = p->link;
		
	}

}

void first(student_h *L, int w, int e, int r, int t,int y) {
	student *newst;
	char *c;
	char name[3] = { rand() % 26+65,rand() % 26 + 65,rand() % 26 + 65 };
	c = name;
	newst = (student*)malloc(sizeof(student));
	strcpy(newst->name, c);
	newst->korea = w;
	newst->math= e;
	newst->eng= r;
	newst->avg= t;
	newst->total=y;
	newst->link = L->head;
	L->head = newst;
}

	student*search(student_h* L,int x){
		student *temp;
		int y;
		temp=L->head;
		while(temp!=NULL){
					
			if(temp->avg==x)return temp;
				else temp=temp->link;
				}	return temp;
		}

void delete(student_h* L, student* p) {
	student *pre;
	if (L->head == NULL) return;
	if (L->head->link == NULL) {
		free(L->head);
		L->head = NULL;
		return;
	}
	else if (p == NULL) return;
	else {
		pre = L->head;
		while (pre->link != p) {
			pre = pre->link;
		}
		pre->link = p->link;
		free(p);
	}
}

void main()
{	
	student *p;
	int seed=0,i;
	int q,w,e,r,total;
	int Min=101;
	seed=time(0);
	srand(seed);
	student_h *L;
	L=create();
	for(int i=0;i<5;i++){
	q=rand()%100+1;
	w=rand()%100+1;
	e=rand()%100+1;
	total=q+w+e;
	r=total/3;
	first(L,q,w,e,r,total);	
	}

	print(L);
	
	student *temp;
	temp=L->head;
	while(temp!=NULL){
	if(Min > temp->avg)Min=temp->avg;
	temp=temp->link;
	}
	p=search(L,Min);
	printf("평균이 가장 낮은 학생 제외\n");	
	printf("평균이 가장 낮은 학생 이름:%s 점수: %d\n",p->name,p->avg);
	delete(L,p);
	print(L);
}
