#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "myutils.h"
#include "model.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m = new model;
    m->init();

    setBoard(m->getStatus());

    connect(this, &MainWindow::keyCaught, this, &MainWindow::handleKeyPress);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::keyPressEvent(QKeyEvent* event){
    emit keyCaught(event);
}


void MainWindow::handleKeyPress(QKeyEvent *event) {
    qDebug() << ("\nkey event in board: %i", event->key());

    switch (event->key()) {
    case 16777234:
        moveLeft();
        break;
    case 16777235:
        moveUp();
        break;
    case 16777236:
        moveRight();
        break;
    case 16777237:
        moveDown();
        break;
    default:
        break;
    }
    m->appear();
    if (m->isDead()) {
        QMessageBox::about(this, "游戏结束", "最终得分："+QString::number(m->getPoints()));
        m->init();
    }


    setBoard(m->getStatus());
    ui->statusBar->showMessage("得分：" + QString::number(m->getPoints()));


}


void MainWindow::moveLeft() {
    m->movel();
}


void MainWindow::moveRight() {
    m->mover();
}



void MainWindow::moveUp() {
    m->moveu();
}


void MainWindow::moveDown() {
    m->moved();
}











void MainWindow::setBoard(vector<int> status) {
    setBoardColor(status);
    setBoardNumber(status);
}


void MainWindow::setBoardColor(vector<int> status) {
    ui->label->setStyleSheet(getBackgroundColor(status[0]));
    ui->label_2->setStyleSheet(getBackgroundColor(status[1]));
    ui->label_3->setStyleSheet(getBackgroundColor(status[2]));
    ui->label_4->setStyleSheet(getBackgroundColor(status[3]));
    ui->label_5->setStyleSheet(getBackgroundColor(status[4]));
    ui->label_6->setStyleSheet(getBackgroundColor(status[5]));
    ui->label_7->setStyleSheet(getBackgroundColor(status[6]));
    ui->label_8->setStyleSheet(getBackgroundColor(status[7]));
    ui->label_9->setStyleSheet(getBackgroundColor(status[8]));
    ui->label_10->setStyleSheet(getBackgroundColor(status[9]));
    ui->label_11->setStyleSheet(getBackgroundColor(status[10]));
    ui->label_12->setStyleSheet(getBackgroundColor(status[11]));
    ui->label_13->setStyleSheet(getBackgroundColor(status[12]));
    ui->label_14->setStyleSheet(getBackgroundColor(status[13]));
    ui->label_15->setStyleSheet(getBackgroundColor(status[14]));
    ui->label_16->setStyleSheet(getBackgroundColor(status[15]));
}



void MainWindow::setBoardNumber(vector<int> status) {
    ui->label->setText(QString::number(status[0]));
    ui->label_2->setText(QString::number(status[1]));
    ui->label_3->setText(QString::number(status[2]));
    ui->label_4->setText(QString::number(status[3]));
    ui->label_5->setText(QString::number(status[4]));
    ui->label_6->setText(QString::number(status[5]));
    ui->label_7->setText(QString::number(status[6]));
    ui->label_8->setText(QString::number(status[7]));
    ui->label_9->setText(QString::number(status[8]));
    ui->label_10->setText(QString::number(status[9]));
    ui->label_11->setText(QString::number(status[10]));
    ui->label_12->setText(QString::number(status[11]));
    ui->label_13->setText(QString::number(status[12]));
    ui->label_14->setText(QString::number(status[13]));
    ui->label_15->setText(QString::number(status[14]));
    ui->label_16->setText(QString::number(status[15]));
}


QString MainWindow::getBackgroundColor(int index) {
    switch (index) {
        case 0:
        return "background-color: #FFFFFF;";
        case 2:
        return "background-color: #CCCC00;";
        case 4:
        return "background-color: #CC9900;";
        case 8:
        return "background-color: #CC6600;";
        case 16:
        return "background-color: #CC0000;";
        case 32:
        return "background-color: #FF6699;";
        case 64:
        return "background-color: #669900;";
        case 128:
        return "background-color: #66CCFF;";
        case 256:
        return "background-color: #9933FF;";
        case 512:
        return "background-color: #CC00FF;";
        case 1024:
        return "background-color: #33FFFF;";
        case 2048:
        return "background-color: #0099FF;";
        case 4096:
        return "background-color: #FF3366;";
        case 8192:
        return "background-color: #339933;";
        case 16384:
        return "background-color: #996699;";
        case 32768:
        return "background-color: #776699;";
        case 65536:
        return "background-color: #000099;";
        case 131072:
        return "background-color: #333333;";
        case 262144:
        return "background-color: #330000;";
        case 524288:
        return "background-color: #330066;";
        default:
        return "background-color: #FFCCFF;";
    }

}
