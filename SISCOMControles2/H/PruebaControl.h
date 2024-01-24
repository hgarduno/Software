#ifndef __PRUEBACONTROL_H__
#define __PRUEBACONTROL_H__

#include <qwidget.h>
#include <qwidgetplugin.h>

class QLineEdit;
class QPushButton;

class QT_WIDGET_PLUGIN_EXPORT PruebaControl : public QWidget
{
    Q_OBJECT

    Q_ENUMS( Mode )
    Q_PROPERTY( Mode mode READ mode WRITE setMode )
    Q_PROPERTY( QString fileName READ fileName WRITE setFileName )

public:
    PruebaControl( QWidget *parent = 0, const char *name = 0);

    enum Mode { File, Directory };

    QString fileName() const;
    Mode mode() const;

public slots:
    void setFileName( const QString &fn );
    void setMode( Mode m );

signals:
    void fileNameChanged( const QString & );

private slots:
    void chooseFile();

private:
    QLineEdit *lineEdit;
    QPushButton *button;
    QPushButton *QPOtro;
    QPushButton *QPOtro1;
    Mode md;

};

#endif
