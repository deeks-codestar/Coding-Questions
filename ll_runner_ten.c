#include<stdio.h>
#include<stdlib.h>
#include "ll_util.h"

int main()
{
	struct node *head;
	push(&head,5);
	push(&head,7);
	push(&head,10);
	push(&head,27);
	push(&head,10);
	push(&head,1);
	push(&head,1);
	push(&head,27);
	push(&head,27);
	printf("\nThe list before sorting");
	print_list(head);
	insert_sort(&head);
	printf("\nThe list after sorting");
	print_list(head);
	remove_duplicate(head);
	print_list(head);
	reverse_list(&head);
	print_list(head);

	return 0;
}
