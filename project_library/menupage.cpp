#include "menupage.h"
#include <QVBoxLayout>
#include <QPushButton>
MenuPage::MenuPage(QWidget *parent) : QWidget(parent)
{
    auto *layout = new QVBoxLayout(this);

    auto *btnAll = new QPushButton("All Books");
    auto *btnAdd = new QPushButton("Add Book");
    auto *btnCheckOut = new QPushButton("Check Out Book");
    auto *btnReturn   = new QPushButton("Return Book");

    layout->addWidget(btnAll);
    layout->addWidget(btnAdd);
    layout->addWidget(btnCheckOut);
    layout->addWidget(btnReturn);

    connect(btnAll, &QPushButton::clicked, this, &MenuPage::showAllBooks);
    connect(btnAdd, &QPushButton::clicked, this, &MenuPage::addBooks);
    connect(btnCheckOut, &QPushButton::clicked, this, &MenuPage::checkOutBook);
    connect(btnReturn, &QPushButton::clicked, this, &MenuPage::returnBook);

}
