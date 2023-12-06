#include <stdio.h>
#include <malloc.h>
//Linked Lists

struct Node
{
	int data;
	struct Node* next;
};

struct Node createNode(int data)
{
	struct Node* temp = NULL;
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = NULL;
	return *temp;
}

void printList(struct Node* head)
{
	struct Node* temp = head;
	while (temp != NULL)
	{
		printf("\n%d ", temp->data);
		temp = temp->next;
	}
}

int main()
{

	int nodes;

	struct Node* head = NULL;
	head = (struct Node*)malloc(sizeof(struct Node));

	printf("Enter the amount of nodes: ");
	scanf_s("%d", &nodes);

	for (int i = 0; i < nodes; i++)
	{
		struct Node* temp = NULL;
		temp = (struct Node*)malloc(sizeof(struct Node));
		temp->data = i;
		temp->next = NULL;

		if (i == 0)
			head = temp;
		else
		{
			struct Node* temp2 = head;
			for (int j = 0; j < i -1; j++)
			{
				temp2 = temp2->next;
			}
			temp2->next = temp;
		}
	}

	struct Node* temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}

	struct Node* temp3 = head;
	int sum = 0;
	while (temp3 != NULL)
	{
		sum = sum + temp3->data;
		temp3 = temp3->next;
	}

	printf("\n%d", sum);

	struct Node head2 = createNode(1);
	printList(&head2);
}