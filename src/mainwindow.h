#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include <QString>
#include <vector>
#include <QKeyEvent>
#include <QMessageBox>
#include <QDebug>

#include "model.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setBoard(vector<int> status);
    QString getBackgroundColor(int index);

signals:
  void keyCaught(QKeyEvent *e);

private slots:
  void handleKeyPress(QKeyEvent *e);

protected:
  virtual void  keyPressEvent(QKeyEvent *event);


private:
    Ui::MainWindow *ui;
    void setBoardColor(vector<int> status);
    void setBoardNumber(vector<int> status);

    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();

    model *m;

};

#endif // MAINWINDOW_H
