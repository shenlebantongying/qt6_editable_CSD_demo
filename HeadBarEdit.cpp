#include "HeadBarEdit.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QMouseEvent>
#include <QMimeData>
#include <QSizePolicy>

HeadBarEdit::HeadBarEdit(QWidget *parent, Qt::WindowFlags f)
    : QDialog(parent, f)
{
    // settings

    auto m_layout = new QVBoxLayout();
    setLayout(m_layout);

    auto a_label = new QLabel("LONG_TEXT",this);
    a_label->setStyleSheet("border: 1px solid black");

    setMinimumSize(400, qMax(200, y()));

    setAcceptDrops(true);
}

void HeadBarEdit::mousePressEvent(QMouseEvent *event) {
  if (event->button() == Qt::LeftButton
      && this->childAt(event->pos())){

  auto label_widget = dynamic_cast<QLabel*>(this->childAt(event->pos()));

  auto *drag = new QDrag(this);

  auto mimeData = new QMimeData();
  mimeData->setText(label_widget->text());
  drag->setMimeData(mimeData);
  drag->setDragCursor(label_widget->grab(),Qt::MoveAction);

  Qt::DropAction dropAction = drag->exec( Qt::MoveAction, Qt::MoveAction);

  if (dropAction == Qt::MoveAction)
    label_widget->close();
  }
}

void HeadBarEdit::dragEnterEvent(QDragEnterEvent *event) {
  qDebug()<<"HeadBarEit"<<"dragEnterEvent";
  event->acceptProposedAction();
}


