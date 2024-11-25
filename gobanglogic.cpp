#include "gobanglogic.h"
#include <QPoint>
#include <QDebug>
int bestX=-1;int bestY=-1;
const int DEPTH=3;
const int DIRECTIONS[4][2] = {{0, 1}, {1, 0}, {1, 1}, {-1, 1}};
void initBoard(int board[BOARD_SIZE][BOARD_SIZE]){
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
}



int evaluateBoard(int board[BOARD_SIZE][BOARD_SIZE],int color,double bias){
    double score=0;    bool is_only;           //总分 临时数据
    short k;        int now_color=0;        //是否唯一（不唯一则值为0） 计数  是否为正
    int chessList;  int px;     int py;     //录入棋子链 临时x与y

    for(int i=0;i<BOARD_SIZE-5;i++){    //001
        for(int j=5;j<BOARD_SIZE;j++){  //010
                                        //100
            is_only=true;   k=0;
            chessList=0;    px=i;   py=j;
            while(board[px][py]==0 && k<5){
                py=py+DIRECTIONS[3][0];px=px+DIRECTIONS[3][1];
                k++;
            }now_color=board[px][py];
            while(k<5 && is_only){
                if(now_color==-board[px][py]){
                    is_only=false;
                }
                chessList=chessList*2+(board[px][py]==0 ? 0:1);
                py=DIRECTIONS[3][0]+py;px=DIRECTIONS[3][1]+px;
                k++;
            }
            if(k==5 && is_only){
                score+=results[chessList]*(now_color*color)*(now_color==color ? 1:bias);//这里因为color是-1和1，所有相同是正，相反是减
            }
        }
    }

    for(int i=0;i<BOARD_SIZE-5;i++){      //100
        for(int j=0;j<BOARD_SIZE-5;j++){  //010
                                          //001
            is_only=true;   k=0;
            chessList=0;    px=i;   py=j;
            while(board[px][py]==0 && k<5){
                py=py+DIRECTIONS[2][0];px=px+DIRECTIONS[2][1];
                k++;
            }now_color=board[px][py];
            while(k<5 && is_only){
                if(now_color==-board[px][py]){
                    is_only=false;
                }
                chessList=chessList*2+(board[px][py]==0 ? 0:1);
                py=DIRECTIONS[2][0]+py;px=DIRECTIONS[2][1]+px;
                k++;
            }
            if(k==5 && is_only){
                score+=results[chessList]*(now_color*color)*(now_color==color ? 1:bias);//这里因为color是-1和1，所有相同是正，相反是减
            }
        }
    }

    for(int i=0;i<BOARD_SIZE-5;i++){      //000
        for(int j=0;j<BOARD_SIZE;j++){    //111
                                          //000
            is_only=true;   k=0;
            chessList=0;    px=i;   py=j;
            while(board[px][py]==0 && k<5){
                py=py+DIRECTIONS[1][1];px=px+DIRECTIONS[1][0];
                k++;
            }now_color=board[px][py];
            while(k<5 && is_only){
                if(now_color==-board[px][py]){
                    is_only=false;
                }
                chessList=chessList*2+(board[px][py]==0 ? 0:1);
                py=DIRECTIONS[1][1]+py;px=DIRECTIONS[1][0]+px;
                k++;
            }
            if(k==5 && is_only){
                score+=results[chessList]*(now_color*color)*(now_color==color ? 1:bias);//这里因为color是-1和1，所有相同是正，相反是减
            }
        }
    }

    for(int i=0;i<BOARD_SIZE;i++){        //010
        for(int j=0;j<BOARD_SIZE-5;j++){  //010
                                          //010
            is_only=true;   k=0;
            chessList=0;    px=i;   py=j;
            while(board[px][py]==0 && k<5){
                py=py+DIRECTIONS[0][1];px=px+DIRECTIONS[0][0];
                k++;
            }now_color=board[px][py];
            while(k<5 && is_only){
                if(now_color==-board[px][py]){
                    is_only=false;
                }
                chessList=chessList*2+(board[px][py]==0 ? 0:1);
                py=DIRECTIONS[0][1]+py;px=DIRECTIONS[0][0]+px;
                k++;
            }
            if(k==5 && is_only){
                score+=results[chessList]*(now_color*color)*(now_color==color ? 1:bias);//这里因为color是-1和1，所有相同是正，相反是减
            }
        }
    }

    return score;
}

void AIthink(int board[BOARD_SIZE][BOARD_SIZE]){
    alphabeta(board,-INF,INF,DEPTH,false,-1);
    board[bestX][bestY]=-1;

}

int alphabeta(int board[BOARD_SIZE][BOARD_SIZE], int alpha, int beta, int depth, bool isMax, int color) {
    int score;
    if (depth == 0) {
        return evaluateBoard(board,color,0.5);
    }

    if (isMax) {
        score = -INF;
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                if (board[i][j] == 0) {
                    board[i][j] = color;
                    score = std::max(score, alphabeta(board, alpha, beta, depth - 1, false, -color));
                    board[i][j] = 0;

                    if (score > alpha) {
                        alpha = score;
                        bestX = i;
                        bestY = j; // 更新最佳位置
//                        qDebug() << "Current score: " << score << " at depth: " << depth ;
                    }
                    if (beta <= alpha) {
                        break; // 剪枝
                    }
                }
            }
        }
    } else {
        score = INF;
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                if (board[i][j] == 0) {
                    board[i][j] = -color;
                    score = std::min(score, alphabeta(board, alpha, beta, depth - 1, true, color));
                    board[i][j] = 0;

                    if (score < beta) {
                        beta = score;
                        bestX = i;
                        bestY = j; // 更新最佳位置
//                        qDebug() << "Current score: " << score << " at depth: " << depth ;
                    }
                    if (beta <= alpha) {
                        break; // 剪枝
                    }
                }
            }
        }
    }

    return score;
}

/*int alphabeta(int board[BOARD_SIZE][BOARD_SIZE], int alpha, int beta, int depth, bool isMax, int color) {
    int score;
    if (depth == 0) {
        return evaluateBoard(board, color);
    }        // 最大        最小      深度        极大极小标志    棋色
    if (isMax) {
        score = -INF;
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                if (board[i][j] == 0) {
                    board[i][j] = color;
                    score = std::max(score, alphabeta(board, alpha, beta, depth - 1, false, -color));
                    board[i][j] = 0;
                    if (score > alpha) {
                        alpha = score;
                        bestX = i;
                        bestY = j; // 更新最佳位置
                    }else{
                        break;
                    }
                }
            }
        }
    } else {
        score = INF;
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                if (board[i][j] == 0) {
                    board[i][j] = -color;
                    score = std::min(score, alphabeta(board, alpha, beta, depth - 1, true, color));
                    board[i][j] = 0;
                    if (score < beta) {
                        beta = score;
                        bestX = i;
                        bestY = j; // 更新最佳位置
                    }else{
                        break;
                    }
                }
            }
        }
    }
    return score;
}
*/
/*void dfstree(int MAXscore[LAYER],int board[BOARD_SIZE][BOARD_SIZE],int pointchoice[LAYER][2],int layer,int color){
    for(int i=0;i<BOARD_SIZE;i++){
        for(int j=0;j<BOARD_SIZE;j++){
            if(board[i][j]==0){
                board[i][j]=color;
                int temp=evaluateBoard(board,color);
                if(temp > MAXscore[layer]){
                    MAXscore[layer]=temp;
                    pointchoice[layer][0]=i;pointchoice[layer][1]=j;
                    if(layer<LAYER) dfstree(MAXscore,board,pointchoice,layer+1,-color);
                    if(layer==LAYER)bestchoice[0]=pointchoice[0][0];bestchoice[1]=pointchoice[0][1];
                }
                board[i][j]=0;
            }
        }
    }
}
*/

/*int evaluateBoard(int board[BOARD_SIZE][BOARD_SIZE],int color){
    int score=0;    bool is_only;           //总分 临时数据
    short k;        int now_color=0;        //是否唯一（不唯一则值为0） 计数  是否为正
    int chessList;  int px;     int py;     //录入棋子链 临时x与y

    for(int i=5;i<BOARD_SIZE;i++){
        for(int j=0;j<BOARD_SIZE;j++){

            is_only=true;   k=0;
            chessList=0;    px=i;   py=j;
            while(board[px][py]==0 && k<5){
                py=DIRECTIONS[3][0]+py;px=DIRECTIONS[3][1]+px;
                k++;
            }now_color=board[px][py];
            while(k<5 && is_only){
                if(now_color==-board[px][py]){
                    is_only=false;
                }
                chessList=chessList*2+(board[px][py]==0 ? 0:1);
                py=DIRECTIONS[3][0]+py;px=DIRECTIONS[3][1]+px;
                k++;
            }
            qDebug()<<chessList<<"#";
            qDebug()<<results[chessList];
            if(k==5 && is_only){
                score+=results[chessList]*(now_color*color);//这里因为color是-1和1，所有相同是正，相反是减
            }
        }
    }

//    score+=calculateByDir(board,color,0);

//    score+=calculateByDir(board,color,1);

//    score+=calculateByDir(board,color,2);

    return score;
}
*/

bool checkWin(int board[BOARD_SIZE][BOARD_SIZE], int x, int y, int color) {

    for (int i = 0; i < 4; ++i) {
        int dx = DIRECTIONS[i][0];
        int dy = DIRECTIONS[i][1];
        int nx = x + dx, ny = y + dy;
        // 检查一个方向
        int count = 1; // 已经有一个棋子
        while (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE && board[nx][ny] == color) {
            count++;
            nx += dx;
            ny += dy;
        }
        // 检查反方向
        nx = x - dx;
        ny = y - dy;
        while (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE && board[nx][ny] == color) {
            count++;
            nx -= dx;
            ny -= dy;
        }
        if (count >= 5) {
            return true; // 找到五个连续的棋子
        }
    }
    return false;
}


/*bool isGameOver(int board[BOARD_SIZE][BOARD_SIZE],int x,int y){
    int px;int py;int nums;
    int direct[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
    for(int i=0;i<4;i++){
        px=x;py=y;nums=0;
        qDebug()<<i<<":";
        while((px+direct[i*2][0]>=0 && px+direct[i*2][0] >=0) && (px+direct[i*2][0]<BOARD_SIZE && py+direct[i*2][0]<BOARD_SIZE) &&
               board[px][py]==board[px+direct[i*2][0]][py+direct[i*2][1]] ){
            px=px+direct[i*2][0];py=px+direct[i*2][0];
            qDebug()<<board[px][py]<<" "<<board[px+direct[i*2][0]][py+direct[i*2][1]];
        }
        while((px+direct[i*2+1][0]>=0 && px+direct[i*2+1][0] >=0) && (px+direct[i*2+1][0]<BOARD_SIZE && py+direct[i*2+1][0]<BOARD_SIZE) &&
               board[px][py]==board[px+direct[i*2+1][0]][py+direct[i*2+1][1]]){
            px=px+direct[i*2+1][0];py=px+direct[i*2+1][0];
            nums+=1;
            qDebug()<<nums;
        }
        if(nums>=5){
            return true;
        }
    }
    return false;
}*/
