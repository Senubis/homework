#ifndef TIMERWIDGET_H
#define TIMERWIDGET_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class TimerWidget;
}

class TimerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TimerWidget(QWidget *parent = nullptr);
    ~TimerWidget();

private slots:

    void startButton_clicked();
    void pauseButton_clicked();
    void resetButton_clicked();

private:
    Ui::TimerWidget *ui;
    QTimer *timer;
    int remainingSeconds = 25 * 60; // 25分钟
    bool isRunning = false;

    void updateDisplay();
};

#endif
