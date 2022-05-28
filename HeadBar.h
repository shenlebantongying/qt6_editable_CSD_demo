#ifndef HEADBAR_H
#define HEADBAR_H

#include <QToolBar>
#include <QEvent>
#include <QWindow>
class HeadBar : public QToolBar
{
    Q_OBJECT
public:
  HeadBar();
  bool event(QEvent *event) override;

signals:
  void request_move_window();
  void request_window_resize(Qt::Edges edge);
};

#endif // HEADBAR_H
