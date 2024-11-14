#include "gameboard.h"
#include "ui_gameboard.h"
#include "drawtools.h"
#include "widget.h"

GameBoard::GameBoard(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameBoard),
    is_black(true), // 初始为黑棋
    last_click_pos(-1, -1)
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
void GameBoard::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(Qt::black, 2));
    Drawer::drawBoard(painter);

    // 绘制棋子
    if (last_click_pos != QPoint(-1, -1)) {
        Drawer::drawStone(painter, last_click_pos, is_black);
    }
}

void GameBoard::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        last_click_pos = event->pos(); // 记录点击位置
        is_black = !is_black; // 切换棋子颜色
        update(); // 触发重绘整个控件
    }
}



