#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct donaNode {
    char donInvType[30];
    float donAmount;
    struct donaNode* link;
};

struct donaNode* search(struct donaNode* head, struct donaNode* find);
void printList(struct donaNode* head);

int main(void)
{
    int options;
    struct donaNode* head = malloc(sizeof(struct donaNode));
    struct donaNode* tail = malloc(sizeof(struct donaNode));

    head = NULL;

    printf("1. Add an item to the list.\n");
    printf("2. Print the list.\n");
    printf("3. Exit.\n");

    scanf("%d", &options);

    while(options != 3)
    {

        if(options == 1)
        {
            struct donaNode* found = malloc(sizeof(struct donaNode));
            struct donaNode* temp = malloc(sizeof(struct donaNode));
            found = NULL;

            printf("Enter the name and amount of the item you would like to give:\n");
            scanf("%s %f", temp->donInvType, &temp->donAmount);

            found = search(head, temp);

            //If the item wasn't found, we add a new entry at the end of the list
            if(found == NULL)
            {
                temp->link = NULL;

                //If head is NULL then we are adding our first item to the list.
                if (head == NULL)
                {
                    head = temp;
                    tail = temp;
                }
                //We add a NEW item to the list
                else
                {
                    tail->link = temp;
                    tail = temp;
                }
            }
            //The item must have been found, so we simply add on to the amount in storage.
            else
            {
                found->donAmount += temp->donAmount;
            }

        }

        if(options == 2)
        {
            printList(head);
        }

        printf("1. Add an item to the list.\n");
        printf("2. Print the list.\n");
        printf("3. Exit.\n");

        scanf("%d", &options);
    }

    return 0;
}

void printList(struct donaNode* head)
{
    while(head!=NULL)
    {
        printf("%s %.2f\n", head->donInvType, head->donAmount);

        head = head->link;
    }
}

struct donaNode* search(struct donaNode* head, struct donaNode* find)
{
    while(head!=NULL)
    {
        //If the current link is equal to the link we are looking for return that link
        if((strcmp(head->donInvType,find->donInvType)==0))
        {
            return head;
        }
        head = head->link;
    }

    return NULL;
}
