#include "csl102_th2.h"
#include <stdio.h>
#include <stdlib.h>


#define EMPTYNODE 0

nodeQ_t *createNode(int val)
{
    nodeQ_t *ass2 = (nodeQ_t *)malloc(sizeof(struct nodeQ));
    ass2->data = val;
    ass2->next = NULL;
    return (ass2);
}

nodeQ_t *createList(short values[], short sz)
{
    nodeQ_t *head;
    nodeQ_t *tail;
    nodeQ_t *ass2;
    head = createNode(values[0]);
    tail = head;
    for (int m = 1; m < sz; m++)
    {
        ass2 = createNode(values[m]);
        tail->next = ass2;
        tail = ass2;
    }
    return (head);
}

status_t deleteNode(nodeQ_t *head, short index)
{
    if (EMPTYNODE == head)
        return (LIST_FALSE);
    short counter = 1;
    nodeQ_t *prev = head;
    nodeQ_t *ass2 = prev->next;
    while (ass2)
    {
        if (counter == index)
        {
            prev->next = ass2->next;
            free(ass2);
            return (LIST_TRUE);
        }
        else
        {
            prev = ass2;
            counter++;
            ass2 = ass2->next;
        }
    }
    return (LIST_FALSE);
}

status_t deleteNodes(nodeQ_t *head, nodeQ_t **out_newHead, short in_data)
{
    if (EMPTYNODE == head)
        return (LIST_FALSE);
    short index = 0;
    nodeQ_t *ass2 = head;
    while (ass2)
    {
        if (in_data == ass2->data)
        {
            if (index == 0)
            {
                ass2 = ass2->next;
                free(head);
                head = ass2;
            }
            else
            {
                ass2 = ass2->next;
                deleteNode(head, index);
            }
        }
        else
        {
            index++;
            ass2 = ass2->next;
        }
        *out_newHead = head;
    }
    return (LIST_TRUE);
}

status_t splitLists(nodeQ_t *head, nodeQ_t **out_evenList, nodeQ_t **out_oddList)
{
    if (EMPTYNODE == head || EMPTYNODE == out_evenList || EMPTYNODE == out_oddList)
        return (LIST_FALSE);
    nodeQ_t *evenHead = head;
    nodeQ_t *oddHead = head->next;
    nodeQ_t *prevEven = head;
    nodeQ_t *prevOdd = head->next;
    nodeQ_t *ass2 = head->next->next;
    short index = 2;
    while (ass2)
    {
        if (index % 2 == 0)
        {
            prevEven->next = ass2;
            prevEven = ass2;
            ass2 = ass2->next;
            index++;
        }
        else
        {
            prevOdd->next = ass2;
            prevOdd = ass2;
            ass2 = ass2->next;
            index++;
        }
    }
    prevEven->next = EMPTYNODE;
    prevOdd->next = EMPTYNODE;
    *out_oddList = oddHead;
    *out_evenList = evenHead;
    return (LIST_TRUE);
}

status_t getCommonSubList(nodeQ_t *head1, nodeQ_t *head2, nodeQ_t **out_commonSubList)
{
    if (EMPTYNODE == head1 || EMPTYNODE == head2)
        return (LIST_FALSE);
    int count = 0;
    nodeQ_t *ass02 = head1;
    nodeQ_t *tempHead1 = head1;
    nodeQ_t *ass002 = head2;
    while (tempHead1)
    {
        ass02 = tempHead1;
        ass002 = head2;
        while (ass002)
        {
            if (ass02->data == ass002->data)
            {
                count++;
                ass002 = ass002->next;
                ass02 = ass02->next;
            }
            else
            {
                ass002 = ass002->next;
            }
        }
        if (count > 0)
        {
            *out_commonSubList = tempHead1;
            return (LIST_TRUE);
        }
        tempHead1 = tempHead1->next;
    }
    return (LIST_FALSE);
}