#include "HeadBar.h"
#include <QMouseEvent>
#include <QMimeData>

HeadBar::HeadBar()
{
  setMovable(false);
  setFloatable(false);

  setAcceptDrops(true);

  setContextMenuPolicy(Qt::PreventContextMenu);
}

bool HeadBar::event(QEvent *event){
  if (event->type() ==  QEvent::MouseButtonPress) {
    emit request_move_window();
  }

  return QToolBar::event(event);
}

void HeadBar::dragEnterEvent(QDragEnterEvent *event)
{
    qDebug()<< "HeadBar" << "dragEnterEvent";
    event->acceptProposedAction();
}

void HeadBar::dragMoveEvent(QDragMoveEvent *p_event) {
  p_event->acceptProposedAction();
}


void HeadBar::dropEvent(QDropEvent *event)
{
    qDebug()<< "GOT" << event->mimeData()->text();
    event->accept();
}

