#ifndef DISPLAYPAGE_H
#define DISPLAYPAGE_H

#include <QWidget>
#include <QTableWidget>

class DisplayPage : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayPage(QWidget *parent = nullptr);

    void loadData(const QString &type);  // ← Must match exactly

signals:
    void backRequested();

private:
    QTableWidget *table;
};

#endif // DISPLAYPAGE_H
