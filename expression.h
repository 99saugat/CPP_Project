class expression
{
    public:
    string expression, var, single_variable;
    int length;
    int n = 0, n2 = 0; //n is number_of_variables
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


    for (int i = 0; i < length; i++)
    {
        if(expression[i] != '&' && expression[i] != '|' && expression[i] != '!' && expression[i] != '(' && expression[i] != ')')
        {
            var[n] = expression[i];
            n+=1;
        }

    }
/*
    n2 = n;

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
*/
for(int i=0;i<n;i++)
{
   cout<<var[i]<<"\t";
   single_variable[i] = var[i];
}

    cout<<expression<<endl;

}
