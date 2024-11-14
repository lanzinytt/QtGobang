#ifndef DRAWTOOLS_H
#define DRAWTOOLS_H

#define BOARD_WIDTH 15  // 棋盘宽度，以格子数计
#define BOARD_HEIGHT 15 // 棋盘高度，以格子数计
#define CELL_SIZE 30   // 每个格子的大小，以像素计
#define START_POS_X 40   // 棋盘起始位置的X坐标
#define START_POS_Y 40   // 棋盘起始位置的Y坐标
#define SIGN_RANGE 10 //鼠标提示的范围
#define SIGN_SIZE 5
#define CHESS_SIZE 12
#include <QPainter>
#include <QPointer>
#include <cmath>

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
    static void drawSign(QPainter &painter,const QPoint &position){
        //int px=position.x();int py=position.y();
        painter.drawEllipse(position,SIGN_SIZE,SIGN_SIZE);
        /*if((px-START_POS_X-SIGN_RANGE)<0 || (START_POS_X+BOARD_WIDTH*CELL_SIZE-px)<0
        || (py-START_POS_Y-SIGN_RANGE)<0 || (START_POS_Y+BOARD_HEIGHT*CELL_SIZE-py)<0){
            return;
        }else{
            int x=std::floor(((px-START_POS_X)/CELL_SIZE)+0.5);
            int y=std::floor(((py-START_POS_Y)/CELL_SIZE)+0.5);
            painter.drawEllipse(x,y,SIGN_SIZE,SIGN_SIZE);
        }*/
    }

    static  void drawStone(QPainter &painter, const QPoint &position, bool isBlack) {
        painter.setBrush(isBlack ? Qt::black : Qt::white);
        painter.setPen(Qt::NoPen);
        painter.drawEllipse(position, CHESS_SIZE, CHESS_SIZE);
    }

};




#endif // DRAWTOOLS_H
