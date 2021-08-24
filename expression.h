class expression
{
    public:
    string expression, var, single_variable;
    int length; //length of expression
    int n = 0; //number of variables
    void get();
    void analyze();
};

void expression::get()
{
    cout<<"What is the expression? "; cin>>expression;

}

void expression::analyze()
{

    length = expression.length();

//finding total variables by excluding operators

    for (int i = 0; i < length; i++)
    {
        if(expression[i] != '&' && expression[i] != '|' && expression[i] != '!' && expression[i] != '(' && expression[i] != ')')
        {
            var[n] = expression[i];
            n+=1;
        }

    }

//finding total variables, where a variable is present only one time

    char variable[n];

    for(int i=0;i<n;i++)
    {
        variable[i] = var[i];
    }

    int index = 0;
    int a = 0;
   for (int i=0; i< sizeof(variable) / sizeof(variable[0]); i++)
    {
     int j;
     for (j=0; j<i; j++)

        if (variable[i] == variable[j])
        {
           break;
        }
     if (j == i)
     {
        variable[index++] = variable[i];
        a+=1;
     }


   }

   n = a;

//copying variable to single_variable
for(int i=0;i<a;i++)
{
   cout<<variable[i]<<"\t";
   single_variable[i] = variable[i];
}

    cout<<expression<<endl;

}

//edit2
