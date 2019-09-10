#include "preview_win.h"

#include <QDragEnterEvent>
#include <QDebug>

PreviewWindow::PreviewWindow(QWidget *parent) :
    QMainWindow(parent),
    oldMousex(-1),
    oldMousey(-1)
{
    setWindowOpacity(1);
    setWindowFlags(Qt::FramelessWindowHint);
    // setAttribute(Qt::WA_TranslucentBackground);

    setGeometry(10, 10, 200, 200);
}

PreviewWindow::~PreviewWindow()
{
}

void PreviewWindow::dragEnterEvent(QDragEnterEvent *event)
{
    event->acceptProposedAction();
    QWidget::dragEnterEvent(event);
}

void PreviewWindow::mouseMoveEvent(QMouseEvent *event)
{
    // qDebug() << event->x();
    if (oldMousex == -1) {
        return;
    }

    auto geom = geometry();

    int mouseXDelta = oldMousex - event->x();
    int mouseYDelta = oldMousey - event->y();
    int winX = geom.x() - mouseXDelta;
    int winY = geom.y() - mouseYDelta;
    qDebug() << mouseXDelta;
    setGeometry(winX, winY, size().width(), size().height());
}

void PreviewWindow::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "press";
    oldMousex = event->x();
    oldMousey = event->y();
}

void PreviewWindow::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "release";
}

void PreviewWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape) {
        close();
    }
}
