#include "displaypage.h"
#include <QVBoxLayout>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QPushButton>

DisplayPage::DisplayPage(QWidget *parent) : QWidget(parent)
{
    auto *mainLayout = new QVBoxLayout(this);

    // Top bar for navigation
    auto *topLayout = new QHBoxLayout();
    auto *btnBack = new QPushButton("← Back");
    connect(btnBack, &QPushButton::clicked, this, &DisplayPage::backRequested);

    btnBack->setFixedWidth(100);

    topLayout->addWidget(btnBack);
    topLayout->addStretch();

    mainLayout->addLayout(topLayout);


    table = new QTableWidget();
    table->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    mainLayout->addWidget(table);

    table->setColumnCount(3);
    table->setHorizontalHeaderLabels({"Title", "Author", "Status"});

    connect(btnBack, &QPushButton::clicked, this, &DisplayPage::backRequested);
}

void DisplayPage::loadData(const QString &type)
{
    QFile file("books.json");
    if (!file.open(QIODevice::ReadOnly)) return;

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    QJsonArray arr = doc.array();

    table->setRowCount(0);

    for (const auto &item : arr) {
        QJsonObject obj = item.toObject();
        if (type == "all" ||
            (type == "Available" && obj["status"] == "Available") ||
            (type == "Checked Out" && obj["status"] == "Checked Out"))
        {
            int row = table->rowCount();
            table->insertRow(row);

            table->setItem(row, 0, new QTableWidgetItem(obj["title"].toString()));
            table->setItem(row, 1, new QTableWidgetItem(obj["author"].toString()));
            table->setItem(row, 2, new QTableWidgetItem(obj["status"].toString()));
        }
    }
}




