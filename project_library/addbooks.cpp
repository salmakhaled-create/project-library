#include "addbooks.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

AddBooksPage::AddBooksPage(QWidget *parent)
    : QWidget(parent)
{
    auto *layout = new QVBoxLayout(this);

    title = new QLineEdit(this);
    author = new QLineEdit(this);

    title->setPlaceholderText("Book Title");
    author->setPlaceholderText("Author");
    auto *btnAdd = new QPushButton("Add Book", this);
    auto *btnBack = new QPushButton("← Back", this);

    layout->addWidget(title);
    layout->addWidget(author);
    layout->addWidget(btnAdd);
    layout->addWidget(btnBack);

    connect(btnBack, &QPushButton::clicked,
            this, &AddBooksPage::backRequested);

    connect(btnAdd, &QPushButton::clicked, this, [this]() {

        QFile file("books.json");
        QJsonArray arr;

        if (file.exists() && file.open(QIODevice::ReadOnly)) {
            arr = QJsonDocument::fromJson(file.readAll()).array();
            file.close();
        }

        QJsonObject obj;
        obj["title"] = title->text();
        obj["author"] = author->text();
        obj["status"] = "Available";

        arr.append(obj);

        if (file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
            file.write(QJsonDocument(arr).toJson());
            file.close();
        }

        title->clear();
        author->clear();

        emit bookAdded();
    });
}

