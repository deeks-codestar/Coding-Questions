#include "ll_util.h"
#include<stdio.h>
#include<stdlib.h>

int main()
{
	struct node* head = NULL;
	printf("Length of the list is %d", count(head));
	push(&head, 1);
	push(&head,2);
	push(&head,3);
	push(&head,4);
	push(&head,5);
	print_list(head);
	struct node* node1 = (struct node*)malloc(sizeof(struct node));
	node1->data = 6;
	node1->next = NULL;
	print_list(head);
	sorted_insert(&head, node1);
	print_list(head);
	insert_sort(&head);
	print_list(head);
	printf("\nThe popped element is %d",pop(&head));
	print_list(head);
	insert_nth(&head,5,0);
	print_list(head);
	insert_nth(&head,6,5);
	print_list(head);
	insert_sort(&head);
	print_list(head);
	delete_list(&head);
	print_list(head);
	return 0;

}
