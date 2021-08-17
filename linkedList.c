#include <stdio.h>
#include <stdlib.h>
struct slinklist
{
	int data;
	struct slinklist* next;	
};
typedef struct slinklist node;
node* start=NULL;

node* getnode(){
	node* newnode;
	newnode=(node *)malloc(sizeof(node));
	printf("Enter data: ");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	return newnode;	
}

void createlist(int n){
	int i;
	node* newnode;
	node* temp;
	for(i=0;i<n;i++){
		newnode=getnode();
		if(start==NULL){
			start=newnode;
		}
		else{
			temp=start;
			while(temp->next!=NULL){
				temp=temp->next;
				//printf("%d",temp->data);
			}
			temp->next=newnode;	
		}	
	}
}

struct node* display(struct node *start){
	node* ptr;
	ptr=start;
	while(ptr!=NULL){
		printf("%d\n",ptr->data);
		ptr=ptr->next;
	}
	return start;
}

int countLink(node* start){
	int count=0;
	node* ptr;
	ptr=start;
	while(ptr!=NULL){
		count++;
		ptr=ptr->next;
	}	
	return count;
}

struct node* search(struct node *start,int val){
	node* ptr;
	int pos;
	ptr=start;
	while(ptr!=NULL){
		if(val==ptr->data){
			int pos=ptr;
			break;
		}
		else{
			ptr=ptr->next;
		}
	}
	//pos=NULL;
	return pos;
}

int main(){
	createlist(5);
	display(start);
	printf("%d\n",countLink(start));
	printf("%d\n",search(start,2));
}
