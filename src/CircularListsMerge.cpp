/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Return Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};

int merge_circularlists(struct node ** head3, struct node ** head4)
{
	if (*head3 == NULL || *head4 == NULL)
		return -1;
	struct node *temp2 = NULL, *temp1 = NULL, *temp = NULL,*head1 = (*head3),*head2 =(*head4);
	temp = head1;
	int i = 0;
	while (temp->next != head1)
	{
		i++;
		temp = temp->next; 
	}
	i++;
	temp->next = NULL;
	temp = head2;
	while (temp->next != head2)
	{
		i++;
		temp = temp->next;
	}
	i++;
	temp->next = NULL;
	int ch;
	if (head2 == NULL)
		return -1;
	temp = head2;
	while (head1 != NULL)
	{
		ch = head1->data;
		while (ch > temp->data)
		{
			temp1 = temp;
			temp = temp->next;
			if (temp == NULL)
				break;
		}
		if (temp1 != NULL)
			temp1->next = head1;
		temp2 = head1->next;
		head1->next = temp;
		if (temp == head2)
			head2 = head1;
		head1 = temp2;
	}
	temp = head2;
	while (temp->next!= NULL)
	{
		temp = temp->next;
	}
	temp->next = head2;
	*head3 = head2;
	return i;
}

