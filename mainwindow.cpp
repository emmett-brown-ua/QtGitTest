#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_pushButton_clicked()
{
    ui->leditResult->setText(convertDecimalToX(ui->leditDigit->text().toInt(), ui->leditSystem->text().toInt()));
}

QString MainWindow::convertDecimalToX(int digit, int sysIndex)
{
    QString output = "";

    int remaind = 0;
/*
    if (digit > 0)
    {
        while (digit > 0)
        {
            remaind = digit % sysIndex;

            output = remaiderIndex(remaind) + output;

            digit /= sysIndex;
        }
    }
    else
        output = "0";
*/
/*
    if (digit > 0)
    {
        do
        {
            remaind = digit % sysIndex;

            output = remaiderIndex(remaind) + output;

            digit /= sysIndex;
        }
        while (digit > 0);
    }
    else
        output = "0";
*/

    if (digit > 0)
    {
        for ( ; digit > 0; )
        {
            remaind = digit % sysIndex;

            output = remaiderIndex(remaind) + output;

            digit /= sysIndex;
        }
    }
    else
        output = "0";

    return output;
}

QString MainWindow::remaiderIndex(int remaind)
{
    switch (remaind)
    {
    case 10:
        return "A";
        break;

    case 11:
        return "B";
        break;

    case 12:
        return "C";
        break;

    case 13:
        return "D";
        break;

    case 14:
        return "E";
        break;

    case 15:
        return "F";
        break;

    default:
        return QString::number(remaind);
        break;
    }
}
