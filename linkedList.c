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

node* insert_beg(node* start,int num){
	node* newnode;
	newnode=(node *)malloc(sizeof(node));
	newnode->data=num;
	newnode->next=start;
	start=newnode;
	return start;
}

node* deletion_beg(node* start){
	node* ptr;
	ptr=start;
	start=start->next;
	free(ptr);
	return start;
}

node* insert_end(node* start,int num){
	node *newnode,*ptr;
	newnode=(node *)malloc(sizeof(node));
	newnode->data=num;
	newnode->next=NULL;
	ptr=start;
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	ptr->next=newnode;
	return start;
}
node* deletion_end(node* start){
	node *preptr,*ptr;
	ptr=start;
	while(ptr->next!=NULL){
		preptr=ptr;
		ptr=ptr->next;
	}
	ptr->next=NULL;
	free(ptr);
	return start;
}

node* insert_after(node*start,int val,int num){
	node *newnode,*ptr,*preptr;
	newnode=(node *)malloc(sizeof(node));
	newnode->data=num;
	ptr=start;
	preptr=ptr;
	while(preptr->data!=val){
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=newnode;
	newnode->next=ptr;
	return start;
}
node* insert_before(node*start,int val,int num){
	node *newnode,*ptr,*preptr;
	newnode=(node *)malloc(sizeof(node));
	newnode->data=num;
	ptr=start;
	//preptr=ptr;
	while(ptr->data!=val){
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=newnode;
	newnode->next=ptr;
	return start;
}
node *delete_node(node *start,int val)
{
	node *ptr, *preptr;
	ptr = start;
	if(ptr -> data == val)
	{
		start = delete_beg(start);
		return start;
	}
	else
	{
		while(ptr -> data != val)
		{
			preptr = ptr;
			ptr = ptr -> next;
		}
		preptr -> next = ptr -> next;
		free(ptr);
		return start;
	}
}
node* display(node *start){
	node* ptr;
	ptr=start;
	while(ptr!=NULL){
		printf("%d\n",ptr->data);
		ptr=ptr->next;
	}
	return start;
}

int main(){
	createlist(6);
	//display(start);
	//printf("%d\n",countLink(start));
	//printf("%d\n",search(start,2));
	deletion_beg(start);
	display(start);
}
