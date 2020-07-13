#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#define BUF_SIZE 4096
typedef char elemant;
typedef struct treeNode{
	int  key;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;

treeNode* insertNode(treeNode *p,int x){
	treeNode* newNode;
	if(p==NULL){
		newNode=(treeNode*)malloc(sizeof(treeNode));
		newNode->key=x;
		newNode->left=NULL;
		newNode->right=NULL;
		return newNode;
	}
	else if(x<p->key)p->left=insertNode(p->left,x);
	else if(x>p->key)p->right=insertNode(p->right,x);
	else printf("\n 이미같은 키가 있습니다.\n");

	return p;

}

void preorder(treeNode* root){
	if(root){
		printf("%d ",root->key);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(treeNode* root){
	if(root){
		inorder(root->left);
		printf("%d ",root->key);
		inorder(root->right);	
	}
}

void postorder(treeNode* root){
	if(root){
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->key);
	}
}
int main(int argc,char *argv[])
{
	int  a;
	FILE  *in;
	if(argc!=2)exit(1);
	in=fopen(argv[1],"r");
	if(in == NULL)exit(2);
	fscanf(in,"%d",&a);
	int m[a],i=0;
	while(1)
	{	
		if(i==a)break;
		fscanf(in,"%d",&m[i]);
		i++;
	}
	printf("%d\n",a);
	for(int z=0;z<i;z++){
	printf("%d\n",m[z]);
	}
	fclose(in);
	
	treeNode *root =NULL;
	root = insertNode(root,m[0]);
	for(int q=1;q<a;q++){
		insertNode(root,m[q]);
	}
	printf("전위순회\n");
	preorder(root);
	printf("\n중위순회\n");
	inorder(root);
	printf("\n후위순회\n");
	postorder(root);
	printf("\n");
	return 0;
}
