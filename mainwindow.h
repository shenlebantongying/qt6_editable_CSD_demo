#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "HeadBar.h"
#include "HeadBarEdit.h"
#include <QLabel>
#include <QMainWindow>
#include <QToolButton>
#include <QHoverEvent>
#include <QMouseEvent>

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

    void paintEvent(QPaintEvent *event) override;
    bool event(QEvent *event) override;

    void dropEvent(QDropEvent *p_event) override;
    void dragEnterEvent(QDragEnterEvent *p_event) override;
    void dragMoveEvent(QDragMoveEvent *p_event) override;
};
#endif // MAINWINDOW_H
