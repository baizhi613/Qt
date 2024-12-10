#ifndef RECBOX_H
#define RECBOX_H

#include <QWidget>
#include <QJsonArray>

namespace Ui {
class RecBox;
}

class RecBox : public QWidget
{
    Q_OBJECT

public:
    explicit RecBox(QWidget *parent = nullptr);
    ~RecBox();
    void initRecBoxUi(QJsonArray data,int row);
private slots:
    void on_btDown_clicked();

    void on_btUp_clicked();

private:
    void createRecBoxItem();
private:
    Ui::RecBox *ui;
    int row;
    int col;
    int currentIndex;
    int count;
    QJsonArray imageList;
};

#endif // RECBOX_H
