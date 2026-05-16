#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Library System");

    stack = new QStackedWidget(this);
    setCentralWidget(stack);

    login = new Login();
    menuPage = new MenuPage();
    displayPage = new DisplayPage();
    addBooksPage = new AddBooksPage();
    checkOutPage = new CheckOutPage();
    returnPage   = new ReturnPage();

    stack->addWidget(login);
    stack->addWidget(menuPage);
    stack->addWidget(displayPage);
    stack->addWidget(addBooksPage);
    stack->addWidget(checkOutPage);
    stack->addWidget(returnPage);

    connect(login, &Login::loginSuccess, this, &MainWindow::handleLoginSuccess);
    connect(menuPage, &MenuPage::showAllBooks, this, &MainWindow::openAllBooks);
    connect(menuPage, &MenuPage::addBooks, this, &MainWindow::openAddBook);

    connect(menuPage, &MenuPage::checkOutBook, this, [=](){ stack->setCurrentIndex(4); });
    connect(menuPage, &MenuPage::returnBook,   this, [=](){ stack->setCurrentIndex(5); });

    connect(displayPage, &DisplayPage::backRequested, this, [=](){ stack->setCurrentIndex(1); });
    connect(addBooksPage, &AddBooksPage::backRequested, this, [=](){ stack->setCurrentIndex(1); });
    connect(checkOutPage, &CheckOutPage::backRequested, this, [=](){ stack->setCurrentIndex(1); });
    connect(returnPage, &ReturnPage::backRequested, this, [=](){ stack->setCurrentIndex(1); });

    connect(checkOutPage, &CheckOutPage::bookStatusChanged, displayPage, [=]() {
        displayPage->loadData("Available");
    });
    connect(returnPage, &ReturnPage::bookStatusChanged, displayPage, [=](){
        displayPage->loadData("Available");
    });
    connect(checkOutPage, &CheckOutPage::bookStatusChanged, this, [=](){
        displayPage->loadData("all");
        stack->setCurrentWidget(displayPage);
    });
    connect(returnPage, &ReturnPage::bookStatusChanged, this, [=](){
        displayPage->loadData("all");
        stack->setCurrentWidget(displayPage);
    });

}

MainWindow::~MainWindow()
{delete ui;}
void MainWindow::handleLoginSuccess()
{stack->setCurrentIndex(1);}
void MainWindow::openAllBooks()
{displayPage->loadData("all");
    stack->setCurrentIndex(2);}
void MainWindow::openAddBook()
{stack->setCurrentIndex(3);}

