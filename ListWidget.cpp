#include "ListWidget.h"
#include <QMouseEvent>
#include <QListWidgetItem>
#include <QDrag>
#include <QMimeData>

ListWidget::ListWidget()
{
  setFlow(QListView::LeftToRight);
  setWrapping(true);

  setAcceptDrops(true);

  // Avoid first item highlighting
  setFocusPolicy(Qt::NoFocus);
}

void ListWidget::mousePressEvent(QMouseEvent *event) {
  if (event->button() == Qt::LeftButton
      && this->itemAt(event->pos())) {

    auto listWidgetItem =
        dynamic_cast<QListWidgetItem *>(this->itemAt(event->pos()));

    auto *drag = new QDrag(this);

    auto mimeData = new QMimeData();

    // TODO: Note: This is the icon name we are passing.
    mimeData->setText(listWidgetItem->text());
    drag->setMimeData(mimeData);
    drag->setDragCursor(listWidgetItem->icon().pixmap(22, 22), Qt::MoveAction);

    Qt::DropAction dropAction = drag->exec(Qt::MoveAction, Qt::MoveAction);

    if (dropAction == Qt::MoveAction) {
      // removeItemWidget(listWidgetItem);
    }
  }
}
void ListWidget::dropEvent(QDropEvent *p_event) {
  p_event->acceptProposedAction();
}
void ListWidget::dragEnterEvent(QDragEnterEvent *p_event) {
  p_event->acceptProposedAction();
}
void ListWidget::dragMoveEvent(QDragMoveEvent *p_event) {
  p_event->acceptProposedAction();
}
