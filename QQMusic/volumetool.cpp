#include "volumetool.h"
#include "ui_volumetool.h"
#include <QGraphicsDropShadowEffect>
#include <QPainter>

VolumeTool::VolumeTool(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::VolumeTool),
    isMuted(false),
    volumeRatio(20)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Popup|Qt::FramelessWindowHint|Qt::NoDropShadowWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    QGraphicsDropShadowEffect* shadowEffect=new QGraphicsDropShadowEffect(this);
    shadowEffect->setOffset(0,0);
    shadowEffect->setColor("#646464");
    shadowEffect->setBlurRadius(10);
    setGraphicsEffect(shadowEffect);
    ui->silenceBtn->setIcon(QIcon(":/images/volumn.png"));
    ui->outSlider->setGeometry(ui->outSlider->x(),180-36+25,ui->outSlider->width(),36);
    ui->sliderBtn->move(ui->sliderBtn->x(),ui->outSlider->y()-ui->sliderBtn->height()/2);
    ui->volumeRatio->setText("20%");
    connect(ui->silenceBtn, &QPushButton::clicked, this, &VolumeTool::onSilenceBtnClicked);
    ui->sliderBox->installEventFilter(this);
}

VolumeTool::~VolumeTool()
{
    delete ui;
}

void VolumeTool::paintEvent(QPaintEvent *event)
{
    (void)event;
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(Qt::white));
    QPolygon polygon;
    polygon.append(QPoint(30, 300));
    polygon.append(QPoint(70, 300));
    polygon.append(QPoint(50, 320));
    painter.drawPolygon(polygon);
}

void VolumeTool::onSilenceBtnClicked()
{
    isMuted=!isMuted;
    if(isMuted)
    {
        ui->silenceBtn->setIcon(QIcon(":/images/silent.png"));
    }
    else
    {
        ui->silenceBtn->setIcon(QIcon(":/images/volumn.png"));
    }
    emit setSilence(isMuted);
}

void VolumeTool::calcVolume()
{
    int height = ui->volumeWidget->mapFromGlobal(QCursor().pos()).y();
    height = height < 25? 25 : height;
    height = height > 205? 205 : height;
    ui->sliderBtn->move(ui->sliderBtn->x(), height-ui->sliderBtn->height()/2);
    ui->outSlider->setGeometry(ui->outSlider->x(), height, ui->outSlider->width(), 205 - height);
    volumeRatio = (int)((int)ui->outSlider->height()/(float)180*100);
    ui->volumeRatio->setText(QString::number(volumeRatio)+"%");
}

bool VolumeTool::eventFilter(QObject *watched, QEvent *event)
{
    if(watched==ui->sliderBox)
    {
        if(event->type()==QEvent::MouseButtonPress)
        {
            calcVolume();
        }
        else if(event->type()==QEvent::MouseMove)
        {
            calcVolume();
            emit setMusicVolume(volumeRatio);
        }
        else if(event->type()==QEvent::MouseButtonRelease)
        {
            emit setMusicVolume(volumeRatio);
        }
        return true;
    }
    return QObject::eventFilter(watched,event);
}
