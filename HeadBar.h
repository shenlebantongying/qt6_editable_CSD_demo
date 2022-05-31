#ifndef HEADBAR_H
#define HEADBAR_H

#include <QToolBar>
#include <QEvent>
#include <QWindow>
#include <QToolButton>

class HeadBar : public QToolBar
{
    Q_OBJECT
public:
  HeadBar(QWidget *parent = nullptr);

  // maintain our own action list
  QList<QAction*> m_action;


  // give the caller a handle of the default action.

  QAction * addToolBtn(QAction *action);

  bool event(QEvent *event) override;
  void dragEnterEvent(QDragEnterEvent *event) override;
  void dragMoveEvent(QDragMoveEvent *p_event) override;
  void dropEvent(QDropEvent *event) override;


signals:
  void request_move_window();
  void request_window_resize(Qt::Edges edge);
};

#endif // HEADBAR_H
