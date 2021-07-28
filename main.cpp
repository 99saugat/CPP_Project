//Written by Saugat Baral
#include<iostream>
#include<cmath>
#include<string>

using namespace std;

#include "expression.h"


int main()
{
    expression e;
    e.get();
    e.analyze();

    int number_of_variables = e.n;

    int value[number_of_variables];

    int total = pow(2, number_of_variables);

    int result[total];

    int b[e.n] = {0};

    for(int i = 0; i < total; i++)
    {
        int n = i;

        int a[e.length] = {0};

        int temp[e.length] = {0};

        for(int j = number_of_variables - 1; n > 0; j--)
        {
            temp[0] = a[j];
            a[j] = n%2;
            a[j-1] = temp[0];
            n = n/2;
        }

        for(int j = 0; j < number_of_variables; j++)
        {
            cout<<a[j]<<"\t";
        }

        for(int j = 0; j < e.n; j++)
        {
            b[j] = a[j];
        }


//Converting strings to numbers
        for(int j = 0; j < e.length; j++)
        {

            switch(e.expression[j])
            {
            case '!':
                for(int k = 0; k < e.length-j; k++)
                {
                temp[k] = a[j+k];
                }

                a[j] = 2;

                for(int k = 0; k < e.length-j; k++)
                {
                a[j+k+1] = temp[k];
                }
                break;

            case '&':

                for(int k = 0; k < e.length-j; k++)
                {
                temp[k] = a[j+k];
                }

                a[j] = 3;

                for(int k = 0; k < e.length-j; k++)
                {
                a[j+1+k] = temp[k];
                }
                break;

            case '|':

                for(int k = 0; k < e.length-j; k++)
                {
                temp[k] = a[j+k];
                }

                a[j] = 4;

                for(int k = 0; k < e.length-j; k++)
                {
                a[j+1+k] = temp[k];
                }
                break;

            case '(':

                for(int k = 0; k < e.length-j; k++)
                {
                temp[k] = a[j+k];
                }

                a[j] = 5;

                for(int k = 0; k < e.length-j; k++)
                {
                a[j+1+k] = temp[k];
                }
                break;

            case ')':

                for(int k = 0; k < e.length-j; k++)
                {
                temp[k] = a[j+k];
                }

                a[j] = 5;

                for(int k = 0; k < e.length-j; k++)
                {
                a[j+1+k] = temp[k];
                }
                break;

            }
        }


//Adding values of repeated variables
for(int j=0; j<e.n; j++)
{
for(int k = 0; k<e.length;k++)
{
    if(e.expression[k] == e.single_variable[j])
    {
        a[k] = b[j];

    }
}
}


/*
//(A&B)|(A&!C)|(B&!C)
//(C&!D)|(!A&C)|(A&B&!D)|(!A&!B&D)
//(!a&b)|c
//(!A&!B)|(!B&C)|(A&B)
 for(int i=0;i<e.length;i++)
        {
            cout<<a[i];
        }

*/


//String Manipulation from numbers

//Brackets

int next_bracket = 0;

for(int i = 0; i < e.length; i++)
        {
            if(a[i] == 5 )
            {

                for(int j = i+1; j < e.length; j++)
                {

                    if(a[j] == 5)
                    {
                        next_bracket = j;
                        break;

                    }
                }

//other operators

        for(int j = i+1; j < next_bracket; j++)
        {
            if(a[j] == 2 )
            {

                a[j] = !a[j+1];

                    for(int k = j; k < e.length-j+2; k++)
                        {
                            a[k+1] = a[k+2];
                        }


            }

                for(int j = i+1; j < e.length; j++)
                {

                    if(a[j] == 5)
                    {
                        next_bracket = j;
                        break;

                    }
                }

        }

            for(int j = i+1; j < e.length; j++)
            {

                if(a[j] == 5)
                {
                    next_bracket = j;
                    break;

                }
            }


for(int j = i+1; j < next_bracket; j++)
{

            for(int k = i+1; k < e.length; k++)
            {

                if(a[k] == 5)
                {
                    next_bracket = k;
                    break;

                }
            }


            switch(a[j])
            {

                case(3):
                    a[j-1] = a[j-1]&&a[j+1];

                    for(int k = j; k < e.length-j; k++)
                        {
                            a[k] = a[k+2];
                        }
                        j-=1;

                        break;

                case(4):
                    a[j-1] = a[j-1]||a[j+1];

                    for(int k = j; k < e.length-j; k++)
                        {
                            a[k] = a[k+2];
                        }
                        j-=1;

                        break;
            }

            }


            //removing brackets

            for(int j = i+1; j < e.length; j++)
            {

                if(a[j] == 5)
                {
                    next_bracket = j;
                    break;

                }
            }

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

    }


//after brackets are solved

for(int j = 0; j < e.length; j++)
        {
            if(a[j] == 2 )
            {

                a[j] = !a[j+1];

                    for(int k = j; k < e.length-j+2; k++)
                        {
                            a[k+1] = a[k+2];
                        }


            }

        }


        for(int j = 0; j < e.length; j++)
        {
            switch(a[j])
            {

                case(3):
                    a[j-1] = a[j-1]&&a[j+1];

                    for(int k = j; k < e.length-j; k++)
                        {
                            a[k] = a[k+2];
                        }
                        j-=1;

                        break;

                case(4):
                    a[j-1] = a[j-1]||a[j+1];

                    for(int k = j; k < e.length-j; k++)
                        {
                            a[k] = a[k+2];
                        }
                        j-=1;

                        break;

            }

        }



        cout<<a[0];

        result[i] = a[0];

        cout<<endl<<endl;
    }

    return 0;


}
