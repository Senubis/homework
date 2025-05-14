#ifndef NOTEWIDGET_H
#define NOTEWIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QFile>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class NoteWidget; }
QT_END_NAMESPACE

class NoteWidget : public QWidget
{
    Q_OBJECT
public:
    explicit NoteWidget(QWidget *parent = nullptr);
    ~NoteWidget();

private slots:
    void onSaveClicked();  // 保存按钮点击
    void onClearClicked(); // 清空按钮点击

private:
    Ui::NoteWidget *ui;
    QString filePath = "notes.txt"; // 默认保存路径

    void loadNotes();       // 启动时加载已有笔记
    void saveNotesToFile(); // 实际保存到文件
};

#endif
