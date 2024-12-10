#ifndef COMMONPAGE_H
#define COMMONPAGE_H

#include <QWidget>
#include "musiclist.h"
namespace Ui {
class CommonPage;
}

enum PageType
{
    LIKE_PAGE,
    LOCAL_PAGE,
    HISTORY_PAGE
};

class CommonPage : public QWidget
{
    Q_OBJECT

public:
    explicit CommonPage(QWidget *parent = nullptr);
    ~CommonPage();
    void setMusicListType(PageType pageType);
    void setCommonPageUI(const QString &title,const QString &image);
    void addMusicToMusicPage(MusicList& musicList);
    void reFresh(MusicList& musicList);
private:
    Ui::CommonPage *ui;

    PageType pageType;
    QVector<QString> musicOfPage;
};

#endif // COMMONPAGE_H
