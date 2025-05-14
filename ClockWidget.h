#ifndef CLOCKWIDGET_H
#define CLOCKWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <QDateTime> // 用于获取系统时间的核心类

QT_BEGIN_NAMESPACE
namespace Ui { class ClockWidget; }
QT_END_NAMESPACE

class ClockWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ClockWidget(QWidget *parent = nullptr);
    ~ClockWidget();

private slots:
    // 定时更新时间的槽函数
    void updateTimeDisplay();

private:
    Ui::ClockWidget *ui;
    QTimer *timer; // 驱动时间更新的定时器
};

#endif
