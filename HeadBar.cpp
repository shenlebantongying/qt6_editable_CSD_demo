#include "HeadBar.h"
#include <QMouseEvent>
#include <QMimeData>
#include <QDebug>

HeadBar::HeadBar(QWidget *parent)
  : QToolBar(parent)
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
    event->acceptProposedAction();
}

void HeadBar::dragMoveEvent(QDragMoveEvent *p_event) {
  p_event->acceptProposedAction();
}

void HeadBar::dropEvent(QDropEvent *event)
{
    // format string: iconname;text

    auto dataStrings = event->mimeData()->text().split(";");
    auto act_icon = dataStrings.first();
    auto act_name = dataStrings.at(1);

    auto tempBtn = new QToolButton;

    tempBtn->setDefaultAction(new QAction(QIcon::fromTheme(act_icon),act_name));

    if (act_name == "kde"){
        connect(tempBtn->defaultAction(),&QAction::triggered,
                [=,this]{
                  qDebug()<<"kde_pressed";
                });
    } else if (act_name == "okular") {
      connect(tempBtn->defaultAction(),&QAction::triggered,
              [=,this]{
                qDebug()<<"okular pressed";
              });
    }


    addWidget(tempBtn);

    event->accept();
}

QAction * HeadBar::addToolBtn(QAction * action){
  auto tempBtn= new QToolButton();

  // Is it a bug or my understanding not enough?
  // After setting default action for QToolButton, the text will be lost.
  // Thus, we force set it here.
  tempBtn->setDefaultAction(action);
  tempBtn->defaultAction()->setText(action->text());

  this->addWidget(tempBtn);

  return tempBtn->defaultAction();
}
