#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffe->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbCoke->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setButtonEnabled()
{
    ui->pbCoffe->setEnabled(money >= 100 ? true : false);
    ui->pbTea->setEnabled(money >= 150 ? true : false);
    ui->pbCoke->setEnabled(money >= 200 ? true : false);
}

void Widget::changeMoney(int diff)
{
    money += diff;
    ui->lcdNumber->display(money);
    setButtonEnabled();
}

void Widget::setMoney(int value)
{
    money = value;
    ui->lcdNumber->display(money);
    setButtonEnabled();
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}


void Widget::on_pb50_clicked()
{
    changeMoney(50);
}


void Widget::on_pb100_clicked()
{
    changeMoney(100);
}


void Widget::on_pbCoffe_clicked()
{
    if (money >= 100)
        changeMoney(-100);
}


void Widget::on_pbTea_clicked()
{
    if (money >= 150)
        changeMoney(-150);
}


void Widget::on_pbCoke_clicked()
{
    if (money >= 200)
        changeMoney(-200);
}

void Widget::on_pbReset_clicked()
{
    QMessageBox mb;
    // TODO: 남은돈 100원 몇개, 10원 몇개 등 출력하기
    int ten = 0, fifty = 0, onehundred = 0;

    if (money > 100)
    {
        onehundred = money / 100;
        money -= 100 * onehundred;
    }
    if (money > 50)
    {
        fifty = money / 50;
        money -= 50 * fifty;
    }
    if (money > 10)
    {
        ten = money / 10;
        money -= 10 * ten;
    }

    setMoney(0);
    QString str;
    str = QString("잔돈 100원: %1개, 50원: %2개, 10원: %3개")
              .arg(onehundred)
              .arg(fifty)
              .arg(ten);
    mb.information(nullptr, "Reset", str);
}

