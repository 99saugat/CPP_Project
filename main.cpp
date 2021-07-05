//Written by Saugat Baral
#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;
#include "expression.h"


int main()
{
    expression e;
    e.get();
    e.analyze();

    string modified = e.expression;

    int number_of_variables = e.n;

    int value[number_of_variables];

    int total = pow(2, number_of_variables);

    int result[total];

    for(int i = 0; i < total; i++)
    {
        int n = i;
        int a[number_of_variables] = {0};
        int temp = 0;

        for(int j = number_of_variables - 1; n > 0; j--)
        {
            temp = a[j];
            a[j] = n%2;
            a[j-1] = temp;
            n = n/2;
        }

        for(int j = 0; j < number_of_variables; j++)
        {
            cout<<a[j]<<"\t";
        }

        for(int j = 0; j <= e.length; j++)
        {

            switch(modified[j])
            {
            case '!':
                a[j] = !a[j];
            }

        }

        for(int j = 0; j <= e.length; j++)
        {

            switch(modified[j])
            {
            case '&':
                a[0] = a[0]&&a[1];
                break;

            case '|':
                a[0] = a[0]||a[1];
                break;

            }
        }

        cout<<a[0];

        result[i] = a[0];

        cout<<endl<<endl;
    }

    return 0;

}
