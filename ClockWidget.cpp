#include "ClockWidget.h"
#include "ui_ClockWidget.h"

ClockWidget::ClockWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ClockWidget)
    , timer(new QTimer(this))
{
    ui->setupUi(this);

    //定时器
    timer->setInterval(1000); // 设置1秒间隔
    connect(timer, &QTimer::timeout, this, &ClockWidget::updateTimeDisplay);
    timer->start(); // 立即启动定时器

    // 初始显示（避免首次更新前的空白）
    updateTimeDisplay();

    // --- 可选样式增强 ---
    //this->setStyleSheet("background: #F5F6FA; border-radius: 8px;");这是什么？
}

ClockWidget::~ClockWidget()
{
    delete ui;
}

// 时间读取核心代码
void ClockWidget::updateTimeDisplay()
{

    const QDateTime current = QDateTime::currentDateTime();
    ui->timeLabel->setText(current.toString("HH:mm:ss"));
    ui->dataLabel->setText(current.toString("yyyy-MM-dd"));
}
