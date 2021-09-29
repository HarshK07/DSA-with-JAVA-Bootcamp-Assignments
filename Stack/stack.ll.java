/*  Implementation of a Stack over a Linked List */
/*  Stack implemented over a Linked List with standard interface methods 

Push(Stack,item) - Adds an element <item> onto the top of Stack 
Pop( ) - removes and returns an element from top of Stack , returns -1 on underflow
isEmpty(Stack) - returns TRUE if Stack is empty , FALSE otherwise
peek( ) - returns the top element of the Stack without changing the state of Stack

*/    

#include<stdio.h>
#include<stdlib.h> // for malloc 

#define TRUE 1
#define FALSE 0 

struct Node
{
    int info; //the information part of a Node 
    struct Node* link; // points to the next Node
} typedef Node;

struct Stack
{
    Node *top ; // pointer to the first Node of the list that models the Stack
}typedef Stack;

int isEmpty(Stack s)
{
    return s.top == NULL ? TRUE:FALSE; 
}

int push( Stack* stack, int item)
{
    Node * newNode =(Node*)malloc(sizeof(Node));// allocate memory for newnode
    if( newNode == NULL)
         return 1; // failure to insert node because of insufficient memory
     
    newNode->info = item ; // add data in the newNode
    newNode->link = stack->top;// newNode points to the (current) first Node
    stack->top = newNode;// newNode is now the first node, update top
    return 0;// successful insertion of node 
}//end of push


int pop( Stack *stack)// stack is passed by reference 
{
    if(stack->top == NULL)// stack is empty
        return -1;
    else
    {
        int top_element = stack->top->info;// store the info of 1st node
        Node *save = stack->top;// save the address of the first node
        stack->top = stack->top->link;// update top  
        free(save);// release the memory of the node to be deleted 
        return top_element;// return the top element 
    }
}//end of pop 

int peek(Stack stack)
{
    if( isEmpty(stack))
        return -1;
    else    
        return stack.top->info;// return the info of the top node
}//end of peek


// Reversing a String using a Stack ( Stack implemented over Dynamic Linked List)
void main()
{
    Stack stk;
    char word[] = "We are reversing a String using Stack";
    int i;
    stk.top  = NULL; // initialize Stack top 
    for(i=0; word[i]; i++)
        push(&stk,word[i]); // push the characters of the string to the Stack

    printf("\nPeeked Element from Stack is %c \n", peek(stk));
    while( !isEmpty(stk))  // until the Stack is empty 
    {
        char c = pop(&stk);// pop from Stack
        printf("%c", c);// print the element im char format
    }//end of while

}//end of main 
    
    





