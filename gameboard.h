#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class GameBoard;
}

class GameBoard : public QWidget
{
    Q_OBJECT

public:
    explicit GameBoard(QWidget *parent = nullptr);
    ~GameBoard();
protected:
    void paintEvent(QPaintEvent * event)override;
    void mousePressEvent(QMouseEvent *event) override;
private slots:
    void on_giveupButton_clicked();

private:
    Ui::GameBoard *ui;
    bool is_black;
    QPoint last_click_pos;
};

#endif // GAMEBOARD_H
