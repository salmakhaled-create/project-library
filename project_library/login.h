#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

#include <QLineEdit>
#include <QPushButton>

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);

signals:
    void loginSuccess();

private:
    QLineEdit *username;
    QLineEdit *password;
};

#endif
