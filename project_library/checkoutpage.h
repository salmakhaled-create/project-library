#ifndef CHECKOUTPAGE_H
#define CHECKOUTPAGE_H

#include <QWidget>

class QLineEdit;
class QPushButton;

class CheckOutPage : public QWidget
{
    Q_OBJECT
public:
    explicit CheckOutPage(QWidget *parent = nullptr);

signals:
    void backRequested();
    void bookStatusChanged();

private slots:
    void checkOutBook();

private:
    QLineEdit *lineEdit;
};

#endif // CHECKOUTPAGE_H
