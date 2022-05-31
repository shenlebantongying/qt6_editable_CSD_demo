#include "HeadBarEdit.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QMouseEvent>
#include <QMimeData>
#include <QSizePolicy>
#include <QPushButton>
#include <QListWidgetItem>

HeadBarEdit::HeadBarEdit(QWidget *parent, Qt::WindowFlags f)
    : QDialog(parent, f)
{

    auto m_layout = new QVBoxLayout();
    auto m_listview = new ListWidget();

    setLayout(m_layout);
    m_layout->addWidget(m_listview);

    // TODO: to support actions, you have to subclass QListWidgetItem and add something to carry a QAction?
    m_listview->addItem(new QListWidgetItem(QIcon::fromTheme("kde"),"kde"));
    m_listview->addItem(new QListWidgetItem(QIcon::fromTheme("okular"),"okular"));

    setMinimumSize(400, qMax(200, y()));

    setAcceptDrops(true);
}