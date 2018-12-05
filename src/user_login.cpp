﻿#include "user_login.h"
#include "ui_user_login.h"
#include "user_register_form.h"
#include "connect_database.h"

#include <QMessageBox>
#include <QDesktopWidget>
#include <QSqlQuery>


UserLogin::UserLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserLogin)
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromLocal8Bit("用户登录界面"));

    admin_counter = 0;
    reader_counter = 0;
    counter = 0;
}


UserLogin::~UserLogin()
{
    delete ui;
}


void UserLogin::on_login_btn_clicked()
{
    bool flag = false;
    QString user_account;
    QString user_pwd;
    QString user_type;

    user_account = ui->acnt_le->text();
    user_pwd  = ui->pwd_le->text();
    user_type = ui->type_cbx->currentText();

    QSqlQuery query;

    if (!ConnectDatabase::openDatabase())
    {
        QMessageBox::warning(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("打开数据库失败!"));
        return ;
    }
    else
    {
        if (user_type == QString::fromLocal8Bit("管理员"))
        {
            query.exec("select * from admin");
            while (query.next())
            {
                if (query.value(0).toString() == user_account)
                    if (query.value(3).toString() == user_pwd)
                    {
                        if (admin_counter < 1)
                        {
                            AdminForm  *admin = new AdminForm();
                            flag = true;
                            admin->show();
                            admin->move((QApplication::desktop()->width() -
                                         admin->width()) / 2,
                                        (QApplication::desktop()->height() -
                                         admin->height()) / 2);
    //                        this->hide();
                              admin_counter++;
                              counter++;
                              if (counter == 2)
                                  this->close();
                        }
                        else
                        {
                            QMessageBox::warning(this, QString::fromLocal8Bit("警告"),
                                                 QString::fromLocal8Bit("不能有两个管理员同时在线！"));
                            return ;
                        }
                    }
            }
        }
        else if (user_type == QString::fromLocal8Bit("读者"))
        {
            query.exec("select * from reader");
            while (query.next())
            {
                if (query.value(0).toString() == user_account)
                    if (query.value(2).toString() == user_pwd)
                    {
                        if (reader_counter < 1)
                        {
                            ReaderForm *reader = new ReaderForm();
                            flag = true;
                            reader->show();
                            reader->move((QApplication::desktop()->width() -
                                          reader->width()) / 2,
                                         (QApplication::desktop()->height() -
                                          reader->height()) / 2);
    //                        this->hide();
                            reader_counter++;
                            counter++;
                            if (counter == 2)
                                this->close();
                        }
                        else
                        {
                            QMessageBox::warning(this, QString::fromLocal8Bit("警告"),
                                                 QString::fromLocal8Bit("不能有两个读者同时在线！"));
                            return ;
                        }
                    }
            }
        }
        if (!flag)
            QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("用户名或密码错误!"));
    }
}


void UserLogin::on_quit_btn_clicked()
{
    this->close();
}


void UserLogin::on_reg_btn_clicked()
{
    UserRegisterForm *user_register = new UserRegisterForm();
    user_register->show();
    user_register->move((QApplication::desktop()->width() -
                         user_register->width()) / 2,
                        (QApplication::desktop()->height() -
                         user_register->height()) / 2);
}
