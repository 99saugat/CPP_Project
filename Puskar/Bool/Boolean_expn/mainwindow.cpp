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
void TestModel::populateData(const QList<QString> &A,const QList<QString> &B,const QList<QString> &C)
{
    tm_A.clear();
    tm_A = A;
    tm_B.clear();
    tm_B = B;
    tm_C.clear();
    tm_C = C;
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
    return 3;
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

        // Create some data that is tabular in nature:
       A.append("0");
        A.append("0");
        A.append("1");
        A.append("1");
        B.append("0");
        B.append("1");
       B.append("0");
       B.append("1");
       using namespace puskar;
       expn();
       for (int i=0;i<4;i++)
       {
           using namespace puskar;
           QString s = QString::number(result[i]);
          C.append(s);
       }


        // Create model:
        TestModel *truthtable = new TestModel(this);

        // Populate model with data:
        truthtable->populateData(A,B,C);

        // Connect model to table view:
        ui->tableView->setModel(truthtable);

        // Make table header visible and display table:
        ui->tableView->horizontalHeader()->setVisible(true);
        ui->tableView->show();
}



void Expression::get()
{
    using namespace puskar;
    expression=S;
}
void Expression::analyze()
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

for(int i=0;i<a;i++)
{
   cout<<variable[i]<<"\t";
   single_variable[i] = variable[i];
}

    cout<<expression<<endl;

}


