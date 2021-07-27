#ifndef EXPRESSION_H
#define EXPRESSION_H


#include<iostream>
using namespace std;
 extern int result[4];
namespace puskar
{

    static string S;
}
class Expression
{
    public:
    string expression, var, single_variable;
    int length;
    int n = 0, n2 = 0; //n is number_of_variables
    void get();
    void analyze();
};



#endif // EXPRESSION_H
