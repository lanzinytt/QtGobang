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
    Drawer::drawBoard(painter);

}

void selfchess::on_giveupButton_clicked()
{
    Widget *father=new Widget();
    this->close();
    father->show();
    delete this;
}

