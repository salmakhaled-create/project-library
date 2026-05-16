#ifndef MENUPAGE_H
#define MENUPAGE_H

#include <QWidget>

class QPushButton;

class MenuPage : public QWidget
{
    Q_OBJECT

public:
    explicit MenuPage(QWidget *parent = nullptr);

signals:
    void showAllBooks();
    void addBooks();
    void checkOutBook();
    void returnBook();


private:
    // any private members
};

#endif // MENUPAGE_H
