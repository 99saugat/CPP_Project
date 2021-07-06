//Written by Saugat Baral
#include<iostream>
#include<cmath>

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
                a[j+1+k] = temp[k];
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



        for(int j = 0; j < e.length; j++)
        {
            switch(a[j])
            {
                case(2):
                    a[j] = !a[j+1];

                    for(int k = j; k < e.length-j; k++)
                        {
                            a[k+1] = a[k+2];
                        }

                        break;

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
