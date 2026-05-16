#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include <QStackedWidget>
#include "login.h"
#include "menupage.h"
#include "displaypage.h"
#include "addbooks.h"
#include "checkoutpage.h"
#include "returnpage.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void handleLoginSuccess();
    void openAllBooks();
    void openAddBook();



private:
    Ui::MainWindow *ui;

    QStackedWidget *stack;
    Login *login;
    MenuPage *menuPage;
    DisplayPage *displayPage;
    AddBooksPage *addBooksPage;
    CheckOutPage *checkOutPage;
    ReturnPage *returnPage;

};

#endif // MAINWINDOW_H
