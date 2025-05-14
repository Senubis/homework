#include "NoteWidget.h"
#include "ui_NoteWidget.h"

NoteWidget::NoteWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NoteWidget)
{
    ui->setupUi(this);

    // 连接按钮槽
    connect(ui->saveButton, &QPushButton::clicked, this, &NoteWidget::onSaveClicked);
    connect(ui->clearButton, &QPushButton::clicked, this, &NoteWidget::onClearClicked);

    // 启动加载记忆
    loadNotes();
}

NoteWidget::~NoteWidget()
{
    delete ui;
}

// 加载保存的笔记
void NoteWidget::loadNotes()
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    QTextStream in(&file);
    ui->textEdit->setPlainText(in.readAll());
    file.close();
}

// 保存
void NoteWidget::onSaveClicked()
{
    saveNotesToFile();
    QMessageBox::information(this, "保存成功", "笔记已保存到文件！");
}

// 清空
void NoteWidget::onClearClicked()
{
    ui->textEdit->clear();
}

// 实际保存
void NoteWidget::saveNotesToFile()
{
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "错误", "无法保存文件！");
        return;
    }

    QTextStream out(&file);
    out << ui->textEdit->toPlainText();
    file.close();
}
