#include "gameboard.h"
#include "ui_gameboard.h"
#include "drawtools.h"
#include "widget.h"

bool is_black=true;

GameBoard::GameBoard(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameBoard)
{
    ui->setupUi(this);
}

GameBoard::~GameBoard()
{
    delete ui;
}

void GameBoard::on_giveupButton_clicked()
{
    Widget *father=new Widget();
    this->close();
    father->show();
    delete this;
}

void GameBoard::paintEvent(QPaintEvent* event){
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(Qt::black, 2));
    Drawer::drawBoard(painter);
}

void GameBoard::mousePressEvent(QMouseEvent *event){
    QPainter painter(this);
    if(event->button()==Qt::LeftButton){
        QPoint clickpos=event->pos();
        Drawer::drawStone(painter,clickpos,is_black);
        is_black=!is_black;
        update();
    }
}


