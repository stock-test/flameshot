
#include "preview.h"
#include "../../core/controller.h"

#include <QDebug>

PreviewWindow::PreviewWindow(QObject *parent) : CaptureTool(parent) {

}

bool PreviewWindow::isValid() const {
    return !m_text.isEmpty();
}

bool PreviewWindow::closeOnButtonPressed() const {
    return false;
}

bool PreviewWindow::isSelectable() const {
    return true;
}

bool PreviewWindow::showMousePreview() const {
    return false;
}

QIcon PreviewWindow::icon(const QColor &background,
                          bool inEditor) const
{
    return QIcon(iconPath(background) + "text.svg");
}

QString PreviewWindow::name() const {
    return tr("Text");
}

QString PreviewWindow::nameID() {
    return QLatin1String("");
}

QString PreviewWindow::description() const {
    return tr("Add text to your capture");
}

QWidget *PreviewWindow::widget() {
//    TextWidget *w = new TextWidget();
//    w->setTextColor(m_color);
//    m_font.setPointSize(m_size + BASE_POINT_SIZE);
//    w->setFont(m_font);
//    connect(w, &TextWidget::textUpdated,
//            this, &TextTool::updateText);
//    m_widget = w;
//    return w;
    return nullptr;
}
QWidget *PreviewWindow::configurationWidget() {
//    m_confW = new TextConfig();
//    connect(m_confW, &TextConfig::fontFamilyChanged,
//            this, &TextTool::updateFamily);
//    connect(m_confW, &TextConfig::fontItalicChanged,
//            this, &TextTool::updateFontItalic);
//    connect(m_confW, &TextConfig::fontStrikeOutChanged,
//            this, &TextTool::updateFontStrikeOut);
//    connect(m_confW, &TextConfig::fontUnderlineChanged,
//            this, &TextTool::updateFontUnderline);
//    connect(m_confW, &TextConfig::fontWeightChanged,
//            this, &TextTool::updateFontWeight);
//    m_confW->setItalic(m_font.italic());
//    m_confW->setUnderline(m_font.underline());
//    m_confW->setStrikeOut(m_font.strikeOut());
//    m_confW->setWeight(m_font.weight());
//    return m_confW;

    return nullptr;
}

CaptureTool *PreviewWindow::copy(QObject *parent) {
//    TextTool *tt = new TextTool(parent);
//    connect(m_confW, &TextConfig::fontFamilyChanged,
//            tt, &TextTool::updateFamily);
//    connect(m_confW, &TextConfig::fontItalicChanged,
//            tt, &TextTool::updateFontItalic);
//    connect(m_confW, &TextConfig::fontStrikeOutChanged,
//            tt, &TextTool::updateFontStrikeOut);
//    connect(m_confW, &TextConfig::fontUnderlineChanged,
//            tt, &TextTool::updateFontUnderline);
//    connect(m_confW, &TextConfig::fontWeightChanged,
//            tt, &TextTool::updateFontWeight);
//    tt->m_font = m_font;
//    return tt;
    return nullptr;
}

void PreviewWindow::undo(QPixmap &pixmap) {
    QPainter p(&pixmap);
    // p.drawPixmap(m_backupArea.topLeft(), m_pixmapBackup);
}

void PreviewWindow::process(QPainter &painter, const QPixmap &pixmap, bool recordUndo) {
//    if (m_text.isEmpty()) {
//        return;
//    }
//    QFontMetrics fm(m_font);
//    QSize size(fm.boundingRect(QRect(), 0, m_text).size());
//    m_backupArea.setSize(size);
//    if (recordUndo) {
//        m_pixmapBackup = pixmap.copy(m_backupArea + QMargins(0, 0, 5, 5));
//    }
//    // draw text
//    painter.setFont(m_font);
//    painter.setPen(m_color);
//    painter.drawText(m_backupArea + QMargins(-5, -5, 5, 5), m_text);
}

void PreviewWindow::paintMousePreview(QPainter &painter, const CaptureContext &context) {
    Q_UNUSED(painter);
    Q_UNUSED(context);
}

void PreviewWindow::drawEnd(const QPoint &p) {
//    m_backupArea.moveTo(p);
}

void PreviewWindow::drawMove(const QPoint &p) {
//    m_widget->move(p);
}

void PreviewWindow::drawStart(const CaptureContext &context) {
//    m_color = context.color;
//    m_size = context.thickness;
//    emit requestAction(REQ_ADD_CHILD_WIDGET);
}

void PreviewWindow::pressed(const CaptureContext &context) {
    Q_UNUSED(context);
    // Controller::getInstance()->
}

void PreviewWindow::colorChanged(const QColor &c) {
//    m_color = c;
//    if (m_widget) {
//        m_widget->setTextColor(c);
//    }
}

void PreviewWindow::thicknessChanged(const int th) {
//    m_size = th;
//    m_font.setPointSize(m_size + BASE_POINT_SIZE);
//    if (m_widget) {
//        m_widget->setFont(m_font);
//    }
}
