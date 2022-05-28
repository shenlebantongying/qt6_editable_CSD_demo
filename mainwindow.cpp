#include "mainwindow.h"
#include <QApplication>
#include <QMouseEvent>
#include <QPainter>
#include <QWindow>
#include <QSizePolicy>
#include <QPushButton>

constexpr qreal border = 15;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

   setWindowFlag(Qt::FramelessWindowHint);
   resize(600,400);

   headbar = new HeadBar();

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

void MainWindow::mousePressEvent(QMouseEvent *event){
  resize_q(event->position());
}

void MainWindow::resize_q(const QPointF &p)
{
  Qt::Edges edges;
  if (p.x() > width() - border)
    edges |= Qt::RightEdge;
  if (p.x() < border)
    edges |= Qt::LeftEdge;
  if (p.y() > height() - border)
    edges |= Qt::BottomEdge;
  if (edges != 0) {
    this->windowHandle()->startSystemResize(edges);
  }
}

MainWindow::~MainWindow()
= default;

