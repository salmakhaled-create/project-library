#ifndef RETURNPAGE_H
#define RETURNPAGE_H

#include <QWidget>

class QLineEdit;
class QPushButton;

class ReturnPage : public QWidget
{
    Q_OBJECT
public:
    explicit ReturnPage(QWidget *parent = nullptr);

signals:
    void backRequested();
    void bookStatusChanged();

private slots:
    void returnBook();

private:
    QLineEdit *lineEdit;
};

#endif // RETURNPAGE_H
