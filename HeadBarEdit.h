#ifndef HEADBAREDIT_H
#define HEADBAREDIT_H

#include "HeadBar.h"
#include <QDialog>
#include <QDrag>
#include <QToolButton>

class HeadBarEdit : public QDialog
{
    Q_OBJECT
public:
  HeadBarEdit(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
  void mousePressEvent(QMouseEvent *event) override;

  void dragEnterEvent(QDragEnterEvent *event) override;
};

#endif // HEADBAREDIT_H
