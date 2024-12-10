#ifndef RECBOXITEM_H
#define RECBOXITEM_H

#include <QWidget>

namespace Ui {
class RecBoxItem;
}

class RecBoxItem : public QWidget
{
    Q_OBJECT

public:
    explicit RecBoxItem(QWidget *parent = nullptr);
    ~RecBoxItem();
    void setRecText(const QString& text);
    void setRecImage(const QString& imagePath);
    bool eventFilter(QObject *watched, QEvent *event);
private:
    Ui::RecBoxItem *ui;
};

#endif // RECBOXITEM_H
