#include "mainwindow.h"
#include "Expression.h"
#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;
int result[16], X[16][4],n;

void read_expression(int a[], int temp[], int j, int length)
{
    for(int k = 0; k < length-j; k++)
        {
            temp[k] = a[j+k];
        }
}

//modifies expression after assigning numerical value to operator
void modify_expression(int a[], int temp[], int j, int length)
{
    for(int k = 0; k < length-j; k++)
        {
            a[j+k+1] = temp[k];
        }
}

//function to apply not operator
void apply_not(int a[], int j, expression e)
{
    if(a[j]==2 )
        {
            a[j] = !a[j+1];
            for(int k = j; k < e.length-j; k++)
                {
                    a[k+1] = a[k+2];
                }
        }
}

//modifies expression after using certain operator with given operands
void modify_expression(int a[], int &j, int length)
{
    for(int k=j; k<length-j;k++)
        {
            a[k] = a[k+2];
        }
        j-=1;
}

//finds next bracket from the position where first bracket is detected
int find_next_bracket(int a[], int i, int length)
{
    for(int j=i+1; j<length; j++)
    {
        if(a[j]==5)
        {
            return j;
        }
    }
}

//removes brackets; to be used after manipulation expressions inside bracket
void remove_brackets(int a[], int i, expression e)
{
    int next_bracket = find_next_bracket(a, i, e.length);

    for(int j = 0; j < next_bracket; j++)
        {
            if(a[j] == 5)
            {
                for(int k = j; k < e.length; k++)
                {
                    a[k] = a[k+1];
                }
            }
        }
}

//all possible binary values by decimal to binary conversion
void value_to_variables(int a[], int temp[], int number_of_variables, int n, int z)
{

    for(int j=number_of_variables-1; n>0; j--)
        {
            temp[0] = a[j];
            a[j] = n%2;
            a[j-1] = temp[0];
            n = n/2;
        }

    for(int j=0; j<number_of_variables; j++)
        {
            cout<<a[j]<<"\t";
            X[z][j]=a[j];
        }
}

//copies variable values only from source to destination
void copy_variable_value_only(int source[], int destination[], int number_of_variables)
{
    for(int j=0; j<number_of_variables; j++)
    {
        destination[j] = source[j];
    }
}

//converting string to number
void string_to_number(int a[], int b[], int temp[], int number_of_variables, expression& e)
{
    for(int j = 0; j < e.length; j++)
        {
            switch(e.expression[j])
            {
            case '!':
                read_expression(a, temp, j, e.length);

                a[j] = 2;

                modify_expression(a, temp, j, e.length);

                break;

            case '&':
                read_expression(a, temp, j, e.length);

                a[j] = 3;

                modify_expression(a, temp, j, e.length);

                break;

            case '|':

                read_expression(a, temp, j, e.length);

                a[j] = 4;

                modify_expression(a, temp, j, e.length);

                break;

            case '(':

                read_expression(a, temp, j, e.length);

                a[j] = 5;

                modify_expression(a, temp, j, e.length);

                break;

            case ')':

                read_expression(a, temp, j, e.length);

                a[j] = 5;

                modify_expression(a, temp, j, e.length);

                break;

            }
        }

    for(int j=0; j<number_of_variables; j++)
        {
            for(int k = 0; k<e.length;k++)
            {
                if(e.expression[k] == e.single_variable[j])
                {
                    a[k] = b[j];
                }
            }
        }
}

int expn()
{
    expression e;
    e.get();
    e.analyze();

    int number_of_variables = n;

    int total = pow(2, number_of_variables);

    //int result[total] = {0};
    X[16][4]=0;


    int b[number_of_variables];
    b[number_of_variables] = {0};

    for(int i = 0; i < total; i++)
    {
        int n = i;

        int a[e.length];
        a[e.length] = {0};


        int temp[e.length];
        temp[e.length] = {0};

        value_to_variables(a, temp, number_of_variables, n,i);

        copy_variable_value_only(a, b, number_of_variables);

        string_to_number(a, b, temp, number_of_variables, e);


//String Manipulation from numbers

//Brackets

int next_bracket = 0;

for(int i = 0; i < e.length; i++)
        {
            if(a[i]==5 )
            {
                next_bracket = find_next_bracket(a, i, e.length);

                for(int j = i+1; j < next_bracket; j++)
                    {
                        apply_not(a, j, e);
                        next_bracket = find_next_bracket(a, i, e.length);
                    }

                    next_bracket = find_next_bracket(a, i, e.length);

                    for(int j = i+1; j < next_bracket; j++)
                        {
                            next_bracket = find_next_bracket(a, i, e.length);

                            switch(a[j])
                            {
                                case(3):
                                    a[j-1] = a[j-1]&&a[j+1];
                                    modify_expression(a, j, e.length);
                                    break;

                                case(4):
                                    a[j-1] = a[j-1]||a[j+1];
                                    modify_expression(a, j, e.length);
                                    break;
                            }
                        }

                        remove_brackets(a, i, e);
            }

    }


//after brackets are solved; for remaining expressions

for(int j = 0; j < e.length; j++)
{
    apply_not(a, j, e);
}

        for(int j = 0; j < e.length; j++)
        {
            switch(a[j])
            {

                case(3):
                    a[j-1] = a[j-1]&&a[j+1];
                    modify_expression(a, j, e.length);
                    break;

                case(4):
                    a[j-1] = a[j-1]||a[j+1];
                    modify_expression(a, j, e.length);
                    break;
            }

        }

        cout<<a[0];
        result[i] = a[0];
        cout<<endl<<endl;
    }
    return 0;
}
