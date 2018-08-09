#include <stdio.h>
#include <stdlib.h>

typedef struct node_s
{
	int data;
	struct node_s* next;
}node;//linked list structure

int main()
{
	int m;
	scanf("%d\n", &m);

	for (int i = 0; i<m; i++)
	{
		char c;
		scanf("%c\n\n", &c);//fflush(stdin);
		node *a1 = (node *)malloc(sizeof(node));
		node *a2 = (node *)malloc(sizeof(node));
		node *p1 = a1;
		node *p2 = a2;
		while (1)
		{
			char data[18];
			gets(data);
			if (data[0] == 0)
				break;
			else
			{
				p1->data = atoi(data);
				p1->next = (node*)malloc(sizeof(node));
				p1 = p1->next;
				p1->next = NULL;
			}
		}//put datas into the first linked list
		while (1)
		{
			char data[18];
			gets(data);
			if (data[0] == 0)
				break;
			else
			{
				p2->data = atoi(data);
				p2->next = (node*)malloc(sizeof(node));
				p2 = p2->next;
				p2->next = NULL;
			}
		}//put datas into the second linked list
		if (c == '+')
		{
			while (a1->next != NULL && a2->next != NULL)
			{
				int dif = a1->data - a2->data;
				if (dif == 0)
				{
					printf("%d\n", a1->data);
						a1 = a1->next;
						a2 = a2->next;
				}
				else if (dif > 0)
				{
					printf("%d\n", a2->data);
						a2 = a2->next;
				}
				else
				{
					printf("%d\n", a1->data);
						a1 = a1->next;
				}
			}
			while(a1->next != NULL)
			{
				printf("%d\n", a1->data);
				a1 = a1->next;
			}
			while(a2->next != NULL)
			{
				printf("%d\n", a2->data);
				a2 = a2->next;
			}
		}//union of datas, check from the beginning
    else if (c == '-')
		{
			while (a1->next != NULL && a2->next != NULL)
			{
				int dif = a1->data - a2->data;
				if (dif == 0)
				{
					printf("%d\n", a1->data);
						a1 = a1->next;
						a2 = a2->next;
				}
				else if (dif > 0)
        {
						a2 = a2->next;
        }
				else
						a1 = a1->next;
			}
		}//intersection of datas, check from the beginning
		printf("\n");
	}
	return 0;
}
