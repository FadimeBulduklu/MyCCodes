#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	int height;
	struct node *left;
	struct node *right;
};

struct node *root=NULL;

void inorder(node *root){ //sol kök sað
	if(root!=NULL){
		inorder(root->left);
		printf("%d",root->data);
		inorder(root->right);
	}
}

void preorder(struct node *root){ // kök sol sað
	if(root!=NULL){
		printf("%d",root->data);
		inorder(root->left);
		inorder(root->right);
	}
}

void postorder (struct node *root){ // sol sað kök
	if(root!=NULL){
		inorder(root->left);
		inorder(root->right);
		printf("%d",root->data);
	}
}

int find_to_height(node *root2){
	if(root2==NULL){
		return -1;
	}
	else{
		int left=0,right=0;
		left=find_to_height(root2->left);
		right=find_to_height(root2->right);
		
		if(left>right) return left++;
		else return right++;
	}
	
}

node *get_value(){
	node *new_node=(node*) malloc(sizeof(node));
	printf("sayi girin: ");
	scanf("%d",&(new_node->data));
	new_node->left=NULL;
	new_node->right=NULL;
	return new_node;
}

void add(node *yeni){
	node *temp,*prev;
	if(root==NULL) root=yeni;
	else{
		temp=root;
		while(temp!=NULL){
			prev=temp;
			if(yeni->data < temp->data){
				temp=temp->left;
			}
			else{
				temp=temp->right;
			}
		}
		if(yeni->data < prev->data){
			prev->left=yeni;
		}
		else{
			prev->right=yeni;
		}
	}
}

void add_rec(node *root,node *new_node){
	if(root==NULL) root=new_node;
	else{
		if(new_node->data < root->data){
			if(root->left==NULL){
				root->left=new_node;
			}
			else add_rec(root->left,new_node);
		}
		else {
			if(root->right==NULL){
				root->right=new_node;
			}
			else add_rec(root->right,new_node);
		}
	}
}

struct node *search(node* aranan){
	struct node* current;
	current=root;
	while(current->data!=aranan->data){
		if(current!=NULL){
			printf("%d",current->data);
			if(aranan->data < current->data){
				current=current->left;
			}
			else{
				current=current->right;
			}
		
		}
		if(current==NULL){
			printf("aradiginiz sayi agacta yoktur.");
			return NULL;
		}	
	}
	printf(" %d" ,current->data);
	return current;
}


int main(){
	int secim ;
	
	while(1){
		printf("\n1->sayi ekle\n");
		printf("2->inorder siralama\n");
		printf("3->preorder siralama\n");
		printf("4->postorder siralama\n");
		printf("5->Arama yap\n");
		printf("6->Agac yuksekligi bulma\n");
		printf("7->cikis\n");
		printf("seciminizi yapin: \n");
		scanf("%d",&secim);
		switch(secim){
			case 1:
				add(get_value());
				break;
			case 2:
				inorder(root);
				break;
			case 3:
				preorder(root);
				break;
			case 4:
				postorder(root);
				break;
			case 5:
				printf("aranacak sayi: ");
				node *num;
				scanf("%d",&num);
				search(num);
				break;
			case 6:
				int level=find_to_height(root);
				printf("yukseklik: %d",level);
				break;
			
		}	
	}
}




















