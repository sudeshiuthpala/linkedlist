#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node* next;	
};
//typedef struct slinklist node;
struct node* start=NULL;

//node* getnode(){
//	node* newnode;
//	newnode=(node *)malloc(sizeof(node));
//	printf("Enter data: ");
//	scanf("%d",&newnode->data);
//	newnode->next=NULL;
//	return newnode;	
//}

struct node* createlist(struct node *start){
	int num;
	struct node *newnode,*ptr;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	if(start==NULL){
		newnode->next=newnode;
		start=newnode;
	}
	else{
		ptr=start;
		while(ptr->next!=NULL){
			ptr=ptr->next;
				//printf("%d",temp->data);
		}
		ptr->next=newnode;	
		newnode->next=start;
	}
	printf("Enter data: ");
	scanf("%d",&num);
	return start;
		
}

struct node *display(struct node *start)
{
struct node *ptr;
ptr=start;
while(ptr -> next != start)
{
printf("\t %d", ptr -> data);
ptr = ptr -> next;
}
printf("\t %d", ptr -> data);
return start;
}
struct node *insert_beg(struct node *start)
{
struct node *new_node, *ptr;
int num;
printf("\n Enter the data : ");
scanf("%d", &num);
new_node = (struct node *)malloc(sizeof(struct node));
new_node -> data = num;
ptr = start;
while(ptr -> next != start)
ptr = ptr -> next;
ptr -> next = new_node;
new_node -> next = start;
start = new_node;
return start;
}
struct node *insert_end(struct node *start)
{
struct node *ptr, *new_node;
int num;
printf("\n Enter the data : ");
scanf("%d", &num);
new_node = (struct node *)malloc(sizeof(struct node));
new_node -> data = num;
ptr = start;
while(ptr -> next != start)
ptr = ptr -> next;
ptr -> next = new_node;
new_node -> next = start;
return start;
}
struct node *delete_beg(struct node *start)
{
struct node *ptr;
ptr = start;
while(ptr -> next != start)
ptr = ptr -> next;
ptr -> next = start -> next;
free(start);
start = ptr -> next;
return start;
}
struct node *delete_end(struct node *start)
{
struct node *ptr, *preptr;
ptr = start;
while(ptr -> next != start)
{
preptr = ptr;
ptr = ptr -> next;
}
preptr -> next = ptr -> next;
free(ptr);
return start;
}
struct node *delete_after(struct node *start)
{
struct node *ptr, *preptr;
int val;
printf("\n Enter the value after which the node has to deleted : ");
scanf("%d", &val);
ptr = start;
preptr = ptr;
while(preptr -> data != val)
{
preptr = ptr;
ptr = ptr -> next;
}
preptr -> next = ptr -> next;
if(ptr == start)
start = preptr -> next;
free(ptr);
return start;
}
struct node *delete_list(struct node *start)
{
struct node *ptr;
ptr = start;
while(ptr -> next != start)
start = delete_end(start);
free(start);
return start;
}
int main(){
	//display(start);
	//printf("%d\n",countLink(start));
	//printf("%d\n",search(start,2));

}
