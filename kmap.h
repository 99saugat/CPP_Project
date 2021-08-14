
class input
{
    public:
int num,sum,var,terms,a3[8],a4[16],fil3[4][4],fil4[4][4],temp[20],mus;
input(){}
void getdata()//this function is to store the given minterms
{


if (var==3)
        {
                int k,l,in=0;
                  for( k=1;k<=2;k++){
                    for ( l=1;l<=4;l++){
                      for (int n=0;n<terms;n++){
                        if (in==a3[n]){
                          sum=1;
                            break;
                            }
                        else sum=0;
                     }
                  if (sum==1)
                fil3[k][l]=1;
              else fil3[k][l]=0;
           in++;
           }
         }
       }

      else
        {
              int s,t;
                int ni=0;
                  for( s=1;s<=4;s++){
                    for ( t=1;t<=4;t++){
                      for (int e=0;e<terms;e++){
                        if (ni==a4[e]){
                            mus=1;
                        break;}
                      else mus=0;
                      }
                  if (mus==1)
                fil4[s][t]=1;
              else fil4[s][t]=0;
           ni++;
                     }
                  }
              }

          }
    void exchange() //this function is to swap the elements to get the actual k map structure
    {
      if (var==3){
         for(int i=1;i<=2;i++){
            for (int j=1;j<=4;j++){
               if (j==3){
                 swap(fil3[i][3],fil3[i][4]);
                 continue;
                        }
                    }
                }
            }
    else
    {
        for(int i=1;i<=4;i++){
          for (int j=1;j<=4;j++){
            if (j==3){
               swap( fil4[i][3],fil4[i][4]);
               continue;
                       }
                    }
                 }
                 for(int j=1;j<=4;j++){
                    for (int i=1;i<=4;i++){
                       if (i==3){
                            swap(  fil4[3][j],fil4[4][j]);
                            continue;
                        }
                    }
                 }
             }
         }

    void display(){
      if(var==3){
        cout<<"AB\CD"<<'\t'<<"C'D'  "<<"C'D   "<<"CD    "<<"CD'"<<endl;
          cout<<"     ----------------------"<<endl;
            cout<<"A'B' |"<<'\t';
               for (int j=1;j<=4;j++){
                 cout<<fil3[1][j]<<"     ";}
                   cout<<'\n';
                     cout<<"A'B  |"<<'\t';
                        for (int j=1;j<=4;j++)
                          cout<<fil3[2][j]<<"     ";
    }
    else
    {
        cout<<"AB\CD"<<'\t'<<"C'D'   "<<"C'D    "<<"CD      "<<"CD'"<<endl;
          cout<<"       ----------------------"<<endl;
            cout<<"A'B'  |"<<'\t';
              for (int j=1;j<=4;j++){
                 cout<<fil4[1][j]<<"      ";}
                   cout<<'\n';
                      cout<<"A'B   |"<<'\t';
                         for (int j=1;j<=4;j++){
                            cout<<fil4[2][j]<<"      ";}
                              cout<<'\n';
                              cout<<"AB    |"<<'\t';
                           for (int j=1;j<=4;j++){
                        cout<<fil4[3][j]<<"      ";}
                     cout<<'\n';
                     cout<<"AB'   |"<<'\t';
                 for (int j=1;j<=4;j++){
             cout<<fil4[4][j]<<"      ";}
           cout<<'\n';
          }
       }

void grouping()//This function is for the grouping of elements in K-Map
{
  for(int i=1;i<=4;i++)
  {
    for(int j=1;j<=4;j++)
    {
      if(i==4 && fil4[i][j]==1 && fil4[i][j]==fil4[1][j] && fil4[i][j]==fil4[1][j+1] && fil4[i][j]==fil4[i][j+1] && j!=4)
      {
         cout<<"["<<i<<"]"<<"["<<j<<"]"<<","<<"[1]"<<"["<<j<<"]"<<","<<"[1]"<<"["<<j+1<<"]"<<"and"<<"["<<i<<"]"<<"["<<j+1<<"]"<<" are grouped"<<endl;

      }
      else if(j==4 && fil4[i][j]==1 && fil4[i][j]==fil4[i+1][j] && fil4[i][j]==fil4[i][1] && fil4[i+1][1] && i!=4)
      {
        cout<<"["<<i<<"]"<<"["<<j<<"]"<<","<<"["<<i<<"]"<<"[1]"<<"["<<i+1<<"]"<<"[1]"<<"and"<<"["<<i+1<<"]"<<"["<<j<<"]"<<" are grouped"<<endl;
      }
      else if(fil4[i][j]==fil4[i][j+1] && fil4[i][j]==fil4[i+1][j] && fil4[i][j]==fil4[i+1][j+1] && fil4[i][j]==1)
      {
         cout<<"["<<i<<"]"<<"["<<j<<"]"<<" , "<<"["<<i+1<<"]"<<"["<<j<<"]"<<","<<"["<<i<<"]"<<"["<<j+1<<"]"<<"and"<<"["<<i+1<<"]"<<"["<<j+1<<"]"" are grouped"<<endl;
      }


     else if(fil4[i][j]==fil4[i][j+1] && fil4[i][j]==fil4[i][j+2] &&fil4[i][j]==fil4[i][j+3] && fil4[i][j]==1 && j==1)
      {
        cout<<"["<<i<<"]"<<"["<<j<<"]"<<" , "<<"["<<i<<"]"<<"["<<j+1<<"]"<<","<<"["<<i<<"]"<<"["<<j+2<<"]"<<"and"<<"["<<i<<"]"<<"["<<j+3<<"]"" are grouped"<<endl;
        break;
      }
      else if(j==4)
      {
        if(fil4[i][j]==1 && fil4[i][j]==fil4[i][1])
        {
          cout<<"["<<i<<"]"<<"["<<j<<"]"<<" and "<<"["<<i<<"]"<<"[1]"<<" are grouped"<<endl;
        }
      }
      else if(fil4[i][j]==fil4[i][j+1] && fil4[i][j]==1)
      {
        cout<<"["<<i<<"]"<<"["<<j<<"]"<<" and "<<"["<<i<<"]"<<"["<<j+1<<"]"<<" are grouped"<<endl;
      }
      }
      }
   for(int t=1;t<=4;t++)
  {
    for(int s=1;s<=4;s++)
    {
       if(fil4[s][t]==fil4[s+1][t] && fil4[s][t]==fil4[s+2][t] && fil4[s][t]==fil4[s+3][t] && fil4[s][t]==1 && s==1)
      {
        cout<<"["<<s<<"]"<<"["<<t<<"]"<<" , "<<"["<<s+1<<"]"<<"["<<t<<"]"<<","<<"["<<s+2<<"]"<<"["<<t<<"]"<<"and"<<"["<<s+3<<"]"<<"["<<t<<"]"" are grouped"<<endl;
        break;
      }

      else if(fil4[s][t]==1 && fil4[s][t]==fil4[1][t] && s==4)
        {
          cout<<"["<<s<<"]"<<"["<<t<<"]"<<" and "<<"[1]"<<"["<<t<<"]"<<" are grouped"<<endl;
        }
      else if(fil4[s][t]==fil4[s+1][t] && fil4[s][t]==1)
      {
        cout<<"["<<s<<"]"<<"["<<t<<"]"<<" and "<<"["<<s+1<<"]"<<"["<<t<<"]"<<" are grouped"<<endl;
      }

    }
  }
 /* for(int u=1;u<=4;u++)
  {
    for(int v=1;v<=4;v++)
    {
     if(u==4 && fil4[u][v]==1 && fil4[u][v]==fil4[1][v] && fil4[u][v]==fil4[1][v+1] && fil4[u][v]==fil4[u][v+1] && v!=4)
      {
         cout<<"["<<u<<"]"<<"["<<v<<"]"<<","<<"[1]"<<"["<<v<<"]"<<","<<"[1]"<<"["<<v+1<<"]"<<"and"<<"["<<u<<"]"<<"["<<v+1<<"]"<<" are grouped"<<endl;
      }
      else if(v==4 && fil4[u][v]==1 && fil4[u][v]==fil4[u+1][v] && fil4[u][v]==fil4[u][1] && fil4[u+1][1] && u!=4)
      {
        cout<<"["<<u<<"]"<<"["<<v<<"]"<<","<<"["<<u<<"]"<<"[1]"<<"["<<u+1<<"]"<<"[1]"<<"and"<<"["<<u+1<<"]"<<"["<<v<<"]"<<" are grouped"<<endl;
      }
      else if(fil4[u][v]==fil4[u][v+1] && fil4[u][v]==fil4[u+1][v] && fil4[u][v]==fil4[u+1][v+1] && fil4[u][v]==1)
      {
         cout<<"["<<u<<"]"<<"["<<v<<"]"<<" , "<<"["<<u+1<<"]"<<"["<<v<<"]"<<","<<"["<<u<<"]"<<"["<<v+1<<"]"<<"and"<<"["<<u+1<<"]"<<"["<<v+1<<"]"" are grouped"<<endl;
      }
    }
  }*/
}
};
