#pragma once

#ifndef QSSDEBUGWIDGET_H
#define QSSDEBUGWIDGET_H

#include <QApplication>
#include <QMimeData>
#include <QWidget>
#include <QFile>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QLabel>
#include <QVBoxLayout>
#include <QFileInfo>
#include <QDragEnterEvent>
#include <QUrl>

class QSSDebugWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QSSDebugWidget(QWidget* parent = nullptr)
        : QWidget(parent, Qt::Tool | Qt::FramelessWindowHint)
        , m_dragging(false)
    {
        initUI();
        setAcceptDrops(true);
    }

    void loadQSS(const QString& filePath)
    {
        QFile file(filePath);
        if (file.open(QFile::ReadOnly)) {
            qApp->setStyleSheet(file.readAll());
            file.close();
            m_qssPath = filePath;
            updateLabel();
        }
    }

protected:
    void dragEnterEvent(QDragEnterEvent* event) override
    {
        if (event->mimeData()->hasUrls()) {
            event->acceptProposedAction();
        }
    }

    void dropEvent(QDropEvent* event) override
    {
        const QMimeData* mimeData = event->mimeData();
        if (mimeData->hasUrls()) {
            QUrl url = mimeData->urls().first();
            QString filePath = url.toLocalFile();
            if (filePath.endsWith(".qss", Qt::CaseInsensitive) ||
                filePath.endsWith(".css", Qt::CaseInsensitive)) {
                loadQSS(filePath);
            }
        }
    }

    void mousePressEvent(QMouseEvent* event) override
    {
        if (event->button() == Qt::LeftButton) {
            m_dragging = true;
            m_dragPos = event->globalPos() - frameGeometry().topLeft();
            event->accept();
        }
    }

    void mouseMoveEvent(QMouseEvent* event) override
    {
        if (event->buttons() & Qt::LeftButton && m_dragging) {
            move(event->globalPos() - m_dragPos);
            event->accept();
        }
    }

    void mouseReleaseEvent(QMouseEvent* event) override
    {
        m_dragging = false;
    }

    void keyPressEvent(QKeyEvent* event) override
    {
        if (event->modifiers() & Qt::ControlModifier && event->key() == Qt::Key_R) {
            if (!m_qssPath.isEmpty()) {
                loadQSS(m_qssPath);
            }
            event->accept();
        }
    }

private:
    void initUI()
    {
        // 父窗口透明，边框由子 widget 呈现
        setAttribute(Qt::WA_TranslucentBackground);
        setFixedSize(210, 60);

        // 子 widget 作为内容区，border 生效
        m_container = new QWidget(this);
        m_container->setFixedSize(200, 50);
        m_container->move(5, 5);
        m_container->setStyleSheet(R"(
            QWidget {
                background: #2d2d2d;
                border: 3px solid #1e3a53;
                border-radius: 3px;
            }
        )");
        m_container->setAttribute(Qt::WA_TranslucentBackground, false);

        m_label = new QLabel(m_container);
        m_label->setText("Drop QSS here");
        m_label->setStyleSheet("color: #aaa; background: transparent;");
        m_label->setAlignment(Qt::AlignCenter);
        m_label->setFixedSize(200, 50);
    }

    void updateLabel()
    {
        if (m_qssPath.isEmpty()) {
            m_label->setText("Drop QSS here");
        }
        else {
            QFileInfo info(m_qssPath);
            m_label->setText(QString("Ctrl+R | %1").arg(info.fileName()));
        }
    }

    bool m_dragging;
    QPoint m_dragPos;
    QString m_qssPath;
    QLabel* m_label;
    QWidget* m_container;
};

#endif // QSSDEBUGWIDGET_H