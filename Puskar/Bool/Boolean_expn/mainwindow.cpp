/* Written by Puskar Neupane */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"Expression.h"
#include<QTableWidget>
#include<iostream>
QString input;
MainWindow::MainWindow(QWidget *parent)

    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



}

MainWindow::~MainWindow()
{
    delete ui;
}
TestModel::TestModel(QObject *parent) : QAbstractTableModel(parent)
{
}

// Create a method to populate the model with data:
void TestModel::populateData(const QList<QString> &A,const QList<QString> &B,const QList<QString> &C,const QList<QString> &D,const QList<QString> &E)
{
    tm_A.clear();
    tm_A = A;
    tm_B.clear();
    tm_B = B;
    tm_C.clear();
    tm_C = C;
    tm_D.clear();
    tm_D = D;
    tm_E.clear();
    tm_E = E;
    return;
}

int TestModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return tm_A.length();
}

int TestModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 5;
}

QVariant TestModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole) {
        return QVariant();
    }
    if (index.column() == 0) {
        return tm_A[index.row()];
    } else if (index.column() == 1) {
        return tm_B[index.row()];
    }else if (index.column() == 2) {
        return tm_C[index.row()];
    }else if (index.column() == 3) {
        return tm_D[index.row()];
    }else if (index.column() == 4) {
         return tm_E[index.row()];
    }
    return QVariant();
}

QVariant TestModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        if (section == 0) {
            return QString("A");
        } else if (section == 1) {
            return QString("B");
        }else if (section == 2) {
            return QString("C");
        }else if (section == 3) {
            return QString("D");
        }else if (section == 4) {
            return QString("Output");
        }

    }
    return QVariant();
}

void MainWindow::on_Expression_editingFinished()
{
    input = ui->Expression->text();
    using namespace puskar;
    S=input.toStdString();
   // expn();
     ui->label_3->setText(input);
}

void MainWindow::on_pushButton_clicked()
{
       QList<QString> A;
        QList<QString> B;
        QList<QString> C;
        QList<QString> D;
        QList<QString> E;


        // Create some data that is tabular in nature:
       using namespace puskar;
       expn();
       if (n==2)
         {

         for (int z=0;z<4;z++)
         { for (int j=0;j<1;j++)
         {
           QString t = QString::number(X[z][j]);
           QString u = QString::number(X[z][j+1]);
          //  QString v = QString::number(X[z][j+2]);
          //   QString w = QString::number(X[z][j+3]);
          A.append(t);
           B.append(u);
            C.append("*");
             D.append("*");
          }
           }
          for (int i=0;i<4;i++)
          {
           QString s = QString::number(result[i]);
          E.append(s);
           }


           // Create model:
           TestModel *truthtable = new TestModel(this);

           // Populate model with data:
           truthtable->populateData(A,B,C,D,E);
       }



          else if (n==3)
            {
                for (int z=0;z<8;z++)
             { for (int j=0;j<1;j++)
              {
               QString t = QString::number(X[z][j]);
               QString u = QString::number(X[z][j+1]);
                QString v = QString::number(X[z][j+2]);
                 //QString w = QString::number(X[z][j+3]);
              A.append(t);
               B.append(u);
                C.append(v);
                 D.append("*");
               }
               }
              for (int i=0;i<8;i++)
              {
               QString s = QString::number(result[i]);
              E.append(s);
              }


               // Create model:
               TestModel *truthtable = new TestModel(this);

                // Populate model with data:
               truthtable->populateData(A,B,C,D,E);
                }




               else if (n==4)
               {
                for (int z=0;z<16;z++)
               { for (int j=0;j<1;j++)
             {
              QString t = QString::number(X[z][j]);
              QString u = QString::number(X[z][j+1]);
              QString v = QString::number(X[z][j+2]);
              QString w = QString::number(X[z][j+3]);
          A.append(t);
           B.append(u);
            C.append(v);
             D.append(w);
             }
           }
            for (int i=0;i<16;i++)
           {
           QString s = QString::number(result[i]);
          E.append(s);
           }


            // Create model:
           TestModel *truthtable = new TestModel(this);

            // Populate model with data:
            truthtable->populateData(A,B,C,D,E);


            // Connect model to table view:
           ui->tableView->setModel(truthtable);
          }

           // Make table header visible and display table:
      ui->tableView->horizontalHeader()->setVisible(true);
      ui->tableView->show();
}



void expression::get()
{
    using namespace puskar;
    expression=S;
}
void expression::analyze()
{

    length = expression.length();
    n=0;

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
cout<<"Hello "<<n;
//copying variable to single_variable
for(int i=0;i<a;i++)
{
   cout<<variable[i]<<"\t";
   single_variable[i] = variable[i];
}

    cout<<expression<<endl;

}


