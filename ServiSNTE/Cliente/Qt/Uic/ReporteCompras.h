/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/ReporteCompras.ui'
**
** Created: Sat Jan 27 16:35:16 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REPORTECOMPRAS_H
#define REPORTECOMPRAS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QTable;
class QPushButton;
class QLCDNumber;

class ReporteCompras : public QWidget
{
    Q_OBJECT

public:
    ReporteCompras( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ReporteCompras();

    QLabel* textLabel1;
    QLineEdit* QLERangoFechas;
    QLabel* textLabel2;
    QTable* QTCompras;
    QPushButton* pushButton15;
    QPushButton* pushButton15_2;
    QLabel* textLabel2_2;
    QTable* QTDetalleCompras;
    QLabel* textLabel3;
    QLCDNumber* lCDNumber5;
    QLabel* textLabel3_2;
    QLCDNumber* lCDNumber5_2;
    QLabel* textLabel3_2_2;
    QLCDNumber* lCDNumber5_2_2;

protected:
    QGridLayout* ReporteComprasLayout;
    QSpacerItem* spacer2;
    QVBoxLayout* layout1;
    QVBoxLayout* layout41;
    QHBoxLayout* layout44;
    QHBoxLayout* layout49;
    QVBoxLayout* layout41_2;
    QVBoxLayout* layout48;
    QVBoxLayout* layout45;
    QVBoxLayout* layout45_2;
    QVBoxLayout* layout45_2_2;

protected slots:
    virtual void languageChange();

};

#endif // REPORTECOMPRAS_H
