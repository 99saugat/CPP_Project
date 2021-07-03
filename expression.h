class expression
{
    public:
    string expression, variable;
    int length;
    int n = 0; //n is number_of_variables
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
            variable[n] = expression[i];
            n+=1;
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout<<variable[i]<<"\t";
    }

    cout<<expression<<endl;


}
