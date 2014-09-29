#include<stdio.h>
#include<stdlib.h>
#include "ll_util.h"

void recursive_reverse(struct node **head_ref)
{
	struct node *rest;
	struct node *head = *head_ref;
	if(*head_ref == NULL)
		return;
	if((*head_ref)->next == NULL)
		return;
	rest = (*head_ref)->next;
	recursive_reverse(&rest);
	
	head->next->next = head;
	head->next = NULL;
	
	*head_ref = rest;
	

}

int main()
{
	struct node *head;
//	push(&head,1);
//	push(&head,2);
//	push(&head,3);
	print_list(head);
	recursive_reverse(&head);
	print_list(head);
	return 0;
}
