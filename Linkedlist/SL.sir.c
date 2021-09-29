/*  Implementation of a Singly Linked List with standard interface methods*/
/*    Interrface methods implemented are : 
    insert_begin : Inserts a Node at the beginning of List 
    delete_begin:  Deletes the First Node of list and returns the contents
    delete_end :   Deletes the Last Node of the list and returns the contents
    display_list:  Prints the information contained in the Nodes sequentially 
*/    

#include<stdio.h>
#include<stdlib.h> // for malloc 

struct Node
{
    int info; //the information part of a Node 
    struct Node* link; // points to the next Node
} typedef Node;


struct List
{
    Node *start ; // pointer to the first Node of the list
}typedef List;


int insert_begin( List* list, int item)
{
    Node * newNode =(Node*)malloc(sizeof(Node));// allocate memory for newnode
    if( newNode == NULL)
         return 1; // failure to insert node because of insufficient memory
     
    newNode->info = item ; // add data in the newNode
    newNode->link = list->start;// newNode points to the (current) first Node
    list->start = newNode;// newNode is now the first node, update start 
    return 0;// successful insertion of node 
}//end of insert_begin


int insert_end( List * list, int item)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    if( newNode == NULL)
        return 1; // failure to insert node because of insufficient memory
        
    newNode->info = item;// assign data in the new node
    newNode->link = NULL;// newNode is going to be the last node of list
    
    if( list->start == NULL ) // if list is empty  
       {
        list->start = newNode;
        return 0; 
       }
    // iterate through all nodes and reach upto the current last node
    Node * temp = list->start; // iterator set to the first Node
    while( temp->link != NULL)
        temp = temp->link;

    temp->link = newNode; // current last node now points to newNode
    return 0; // successful insertion 
}//end of insert_end

int delete_begin( List *list)// list is passed by reference 
{
    if(list->start == NULL)// list is empty
        return -1;
    else
    {
        int last_element = list->start->info;// store the info of 1st node
        Node *save = list->start;// save the address of the first node
        list->start = list->start->link;// update start 
        free(save);// release the memory of the node to be deleted 
        return last_element;// return the first element 
    }
}//end of list


int delete_end(List *list)
{
    Node * save, *temp;
    int last_element;
    if(list->start == NULL) // if list is empty
        return -1;
    if( list->start->link == NULL)// only 1 node in list
    {
        last_element = list->start->info;// store the info of first node
        save = list->start;// save points to first node 
        list->start = save->link;// alternatively temp->link->link 
        free(save);// release the memory of the first node 
        return last_element;
         /* alternatively call the delete_begin( list) 
           return delete_begin(list);  */
    }
    temp = list->start;
    while( temp->link->link != NULL)// iterate until the last but one Node
        temp = temp->link; 
    save = temp->link;// save the address of the last node for releasing
    last_element= temp->link->info; // store the info of last node 
    temp->link = save->link; // update links 
    free( save); // release the memory of the last node
    return last_element;
}// end of delete_end 


void display_list(List list) 
{
    if(list.start == NULL) // No nodes in the list
    {
        printf("\nEmpty List\n");
        return;
    }
    printf("\n List is : ");
    Node *temp = list.start;// initialize an iterator with start
    while( temp != NULL ) // iterate over all the nodes of the list
    {
        printf("%5d", temp->info); // print the info part of the current node
        temp = temp->link;
    }//end of while
    
}//end of display_list
    
    
void main()
{
    List l;
    l.start = NULL;
    display_list(l); // Empty List
    insert_begin(&l, 100); // start -> 100
    insert_begin(&l, 200); // start -> 200 -> 100
    display_list(l); //  200 100
    
    printf("\n Deleted Element from First = %d ",delete_begin(&l));// 200
    display_list(l); //  100
   
    insert_end(&l, 400);//  Start ->100->400
    display_list(l); //  100 400
    
    printf("\n Deleted Element from End = %d ",delete_end(&l));// 400
    display_list(l); //  100
    printf("\n Deleted Element from End = %d ",delete_end(&l));// 100
    display_list(l); //  Empty List
    printf("\n Deleted Element from End is %d ", delete_end(&l)); // -1
    
}//end of main





