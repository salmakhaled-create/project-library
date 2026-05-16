#ifndef ADDBOOKS_H
#define ADDBOOKS_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

class AddBooksPage : public QWidget
{
    Q_OBJECT
public:
    explicit AddBooksPage(QWidget *parent = nullptr);

signals:
    void bookAdded();
    void backRequested();

private:
    QLineEdit *title;
    QLineEdit *author;
};

#endif
