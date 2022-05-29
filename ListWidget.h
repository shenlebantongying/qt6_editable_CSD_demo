#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QListWidget>

class ListWidget : public QListWidget
{
    Q_OBJECT
public:
    ListWidget();
    void mousePressEvent(QMouseEvent *event) override;
    void dropEvent(QDropEvent *p_event) override;
    void dragEnterEvent(QDragEnterEvent *p_event) override;
    void dragMoveEvent(QDragMoveEvent *p_event) override;
};

#endif // LISTWIDGET_H
