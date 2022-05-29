#include "mainwindow.h"
#include <QApplication>
#include <QMouseEvent>
#include <QPainter>
#include <QWindow>
#include <QSizePolicy>
#include <QPushButton>
#include <QAction>

constexpr qreal border = 15;
constexpr int w = 1;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

   setWindowFlag(Qt::FramelessWindowHint);
   resize(600,400);

   setAcceptDrops(true);

   setContentsMargins(w,w,w,w);
   headbar = new HeadBar(this);


   // if the headbar request win_move (which will be emitted by mouse click event)
   connect(headbar,&HeadBar::request_move_window,
           [=,this]{
             this->windowHandle()->startSystemMove();
           });

// Enable hove move event -> to change cursor when near window boarder.
   setAttribute(Qt::WA_Hover);

// close, fullscreen, and close

   auto close_ac = headbar->addToolBtn(new QAction(QIcon::fromTheme("window-close"),"Close"));
   connect(close_ac,&QAction::triggered,
           [=,this](){QApplication::quit();});

   auto fullscreen_ac = headbar->addToolBtn(new QAction(QIcon::fromTheme("window-maximize"),("fullscreen")));
   connect(fullscreen_ac,&QAction::triggered,
            [=,this]{
              qDebug()<<"what";
             if(windowState() == Qt::WindowMaximized){
               setWindowState(Qt::WindowNoState);
             } else {
               setWindowState(Qt::WindowMaximized);
             }});

   auto minimize_ac = headbar->addToolBtn(new QAction(QIcon::fromTheme("window-minimize"),"Minimize"));
   connect(minimize_ac,&QAction::triggered,
           [=,this](){ setWindowState(Qt::WindowMinimized);});

// Toolbar editor
   auto headBarEdit = new HeadBarEdit(this);

   auto toolbarEditor_ac = headbar->addToolBtn(new QAction(QIcon::fromTheme("entry-edit"),"ToolbarEdit"));

   connect(toolbarEditor_ac,&QAction::triggered,
           [=,this]{
             headBarEdit->show();
           });

   addToolBar(headbar);

}

bool MainWindow::event(QEvent *event) {

  // When hove to edge, change cursor
  if (event->type() == QEvent::HoverMove) {
      auto p = dynamic_cast<QHoverEvent *>(event)->position();

      if (p.y()>height()-border){
          if (p.x() < border){
            this->setCursor(Qt::SizeBDiagCursor);
          } else if (p.x() > width()-border){
            this->setCursor(Qt::SizeFDiagCursor);
          } else {
            this->setCursor(Qt::SizeVerCursor);
          }
      } else if ((p.y() > headbar->height())
                  and
                (((p.x() > width() - border) or (p.x() < border)))){
            this->setCursor(Qt::SizeHorCursor);
      } else {
        setCursor(Qt::ArrowCursor);
      }
  // if user press
  } else if (event->type() == QEvent::MouseButtonPress) {
      auto p = dynamic_cast<QMouseEvent *>(event)->position();
      Qt::Edges edges;
      if (p.x() > width() - border)
        edges |= Qt::RightEdge;
      if (p.x() < border)
        edges |= Qt::LeftEdge;
      if (p.y() > height() - border)
        edges |= Qt::BottomEdge;
      if (edges != 0) {
        // Note: on Mac, this will return false which means isn't supported.
        this->windowHandle()->startSystemResize(edges);
      }
  }
  // TODO: what does this mean?
  return QMainWindow::event(event);
}

MainWindow::~MainWindow()
= default;

void MainWindow::paintEvent(QPaintEvent *event) {
  auto pen = new QPen();
  pen->setWidth(w*2);
  pen->setColor(Qt::lightGray);
  QPainter p(this);
  p.setPen(*pen);
  p.drawRect(this->rect());
}


void MainWindow::dragEnterEvent(QDragEnterEvent *p_event)
{
  qDebug()<<"MainWindow"<<"dragEnterEvent";

  p_event->acceptProposedAction();
}

void MainWindow::dragMoveEvent(QDragMoveEvent *p_event)
{

  p_event->acceptProposedAction();
}

void MainWindow::dropEvent(QDropEvent *p_event)
{
  p_event->acceptProposedAction();
}
