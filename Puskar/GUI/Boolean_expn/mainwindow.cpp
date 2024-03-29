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
    QPixmap bkgnd("D:/Ideathon_2021/C++ project/Template-01.png");
       bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
       QPalette palette;
       palette.setBrush(QPalette::Window, bkgnd);
       this->setPalette(palette);



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

   // for two variables

       if (n==2)

      {
        A.append("0");
         A.append("0");
          A.append("1");
           A.append("1");
           for (int k=0;k<12;k++)
           {

           A.append("*");
            }

           B.append("0");
            B.append("1");
             B.append("0");
              B.append("1");
              for (int k=0;k<12;k++)
              {
              B.append("*");
               }
              for (int k=0;k<16;k++)
              {
              C.append("*");
               D.append("*");
               }

          for (int i=0;i<4;i++)
          {
           QString s = QString::number(result[i]);
          E.append(s);
           }
          for(int k=0;k<12;k++)
          {
                  E.append("*");
          }


           }


   // for 3 variables

          else if (n==3)
            {
           for (int k=0;k<4;k++)
            {
                A.append("0");
            }
           for (int k=0;k<4;k++)
            {
                A.append("1");
            }

            for (int k=0;k<8;k++)
              {

              A.append("*");
               }


            for (int k=0;k<2;k++)
               {
                for(int q=0;q<2;q++)
                {
                B.append("0");
                 }
                for(int q=0;q<2;q++)
                {
                B.append("1");
                 }
               }
               for (int k=0;k<8;k++)
                 {
                 B.append("*");
                  }


             for (int k=0;k<4;k++)
                    {
                     C.append("0");
                     C.append("1");
                    }
               for (int k=0;k<8;k++)
                    {
                    C.append("*");
                    }


             for (int k=0;k<16;k++)
                 {

                  D.append("*");
                  }


              for (int i=0;i<8;i++)
              {
               QString s = QString::number(result[i]);
              E.append(s);
              }

              for(int k=0;k<8;k++)
              {
                      E.append("*");
              }

             }



         // for 4 variables

          else if (n==4)
           {
               for (int k=0;k<8;k++)
                {
                    A.append("0");
                }
               for (int k=0;k<8;k++)
                {
                    A.append("1");
                }

               for (int k=0;k<2;k++)
                {
                    for(int q=0;q<4;q++)
                    {
                    B.append("0");
                     }
                    for(int q=0;q<4;q++)
                    {
                    B.append("1");
                     }

                }
                for (int k=0;k<4;k++)
                {
                    for(int q=0;q<2;q++)
                    {
                    C.append("0");
                     }
                    for(int q=0;q<2;q++)
                    {
                    C.append("1");
                     }

                }
                for (int k=0;k<16;k++)
               {
                    D.append("0");
                    D.append("1");
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


