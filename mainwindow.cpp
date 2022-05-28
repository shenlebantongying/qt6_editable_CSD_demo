#include "mainwindow.h"
#include <QApplication>
#include <QMouseEvent>
#include <QPainter>
#include <QWindow>
#include <QSizePolicy>
#include <QPushButton>
constexpr qreal border = 15;
constexpr int w = 1;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

   setWindowFlag(Qt::FramelessWindowHint);
   resize(600,400);

   setContentsMargins(w,w,w,w);
   headbar = new HeadBar();

// Enable hove move event
   setAttribute(Qt::WA_Hover);

// close, fullscreen, and close
   close = new QToolButton();
   auto * close_a = new QAction(QIcon::fromTheme("window-close"),"Close",this);
   close->setDefaultAction(close_a);
   headbar->addWidget(close);
   connect(close_a,&QAction::triggered,
           [=,this](){QApplication::quit();});

   fullscreen = new QToolButton();
   auto * max_a = new QAction(QIcon::fromTheme("window-maximize"),"Maximize",this);
   fullscreen->setDefaultAction(max_a);
   headbar->addWidget(fullscreen);
   connect(max_a,&QAction::triggered,
           [=,this](){ setWindowState(Qt::WindowMaximized);});

   minimize = new QToolButton();
   auto * mini_a = new QAction(QIcon::fromTheme("window-minimize"),"Minimize",this);
   minimize->setDefaultAction(mini_a);
   headbar->addWidget(minimize);
   connect(mini_a,&QAction::triggered,
           [=,this](){ setWindowState(Qt::WindowMinimized);});

// titlebar in middle
   auto title = new QLabel("CSD style window written in Qt");
   title->setAlignment(Qt::AlignCenter);
   title->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
   headbar->addWidget(title);

// a btn on right;
  auto r_btn = new QPushButton("What?");
  headbar->addWidget(r_btn);

//
   addToolBar(headbar);

   connect(headbar,&HeadBar::request_move_window,
           [=,this]{
              this->windowHandle()->startSystemMove();
           });

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
