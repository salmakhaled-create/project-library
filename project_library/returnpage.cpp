#include "returnpage.h"
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

ReturnPage::ReturnPage(QWidget *parent)
    : QWidget(parent)
{
    auto *layout = new QVBoxLayout(this);

    lineEdit = new QLineEdit(this);
    lineEdit->setPlaceholderText("Book title to return");

    auto *btnReturn = new QPushButton("Return Book", this);
    auto *btnBack = new QPushButton("← Back", this);

    layout->addWidget(lineEdit);
    layout->addWidget(btnReturn);
    layout->addWidget(btnBack);

    connect(btnBack, &QPushButton::clicked,
            this, &ReturnPage::backRequested);

    connect(btnReturn, &QPushButton::clicked,
            this, &ReturnPage::returnBook);
}

void ReturnPage::returnBook()
{
    qDebug() << "Returning book:" << lineEdit->text();

    QFile file("books.json");
    if (!file.open(QIODevice::ReadOnly))
        return;
    QJsonArray arr = QJsonDocument::fromJson(file.readAll()).array();
    file.close();

    bool changed = false;

    for (int i = 0; i < arr.size(); ++i) {
        QJsonObject obj = arr[i].toObject();
        if (obj["title"].toString() == lineEdit->text()
            && obj["status"].toString() == "Checked Out") {

            obj["status"] = "Available";
            arr[i] = obj;
            changed = true;
            break;
        }
    }

    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        file.write(QJsonDocument(arr).toJson());
        file.close();
    }

    lineEdit->clear();
    if (changed)
        emit bookStatusChanged();
}
