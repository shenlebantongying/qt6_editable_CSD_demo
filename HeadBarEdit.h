#ifndef HEADBAREDIT_H
#define HEADBAREDIT_H

#include "HeadBar.h"
#include <QDialog>
#include <QDrag>
#include <QToolButton>

#include "ListWidget.h"

class HeadBarEdit : public QDialog
{
    Q_OBJECT
public:
  HeadBarEdit(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
};

#endif // HEADBAREDIT_H
