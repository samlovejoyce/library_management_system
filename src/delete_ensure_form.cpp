#include "delete_ensure_form.h"
#include "ui_delete_ensure_form.h"
#include <QMessageBox>


DeleteEnsureForm::DeleteEnsureForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeleteEnsureForm)
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromLocal8Bit("删除确认界面"));
}


DeleteEnsureForm::~DeleteEnsureForm()
{
    delete ui;
}


void DeleteEnsureForm::on_yes_btn_clicked()
{
    QMessageBox::information(this, QString::fromLocal8Bit("信息"), QString::fromLocal8Bit("删除信息成功！"));
    this->close();
}


void DeleteEnsureForm::on_no_btn_clicked()
{
    this->close();
}
