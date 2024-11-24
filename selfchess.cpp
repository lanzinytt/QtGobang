#include "selfchess.h"
#include "ui_selfchess.h"

selfchess::selfchess(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::selfchess)
{
    ui->setupUi(this);
    this->setMouseTracking(true);
    initBoard(Board);
    is_black=true;
    gameover=false;
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
    Drawer::drawSign(painter,mousePos);
    Drawer::drawStones(painter,Board);
}


void selfchess::mouseMoveEvent(QMouseEvent *event){
    mousePos=event->pos();       //获取鼠标位置
    update();
}

void selfchess::on_giveupButton_clicked()
{
    Widget *father=new Widget();
    this->close();
    father->show();
    delete this;
}
void selfchess::mousePressEvent(QMouseEvent *event){
    if(event->button()==Qt::LeftButton){
        QPoint clickPos=event->pos();
        bool change =Drawer::clickreact(clickPos,Board,is_black);
        if(change){
            is_black=!is_black;
            update();
            ui->judge_chess->setText(QString::number(evaluateBoard(Board,1)));
        }

    }
}

