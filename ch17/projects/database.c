#include<stdio.h>


#include<stdlib.h>
#include "database.h"
#include "word.h"
int find_part(int find,struct part inventory[]);
void search(struct part inventory[]);
void insert(struct part inventory[],int *num_parts);
void print(struct part inventory[],int num_parts);
void update(struct part inventory[]);
int compare(const void *p,const void *q){

	return (((struct part *)p)->number -((struct part *)q)->number);
}
int main(void){

	struct part *inventory;
	inventory = malloc(MAX_SIZE* sizeof(struct part));
	int num_parts = 0;
	char k;
	char ch;
	printf("ENTER S FOR SEARCH I FOR INSERT P FOR PRINT ALL\n U FOR UPDATE AND Q QUIT\n");
	for(;;)
	{
		if(num_parts == MAX_SIZE){                          inventory = realloc(inventory,(2*num_parts)*sizeof(struct part));                                                           }


	
		printf("Enter the operation :");
		scanf("%c",&ch);
		while( k = getchar() != '\n')
			;
		switch(ch){
			case 'S':
				search(inventory);
				break;
			case 'Q':
				return 0;
				break;
			case 'I':
				insert(inventory,&num_parts);
				break;
			case 'U':
				update(inventory);
				break;
			case 'P':
				print(inventory,num_parts);
				break;
			default:
				printf("You have entered the wrong command\n");
		}


	}
	return 0;
}


int find_part(int find,struct part inventory[])
{
	for(int i = 0; i < MAX_SIZE;i++)
	{
		if(inventory[i].number == find){
			return 0;

		}
	}
	return -1;
}

void insert(struct part inventory[],int *num_parts)
{
	int num;
	printf("ENTER THE PART NUMBER:");
	scanf("%d",&num);
	if(find_part(num,inventory) >= 0){
		printf("The part already exists\n");
		return;
	}
	if(MAX_SIZE == *num_parts)
	{
		printf("The data is full\n");
		printf("New memory allocated");

	}
	inventory[*num_parts].number = num;
	printf("ENTER THE PART NAME:");
	read_line(inventory[*num_parts].name,max_line_len+1);
	printf("Enter the number:");
	scanf("%d",&inventory[*num_parts].on_hand);
	(*num_parts)++;
}

void search(struct part inventory[]){
	int num;
	printf("Enter the part number:");
	scanf("%d",&num);
	int i = find_part(num,inventory);
	if(i < 0)
		printf("The part name does not exists\n");
	else{
		printf("The part number :");
		printf("%d\n",inventory[i].number);
		printf("The part name : %s\n",inventory[i].name);
		printf("The number : %d\n",inventory[i].on_hand);
	}
}

void update(struct part inventory[])
{
	int num;
	printf("Enter the part number:");                 scanf("%d",&num);
	int i = find_part(num,inventory);
	if(i < 0)                                                 printf("The part name does not exists\n");
	else{
		printf("The number value of %d part number :",num);
		scanf("%d",&inventory[i].on_hand);
	}
}
void print(struct part inventory[],int num_parts){
	qsort(inventory,num_parts,sizeof(struct part),compare);
	printf("Part number  name                value \n");
	for(struct part *p = inventory; p < num_parts+ inventory;p++)
	{
		printf("%d          %-20s %d\n",p->number,p->name,p->on_hand);
	}
}


