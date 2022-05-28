#include "HeadBar.h"
#include <QMouseEvent>

HeadBar::HeadBar()
{
  setMovable(false);
  setFloatable(false);
  setContextMenuPolicy(Qt::PreventContextMenu);
}

bool HeadBar::event(QEvent *event){
  if (event->type() ==  QEvent::MouseButtonPress) {
    emit request_move_window();
  } else {
    return QToolBar::event(event);
  }
}