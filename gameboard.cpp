#include "gameboard.h"
#include "ui_gameboard.h"


GameBoard::GameBoard(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameBoard)
{
    ui->setupUi(this);
    setWindowTitle("AImaster!!");
    this->setMouseTracking(true);
    initBoard(Board);
    is_black=true;
    gameover=false;
    last_pt.x=-1;last_pt.y=-1;
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
    Drawer::drawBoard(painter);//绘制基本棋盘
    Drawer::drawSign(painter,mousePos);
    Drawer::drawStones(painter,Board);
}


void GameBoard::mouseMoveEvent(QMouseEvent *event){
    mousePos=event->pos();       //获取鼠标位置
    update();
}

void GameBoard::mousePressEvent(QMouseEvent *event){
    if(event->button()==Qt::LeftButton){
        QPoint clickPos=event->pos();
        bool change =Drawer::clickreact(clickPos,Board,is_black,last_pt);
        if(change){
            update();
            AIthink(Board,last_pt);
            update();
        }
    }

}




