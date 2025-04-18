#include <stdio.h>
#include <ctype.h>
#include <stdlib.h> 
#include<string.h>

#define MAX 100

int top = -1;
int stk[MAX];
void push(int val) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    if(top==-1)
    {
    	top=0;
    	stk[top]=val;
	}
	else
	{
		top++;
		stk[top]=val;
	}
}

int pop() {
    if (top==-1){
        printf("Stack Underflow\n");
        return -1; 
    }
    return stk[top--];
}

int main() {
    char postfix[100];
    printf("\t\t\t\t\tWelcome to Code Alchemist chemistry\n");
    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    int i, ch, op1, op2;
    for (i = 0; postfix[i] != '\0'; i++) {
        if (isalpha(postfix[i])) {
//            scanf("%d", &ch);
            push(postfix[i]);
//            for(int i=0;i<top;i++){
//            	printf("%d ",stk[i]);
//			}
			
        } 
        else if (isdigit(postfix[i])) {
            int num = 0;
            while (postfix[i]!='#'){
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            push(num);
        } 
        else{
            op2 = pop();
            op1 = pop();

            switch (postfix[i]) {
                case '+':
                    push(op1 + op2);
                    break;
                case '-':
                    push(op1 - op2);
                    break;
                case '*':
                    push(op1 * op2);
                    break;
                case '/':
                    if (op2 == 0) {
                        printf("Error: Division by zero\n");
                        return -1;
                    }
                    push(op1 / op2);
                    break;
                case '%':
                    if (op2 == 0) {
                        printf("Error: Division by zero\n");
                        return -1;
                    }
                    push(op1 % op2);
                    break;
            }
        }
    }
    int result = pop();
    printf("\nResult: %d\n", result);

    return 0;
}
