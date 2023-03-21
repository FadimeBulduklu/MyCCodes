#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *dugumOlustur(int veri){
	struct node *yeni=(struct node *) malloc(sizeof(struct node));
	yeni->data=veri;
	yeni->left=NULL;
	yeni->right=NULL;
	
	return yeni;
}

struct node * ekle(struct node *root,int veri){
	if(root==NULL){
		root=dugumOlustur(veri);
	}
	else{
		if(veri < root->data){
			root->left=ekle(root->left,veri);
		}
		else{
			root->right=ekle(root->right,veri);
		}
	}
	return root;
}

void preorder(struct node *root){ //kok sol sað
	if(root!=NULL){
		printf("%d",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(struct node *root){ //sol kok  sað
	if(root!=NULL){
		inorder(root->left);
		printf("%d",root->data);
		inorder(root->right);
	}
}

void postorder(struct node *root){ //sol sað kok 
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d",root->data);
	}
}



int main(){
	struct node *kok=NULL;
	int n,i;
	
	while(i<5){
		printf("sayi: ");
		scanf("%d",&n);
		kok=ekle(kok ,n);
		i++;
	}
	printf("sayi: ");
	scanf("%d",&n);
	kok=ekle(kok ,n);
	
	
	printf("inorder: ");
	inorder(kok);
	
	printf("\n");
	printf("preorder: ");
	preorder(kok);
	
	
	printf("\n");
	printf("postorder: ");
	postorder(kok);
}









