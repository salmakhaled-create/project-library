#include "checkoutpage.h"
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

CheckOutPage::CheckOutPage(QWidget *parent)
    : QWidget(parent)
{
    auto *layout = new QVBoxLayout(this);

    lineEdit = new QLineEdit(this);
    lineEdit->setPlaceholderText("Book title to check out");

    auto *btnCheckOut = new QPushButton("Check Out", this);
    auto *btnBack = new QPushButton("← Back", this);

    layout->addWidget(lineEdit);
    layout->addWidget(btnCheckOut);
    layout->addWidget(btnBack);

    connect(btnBack, &QPushButton::clicked,
            this, &CheckOutPage::backRequested);
    connect(btnCheckOut, &QPushButton::clicked,
            this, &CheckOutPage::checkOutBook);
}

void CheckOutPage::checkOutBook()
{
    qDebug() << "Checking out:" << lineEdit->text();

    QFile file("books.json");
    if (!file.open(QIODevice::ReadOnly))
        return;

    QJsonArray arr = QJsonDocument::fromJson(file.readAll()).array();
    file.close();

    bool changed = false;

    for (int i = 0; i < arr.size(); ++i) {
        QJsonObject obj = arr[i].toObject();

        if (obj["title"].toString() == lineEdit->text() &&
            obj["status"].toString() == "Available") {
            obj["status"] = "Checked Out";
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
