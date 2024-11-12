#ifndef DRAWTOOLS_H
#define DRAWTOOLS_H

#define BOARD_WIDTH 15  // 棋盘宽度，以格子数计
#define BOARD_HEIGHT 15 // 棋盘高度，以格子数计
#define CELL_SIZE 30   // 每个格子的大小，以像素计
#define START_POS_X 40   // 棋盘起始位置的X坐标
#define START_POS_Y 40   // 棋盘起始位置的Y坐标

#include <QPainter>
#include <QPointer>

class Drawer{
public:

    static  void drawBoard(QPainter &painter){
        for(int i=0;i<BOARD_WIDTH+1;i++){
            painter.drawLine(QPoint(START_POS_X+CELL_SIZE*i,START_POS_Y),QPoint(START_POS_X+CELL_SIZE*i,START_POS_Y+CELL_SIZE*BOARD_HEIGHT));
        }
        for(int i=0;i<BOARD_HEIGHT+1;i++){
            painter.drawLine(QPoint(START_POS_X,START_POS_Y+CELL_SIZE*i),QPoint(START_POS_X+CELL_SIZE*BOARD_WIDTH,START_POS_Y+CELL_SIZE*i));
        }
    }

    static  void drawStone(QPainter &painter, const QPoint &position, bool isBlack) {
        painter.setBrush(isBlack ? Qt::black : Qt::white);
        painter.setPen(Qt::NoPen);
        painter.drawEllipse(position, 12, 12);
    }

};


#endif // DRAWTOOLS_H
