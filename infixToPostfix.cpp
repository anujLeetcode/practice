/*
Infix expression:The expression of the form a op b. When an operator is in-between every pair of operands.

Postfix expression:The expression of the form a b op. When an operator is followed for every pair of operands.

Why postfix representation of the expression?
The compiler scans the expression either from left to right or from right to left.

Consider the below expression: a op1 b op2 c op3 d
If op1 = +, op2 = *, op3 = +

The compiler first scans the expression to evaluate the expression b * c, then again scan the expression to add a to it. The result is then added to d after another scan.

The repeated scanning makes it very in-efficient. It is better to convert the expression to postfix(or prefix) form before evaluation.

The corresponding expression in postfix form is: abc*+d+. The postfix expressions can be evaluated easily using a stack. We will cover postfix expression evaluation in a separate post.

Algorithm
1. Scan the infix expression from left to right.
2. If the scanned character is an operand, output it.
3. Else,
…..3.1 If the precedence of the scanned operator is greater than the precedence of the operator in the stack(or the stack is empty), push it.
…..3.2 Else, Pop the operator from the stack until the precedence of the scanned operator is less-equal to the precedence of the operator residing on the top of the stack. Push the scanned operator to the stack.
4. If the scanned character is an ‘(‘, push it to the stack.
5. If the scanned character is an ‘)’, pop and output from the stack until an ‘(‘ is encountered.
6. Repeat steps 2-6 until infix expression is scanned.
7. Pop and output from the stack until it is not empty.



*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include<stack>
// Stack type
using namespace std;

// A utility function to check if the given character is operand
int isOperand(char ch)
{
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

// A utility function to return precedence of a given operator
// Higher returned value means higher precedence
int Prec(char ch)
{
	switch (ch)
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


// The main function that converts given infix expression
// to postfix expression. 
int infixToPostfix(string exp)
{
    stack<char> ops;
    int i, j;
    for(i =0, j=0; i < exp.size(); i++)
    {
        if(isOperand(exp[i]))
            exp[j++] = exp[i];
        else if(exp[i] == '(')
            ops.push(exp[i]);
        else if(exp[i] == ')')
        {
            while(ops.top()!= '(')
            {
                exp[j++] = ops.top();
                ops.pop();
            }
            ops.pop();
        }
        else
        {
            while(!ops.empty()&& Prec(exp[i]) <= Prec(ops.top()))
            {
                exp[j++] = ops.top();
                ops.pop();
            }   
            ops.push(exp[i]);
            
        }
    }
    while(!ops.empty())
        {
            exp[j++] = ops.top();
            ops.pop();
        }
    while(j!=exp.size())
        exp[j++] = ' ';
    cout<< "string" << exp;
}

// Driver program to test above functions
int main()
{
	string exp = "a+b*(c^d-e)^(f+g*h)-i";
	infixToPostfix(exp);
	return 0;
}

