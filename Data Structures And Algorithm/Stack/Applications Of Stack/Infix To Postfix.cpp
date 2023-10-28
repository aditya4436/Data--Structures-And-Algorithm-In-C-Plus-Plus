///A program to concert Infix Expression to Postfix Expression
#include<iostream>
#include<limits.h>
#include<stdlib.h>
#define MAX 20
using namespace std;
char stk[20];
int top=-1;
int Stack_Is_Empty()
{
    return top==-1;
}
int Stack_Is_Full()
{
    return top==MAX-1;
}
char Peek_Of_The_Stack()
{
    return stk[top];
}
char Pop_Up_The_Top()
{
    if(Stack_Is_Empty())
        return -1;

    char ch=stk[top];
    top--;
    return (ch);
}
void Push_Into_The_Stack(char oper)
{
    if(Stack_Is_Full())
        cout<<"Stack is Full!";

    else
    {
        top++;
        stk[top]=oper;
    }
}
int Check_If_Operand(char ch)
{
    return(ch>='a'&&ch<='z' || ch>='A'&&ch<='Z');
}
int Precedence_Of_An_Operator(char ch)
{
    switch(ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}
int Convert_Infix_To_Postfix(char *expression)
{
    int i, j;
    for(i=0, j=-1; expression[i]; ++i)
    {
        if(Check_If_Operand(expression[i]))
            expression[++j]=expression[i];

        else if(expression[i]=='(')
                    Push_Into_The_Stack(expression[i]);

        else if(expression[i]==')')
        {
            while(!Stack_Is_Empty()&&Peek_Of_The_Stack()!='(')
                    expression[++j]=Pop_Up_The_Top();

            if(!Stack_Is_Empty()&&Peek_Of_The_Stack()!='(')
                return 0;
            else
                Pop_Up_The_Top();
        }
        else
        {
            while(!Stack_Is_Empty()&&Precedence_Of_An_Operator(expression[i])<=Precedence_Of_An_Operator(Peek_Of_The_Stack()))
                expression[++j]=Pop_Up_The_Top();
            Push_Into_The_Stack(expression[i]);
        }
    }
    while(!Stack_Is_Empty())
        expression[++j]=Pop_Up_The_Top();

    expression[++j]='\0';
    cout<<expression;
    return 0;
}
int main()
{
    char expression[]="(a-b/c)*(a/k-l)";
    Convert_Infix_To_Postfix(expression);
    return 0;
}
