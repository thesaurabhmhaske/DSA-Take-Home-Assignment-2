#include <stdlib.h>
#include <stdio.h>
#include "csl102_th2.h"

void printlist(nodeQ_t* head){
    if(EMPTYNODE == head ) return;

    while (head)
    {
        printf("%d -->",head->data);
        head = head->next;
    }
    printf("EMPTYNODE\n");
    
}

int main()
{
    nodeQ_t* head= EMPTYNODE;
    nodeQ_t* O= (nodeQ_t*)malloc(sizeof(nodeQ_t));
    nodeQ_t* E= (nodeQ_t*)malloc(sizeof(nodeQ_t));
    short c1[10] ={4,6,7,19,5,24,45,1,1,8};
    short c2[7] ={81,15,44,45,1,1,8};
    short arr[7] = {22,15,72,72,11,23,1},p;
    head = createList(arr, 7);
    nodeQ_t* h1= createList(c1,10);
    nodeQ_t* h2= createList(c2,7);

    for(short i=0; i< 7 ;i++){
        nodeQ_t* newNode = createList(arr+i, 7);
        nodeQ_t* tail = newNode;
    }
    
        printlist(head);
    printf("enter the value to be remove:\n");
    scanf("%hd",&p);
    
        if(LIST_TRUE == deleteNodes(head,&head,p))
        printlist(head);
        
        if(LIST_TRUE == splitLists(head,&O,&E)){
        printlist(O);
        printlist(E);}
        
        if(LIST_TRUE == getCommonSubList(h1,h2,&h1))
        printlist(h1);
        
return 0;
}