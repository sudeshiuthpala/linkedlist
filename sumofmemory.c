#include <stdio.h>
#include <stdlib.h>
int main(){
	int num,i,*ptr,sum=0;
	printf("Enter the element: ");
	scanf("%d",&num);
	
	ptr=(int*)malloc(num*sizeof(int));
	if(ptr==NULL){
		printf("memory is not allocate");
		exit(0);
	}
	printf("Enter the array element: ");
	for(i=0;i<num;++i){
		scanf("%d",ptr+i);
		sum+=*(ptr+i);
	}
	printf("sum = %d",sum);
	free(ptr);
	return 0;
}

