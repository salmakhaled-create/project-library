#include "login.h"
#include <QVBoxLayout>
#include <QLabel>

Login::Login(QWidget *parent) : QWidget(parent)
{
    auto *layout = new QVBoxLayout(this);

    layout->addWidget(new QLabel("Sign In"));

    username = new QLineEdit();
    username->setPlaceholderText("Username");
    layout->addWidget(username);

    password = new QLineEdit();
    password->setPlaceholderText("Password");
    password->setEchoMode(QLineEdit::Password);
    layout->addWidget(password);

    auto *btn = new QPushButton("Sign In");
    layout->addWidget(btn);

    connect(btn, &QPushButton::clicked, [=]() {
        if (username->text() == "admin" && password->text() == "1234") {
            emit loginSuccess();
        }
    });
}
