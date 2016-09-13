#include <stdio.h>
#include <stdlib.h>
struct LLAsStack{
    char val;
    struct LLAsStack* prev;
}*top,*p;
void create(){
    top=-1;
}
int isEmpty(){
    if(top==-1)
        return 1;
    else
        return 0;
}
void push(char c){
    p=(struct LLAsStack *)malloc(sizeof(struct LLAsStack));
    if(top!=-1){
        p->prev=top;
        p->val=c;
        top=p;
    }
    else{
        p->val=c;
        top=p;
    }
}
char pop(){
    if(isEmpty()==0){
        p=top;
        char c=p->val;
        p=p->prev;
        free(top);
        top=p;
        return c;
    }
    else {
        printf("Sorry,Stack empty.\nCannot pop");
        return '$';
    }
}
char peek(){
    if(isEmpty()){
        printf("Sorry,Stack empty.\nCannot peek");
        return '$';
        }
    else
        return top->val;
}
int main()
{
    int i,j=1;
    char d;
    create();
    while(j){
    printf("\nWhat would you like to do with the stack.\n1:Push an Element\n2:Pop an Element\n3:Peek at top of stack\n4:Exit\nEnter your choice:");
    scanf("%d",&i);
    switch(i){
    case 1:
        printf("\nEnter the element to be pushed: ");
        scanf("%c%c",&d,&d);
        push(d);
        break;
    case 2:
        d=pop();
        if(d!='$')
            printf("The element popped is : %c",d);
        break;
    case 3:
        d=peek();
        if(d!='$')
            printf("The top element of stack is: %c",d);
        break;
    default:
        j=0;
    }
    }
    printf("Thank You.Have a nice day");
    return 0;
}
