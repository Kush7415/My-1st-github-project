#include <stdio.h>
#include <stdlib.h>

struct node
{
    int row;
    int column;
    int data;
    struct node *next;
};

void createnewnode(struct node **head, int data,
                   int row, int column)
{
    struct node *temp, *n;
    temp = *head;
    if (temp == NULL)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = data;
        temp->row = row;
        temp->column = column;
        temp->next = NULL;
        *head = temp;
    }
    else
    {
        while (temp->next != NULL)
            temp = temp->next;

        n = (struct node *)malloc(sizeof(struct node));
        n->data = data;
        n->row = row;
        n->column = column;
        n->next = NULL;
        temp->next = n;
    }
}

void PrintList(struct node *head)
{
    struct node *temp, *r, *s;
    temp = r = s = head;

    printf("row position: ");
    while (temp != NULL)
    {

        printf("%d ", temp->row);
        temp = temp->next;
    }
    printf("\n");

    printf("column postion: ");
    while (r != NULL)
    {
        printf("%d ", r->column);
        r = r->next;
    }
    printf("\n");
    printf("Value: ");
    while (s != NULL)
    {
        printf("%d ", s->data);
        s = s->next;
    }
    printf("\n");
}

int main()
{
    int n, i = 0, j = 0;
    printf("enter the number of non zero entries of sparse matrix");
    scanf("%d", &n);
    int row[n];
    int column[n];
    int value[n];

    for (i = 0; i < n; i++)
    {
        printf("enter the row of %d element", i);
        scanf("%d", &row[i]);

        printf("enter the column of %d element", i);
        scanf("%d", &column[i]);

        printf("enter the value of %d element", i);
        scanf("%d", &value[i]);
    }
    int max_row = 0;
    int max_column = 0;

    for (i = 0; i < n; i++)
    {
        if (row[i] > max_row)
        {
            max_row = row[i];
        }
        if (column[i] > max_column)
        {
            max_column = column[i];
        }
    }

    struct node *head = NULL;
    for (i = 0; i < n; i++)
    {
        createnewnode(&head, value[i],
                      row[i], column[i]);
    }

    PrintList(head);

    struct node *top = NULL;
    for (i = 0; i < n; i++)
    {
        createnewnode(&top, value[i], column[i], row[i]);
    }

    PrintList(top);
}
