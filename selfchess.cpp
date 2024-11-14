#include "selfchess.h"
#include "ui_selfchess.h"
#include "drawtools.h"
#include "widget.h"
selfchess::selfchess(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::selfchess)
{
    ui->setupUi(this);

}

selfchess::~selfchess()
{
    delete ui;
}

void selfchess::paintEvent(QPaintEvent* event){
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(Qt::black, 2));
    Drawer::drawBoard(painter);//绘制基本棋盘

}


void selfchess::mouseMoveEvent(QMouseEvent *event){
    QPoint pos=event->pos();       //获取鼠标位置
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(Qt::black, 2));
    Drawer::drawSign(painter,pos);
    update();
}

void selfchess::on_giveupButton_clicked()
{
    Widget *father=new Widget();
    this->close();
    father->show();
    delete this;
}

