#include<stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	node *right;
	node *left;
};

node *root=NULL;
node *prev=NULL;

void add( int value){
	node *new_node=(node *)malloc(sizeof(node));
	new_node->data=value;
	new_node->left=NULL;
	new_node->right=NULL;
	if(root==NULL){
		root=new_node;
	}
	else{
		node *temp=root;
		while(temp!=NULL){
			prev=temp;
			if(new_node->data < temp->data){
				temp=temp->left;
			}
			else{
				temp=temp->right;
			}
		}
		if(new_node->data < prev->data){
			prev->left=new_node;
		}
		else{
			prev->right=new_node;
		}
	}
}


void add_with_rec(node *tree,node *new_n){
	node *new_node=(node *)malloc(sizeof(node));
	new_node=new_n;
	if(root==NULL){
		root=new_node;
	}
	else{
		if(new_node->data < tree->data){
			if(tree->left ==NULL){
				tree->left=new_node;
			}
			else{
				add_with_rec(tree->left,new_node);
			}
		}
		
		else{
			if(tree->right == NULL){
				tree->right=new_node;
			}
			else{
				add_with_rec(tree->right,new_node);
			}
		}
	}
}

node *search(node *root,int searched){
	if(root==NULL) return NULL;
	
	if(searched < root->data){
		return search(root->left,searched);
	}
	else if(searched > root->data){
		return search(root->right,searched);
	}
	else return root;
}



node *search(int searched){
	node *temp=root;
	while(temp!=NULL){
		if(temp->data == searched) return temp;
		else if( searched < temp->data) temp=temp->left;
		else temp=temp->right;
	}
	return NULL;
}


void show(node *root){
	if(root!=NULL){
		show(root->left);
		printf("%d",root->data);
	}
		show(root->right);
}




int main(){
	int num=1;
	
	while(num>-1){
		printf("please, enter a number: \n");
		printf("(if want to leave,enter under zero a number.)");
		scanf("%d",&num);
		add(num);
	}
	show(root);
}












