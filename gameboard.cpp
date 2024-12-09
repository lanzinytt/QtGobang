#include "gameboard.h"
#include "ui_gameboard.h"


GameBoard::GameBoard(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameBoard)
{
    ui->setupUi(this);
    setWindowTitle("AImaster!!");
    this->setMouseTracking(true);
    this->setStyleSheet("background-color: #FFFFE0;");
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
    if(gameover==false && event->button()==Qt::LeftButton){
        QPoint clickPos=event->pos();
        bool change =Drawer::clickreact(clickPos,Board,is_black,last_pt);
        if(change){
            update();
            gameover=checkWin(Board,last_pt.x,last_pt.y,1);
            if(gameover) ui->response->setText("你赢了，可恶");
            if(!gameover)AIthink(Board,last_pt);
            gameover=checkWin(Board,last_pt.x,last_pt.y,-1);
            if(gameover) ui->response->setText("还得练，杂鱼杂鱼");
            update();
        }
    }

}





void GameBoard::on_peaceButton_clicked()
{
    if(evaluateBoard(Board,-1,1)>0){
        ui->response->setText("AI觉得它胜券在握，并拒绝了和棋");
    }else{
        ui->response->setText("AI同意了和棋");
        gameover=true;
    }
}

