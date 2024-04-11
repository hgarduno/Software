/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/ConsultaVentas.ui'
**
** Created: Thu Apr 11 21:05:33 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CONSULTAVENTAS_H
#define CONSULTAVENTAS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;
class QTextEdit;
class QTable;

class ConsultaVentas : public QWidget
{
    Q_OBJECT

public:
    ConsultaVentas( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ConsultaVentas();

    QLabel* textLabel1;
    QLineEdit* QLERFC;
    QLabel* textLabel1_2;
    QLineEdit* QLEFolio;
    QPushButton* QPBConsultaVentas;
    QLabel* textLabel2;
    QTextEdit* QTEDatosCliente;
    QLabel* textLabel4;
    QTable* QTDetalleVenta;
    QLabel* textLabel3;
    QTable* QTVentas;

protected:
    QGridLayout* ConsultaVentasLayout;
    QHBoxLayout* layout3;
    QVBoxLayout* layout1;
    QVBoxLayout* layout1_2;
    QHBoxLayout* layout4;
    QVBoxLayout* layout5;
    QVBoxLayout* layout7;
    QVBoxLayout* layout6;

protected slots:
    virtual void languageChange();

};

#endif // CONSULTAVENTAS_H
