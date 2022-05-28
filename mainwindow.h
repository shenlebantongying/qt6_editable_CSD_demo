#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "HeadBar.h"
#include <QLabel>
#include <QMainWindow>
#include <QToolButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    HeadBar * headbar;
    QToolButton * close;
    QToolButton * fullscreen;
    QToolButton * minimize;

    ~MainWindow();
    void mousePressEvent(QMouseEvent *event) override;
    void resize_q(const QPointF &p);
};
#endif // MAINWINDOW_H
