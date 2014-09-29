#include<stdio.h>
#include <stdlib.h>
#include "ll_util.h"
int count(struct node* head)
{
	int count = 0;
	struct node* current = head;
	while(current != NULL)
	{
		current = current->next;
		count++;
	}
	return count;
}

void push(struct node **head_ref, int data)
{
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = *head_ref;
	*head_ref = new_node;
	return;
}

void print_list(struct node *head)
{
	struct node* current = head;
	printf("\n");
	while(current != NULL)
	{
		printf("%d->",current->data);
		current = current->next;
	}	
	printf("NULL\n");
}

int get_nth(struct node *head, int n)
{
	struct node* current = head;
	int index = 0;
	while(current != NULL && index != n)
	{
		current = current->next;
		index++;
	}
	if(current == NULL)
	{
		printf("This posigion does not exist");
		return -1;
	}
	return current->data;
}

void delete_list(struct node **head_ref)
{
	struct node* current = *head_ref;
	struct node* next;

	while(current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head_ref = NULL;
}

int pop(struct node **head_ref)
{
	int data;
	struct node* head = *head_ref;
	if(*head_ref == NULL)
	{
		printf("The list is empty");
		return -1;
	}
	*head_ref = head->next;
	data = head->data;
	free(head);
	return data;	
}

void insert_nth(struct node **head_ref, int data, int n)
{
	int index = 0;
	struct node* current = *head_ref;
	struct node* prev;
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = NULL;

	if( *head_ref == NULL && n!=0)
	{
		printf("\nInvalid position of insertion");
		free(new_node);
		return;
	}
	if(*head_ref == NULL || n ==0)
	{
		new_node->next = *head_ref;
		*head_ref = new_node;
		return;
	}
	prev = NULL;
	while(current != NULL && index != n)
	{
		prev = current;
		current = current->next;
		index++;
	}
	if(prev == NULL)
	{
		printf("\n Failure():Index does not exist for insertion");
		return;
	}
	new_node->next = prev->next;
	prev->next = new_node;
	return;
}

void sorted_insert(struct node **head_ref, struct node *new_node)
{

	struct node* current;
	if(new_node == NULL)
	{
		printf(" newnnode created is null");
		return;
	}
	if(*head_ref == NULL || (*head_ref)->data > new_node->data)
	{
		new_node->next = *head_ref;
		*head_ref = new_node;
		return;
	}
	
	current = *head_ref;
	while(current->next != NULL && current->next->data< new_node->data)
	{
		current = current->next;
	}

	new_node->next = current->next;
	current->next = new_node;


}
struct node* create_node(int data)
{
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}
void insert_sort(struct node** head_ref)
{
	struct node* current = *head_ref;
	struct node* next;
	struct node* result = NULL;

	while(current != NULL)
	{
			//Forgot this trick
			next = current->next;
			sorted_insert(&result, current);
			current = next;
	}
	//Forgot this
	*head_ref = result;
	return;
	
}


void append(struct node **a, struct node **b)
{
	struct node* current = *a;
	if(*a == NULL)
		*a = *b;
	else 
	{
		while(current->next != NULL)
			current = current->next;
		current->next = *b;

	}
	*b = NULL;
	return;

}

void front_back_split(struct node* source, struct node** front_ref, struct node** back_ref)
{
	struct node *slow_ptr, *fast_ptr;

	if(source == NULL)
	{
		printf("Split not possible as list is non empty");
		return;
	}	
	slow_ptr = source;
	fast_ptr = source;
	while(fast_ptr != NULL && fast_ptr->next != NULL)
	{
		fast_ptr = fast_ptr->next->next;
		slow_ptr = slow_ptr->next;
	}
	*front_ref = source;
	*back_ref = slow_ptr->next;
	slow_ptr->next = NULL;
	return;
}

struct node* get_middle( struct node* head)
{
	struct node* slow_ptr, *fast_ptr;
	if(head == NULL)
	{
		return NULL;
	}
	slow_ptr = head;
	fast_ptr = head;
	while(fast_ptr!= NULL && fast_ptr->next != NULL)
	{
		fast_ptr = fast_ptr->next->next;
		slow_ptr = slow_ptr->next;
	}
	print_list(head);
	printf("\nMiddle Element is %d", slow_ptr->data);
	return slow_ptr;

}

void remove_duplicate(struct node *head)
{
	struct node *current, *free_node;
	if(head == NULL)
	{	
		printf("/nFailure() Empty List- Cannot remove duplicates");
		return;
	}
	current = head;
	while( current!=NULL && current->next != NULL)
	{
		while(current->next!= NULL && current->next->data == current->data)
		{
			free_node = current->next;
			current->next = current->next->next;
			free(free_node);
		}
		
		current = current->next;
	}
	return;
}

void reverse_list(struct node **head_ref)
{
	struct node *current = *head_ref;
	struct node *prev = NULL;
	struct node *next = NULL;

	while(current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head_ref = prev;
}	
