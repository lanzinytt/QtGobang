#include "widget.h"
#include "ui_widget.h"
#include "drawtools.h"
#include "selfchess.h"
#include "gameboard.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::on_aiButton_clicked()
{
    GameBoard *pic=new GameBoard();
    this->close();
    pic->show();
}


void Widget::on_playselfButton_clicked()
{
    selfchess *pic=new selfchess();
    this->close();
    pic->show();
}

void Widget::paintboard(){
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);//抗锯齿
    Drawer::drawBoard(painter);
}
