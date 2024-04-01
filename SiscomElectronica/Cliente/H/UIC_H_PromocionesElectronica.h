/****************************************************************************
** Form interface generated from reading ui file 'UI/PromocionesElectronica.ui'
**
** Created: Wed Jan 31 10:48:06 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PROMOCIONESELECTRONICA_H
#define PROMOCIONESELECTRONICA_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class CQControlFecha;
class QTextEdit;
class QPushButton;

class PromocionesElectronica : public QWidget
{
    Q_OBJECT

public:
    PromocionesElectronica( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~PromocionesElectronica();

    QLabel* textLabel3;
    QLineEdit* QLENombre;
    QLabel* textLabel3_2;
    QLineEdit* QLEPuntosSiscom;
    QLabel* textLabel1;
    CQControlFecha* QCtrFechaIni;
    QLabel* textLabel1_2;
    CQControlFecha* QCtrFechaFin;
    QLabel* textLabel2;
    QTextEdit* QTEDescripcion;
    QPushButton* QPBRegistra;
    QPushButton* pushButton3_2;
    QPushButton* pushButton3_2_2;

protected:
    QHBoxLayout* PromocionesElectronicaLayout;
    QVBoxLayout* layout25;
    QHBoxLayout* layout24;
    QVBoxLayout* layout5;
    QVBoxLayout* layout5_2;
    QVBoxLayout* layout15;
    QVBoxLayout* layout15_2;
    QVBoxLayout* layout17;
    QHBoxLayout* layout19;

protected slots:
    virtual void languageChange();

};

#endif // PROMOCIONESELECTRONICA_H
