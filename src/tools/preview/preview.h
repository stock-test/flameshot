#pragma once

#include "src/tools/capturetool.h"
#include <QPointer>

class PreviewWindow : public CaptureTool {
    Q_OBJECT
public:
    explicit PreviewWindow(QObject *parent = nullptr);

    QIcon icon(const QColor &background,
               bool inEditor) const override;
    bool isValid() const override;
    bool closeOnButtonPressed() const override;
    bool isSelectable() const override;
    bool showMousePreview() const override;
    QString name() const override;
    static QString nameID();
    QString description() const override;

    QWidget* widget() override;
    QWidget* configurationWidget() override;
    CaptureTool* copy(QObject *parent = nullptr) override;

    void undo(QPixmap &pixmap) override;
    void process(
            QPainter &painter, const QPixmap &pixmap, bool recordUndo = false) override;
    void paintMousePreview(QPainter &painter, const CaptureContext &context) override;

public slots:
    void drawEnd(const QPoint &p) override;
    void drawMove(const QPoint &p) override;
    void drawStart(const CaptureContext &context) override;
    void pressed(const CaptureContext &context) override;
    void colorChanged(const QColor &c) override;
    void thicknessChanged(const int th) override;

private:
    QString m_text;
};
