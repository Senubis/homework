#include "TimerWidget.h"
#include "ui_TimerWidget.h" // 必须包含生成的UI头文件
#include <QApplication>     // 用于beep()呃什么时候能用自己的音效

TimerWidget::TimerWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TimerWidget)
    , timer(new QTimer(this))
{
    ui->setupUi(this); // 关键初始化

    // 连接定时器
    connect(timer, &QTimer::timeout, this, &TimerWidget::updateDisplay);

    // 初始状态设置
    updateDisplay();
    ui->pauseButton->setEnabled(false); // 初始化禁用暂停按钮
}

TimerWidget::~TimerWidget()
{
    delete ui;
}

// 定时器更新
void TimerWidget::updateDisplay()
{
    if (isRunning) {
        if (--remainingSeconds <= 0) {
            timer->stop();
            isRunning = false;
            remainingSeconds = 0;
            QApplication::beep(); // 提示音
            ui->startButton->setText("开始");
        }
    }

    // 更新显示
    int minutes = remainingSeconds / 60;
    int seconds = remainingSeconds % 60;//时间运算
    ui->lcdDisplay->display(
        QString("%1:%2")
            .arg(minutes, 2, 10, QLatin1Char('0'))
            .arg(seconds, 2, 10, QLatin1Char('0'))
        );
}


// 开始/暂停按钮
void TimerWidget::startButton_clicked()
{
    if (!isRunning) {
        timer->start(1000);
        isRunning = true;
        ui->startButton->setText("暂停");
        ui->pauseButton->setEnabled(true); // 启用暂停按钮
    } else {
        timer->stop();
        isRunning = false;
        ui->startButton->setText("继续");
        ui->pauseButton->setEnabled(false);
    }
}

// 暂停按钮（这个，不需要了；TMD为什么已经怼到startButton上了但是删了会报错？）
void TimerWidget::pauseButton_clicked()
{
    // ds告诉我此槽函数保留以匹配UI连接，但实际功能已合并到startButton
}

// 重置按钮
void TimerWidget::resetButton_clicked()
{
    timer->stop();
    remainingSeconds = 25 * 60;
    isRunning = false;
    ui->startButton->setText("开始");
    ui->pauseButton->setEnabled(false);
    updateDisplay();
}

