#include <stdlib.h>
#include <stdio.h>

struct node{
	int val;
	struct node* next;
};

struct LinkedList{
	struct node* head;
	struct node* tail;
};

void print_list(struct LinkedList* list){
	if(list->head == NULL)return;
	struct node* current = list->head;
	while(1){
		printf("%d\n", current->val);
		if(current == list->tail)return;
		current = current->next;
	}
}

void insert_node(struct LinkedList* list, int data){
	struct node* new;
	new = (struct node*)malloc(sizeof(struct node));
	new->val = data;
	new->next = NULL;

	//If the list is empty;
	if(list->head == NULL){
		list->head = new;
		list->tail = new;
		return;
	}
	//else
	list->tail->next = new;
	list->tail = new;
}

void delete_node(struct LinkedList* list, int val_to_del){
	struct node* current = list->head;
	//If the node we want to del is first in the list
	if(current->val == val_to_del){
		list->head = current->next;
		free(current);
		return;
	}
	//try to find previous to node we want to del so we could change his next parameter
	while(current->next->val != val_to_del){
		//if we did not find then there is no such element
		if(current->next == list->tail)return;
		current = current->next;
	}
	if(current->next == list->tail)list->tail = current;
	//deleting
	struct node* temp = current->next;
	current->next = temp->next;
	free(temp);
}
//Example of list;
int main(){
	struct LinkedList* myList = (struct LinkedList*)malloc(sizeof(struct LinkedList));
	insert_node(myList, 10);
	insert_node(myList, 20);
	insert_node(myList, 30);
	insert_node(myList, 40);

	print_list(myList);

	delete_node(myList, 30);
	delete_node(myList, 10);

	print_list(myList);
	return 0;
}