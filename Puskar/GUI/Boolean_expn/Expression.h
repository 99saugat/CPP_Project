#ifndef EXPRESSION_H
#define EXPRESSION_H


#include<iostream>
using namespace std;
extern  int result[16], X[16][4],n;
namespace puskar
{

    static string S,P;
}
class expression
{
    public:
    string expression, var, single_variable;
    int length; //length of expression
     //number of variables
    void get();
    void analyze();
};


#endif // EXPRESSION_H
