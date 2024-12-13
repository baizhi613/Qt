#ifndef LRCPAGE_H
#define LRCPAGE_H

#include <QWidget>
#include <QPropertyAnimation>
struct LyricLine
{
    qint64 time;
    QString text;
    LyricLine(qint64 qtime,QString qtext)
        :time(qtime)
        ,text(qtext)
    {}
};

namespace Ui {
class LrcPage;
}

class LrcPage : public QWidget
{
    Q_OBJECT

public:
    explicit LrcPage(QWidget *parent = nullptr);
    ~LrcPage();
    bool parseLrc(const QString& lrcPath);
    int getLineLrcWordIndex(qint64 pos);
    QString getLineLrcWord(qint64 index);
    void showLrcWord(int time);
private:
    Ui::LrcPage *ui;
    QPropertyAnimation* lrcAnimation;
    QVector<LyricLine> lrcLines;
};

#endif // LRCPAGE_H
