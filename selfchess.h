#ifndef SELFCHESS_H
#define SELFCHESS_H

#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class selfchess;
}

class selfchess : public QWidget
{
    Q_OBJECT
public:
    explicit selfchess(QWidget *parent = nullptr);
    ~selfchess();
protected:
    void paintEvent(QPaintEvent * event)override;
private slots:
    void on_giveupButton_clicked();

private:
    Ui::selfchess *ui;
};

#endif // SELFCHESS_H
