#include<stdio.h>
#include<stdlib.h>
void regex_fun(char regex_expression[50],char find_exp[90]);
void main()
{
    char regex_expression[50],find_exp[90];
    printf("there the expression to be search");
    scanf("%s",regex_expression);
    printf("enter the locaton of file to search");
    scanf("%s",find_exp);

    return 0;
}
// #     ------regex-fun idea ----
// #    in this fun it will decode the expression 
// #    into such a way exp for each node
// #   then try to create graph from those
// #   exp by matching the exp with function
// #   that will match the exp as requirement
// #   
// #
// #
void regex_fun(char regex_expression[50],char find_exp[90])
{
    int running = 1,pos=0;
    char ele;
    while(running)
    {
        ele = find_exp[pos];

        
    }
}