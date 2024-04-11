/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/BeneficiosIntegrales.ui'
**
** Created: Sat Jan 27 16:35:16 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef BENEFICIOSINTEGRALES_H
#define BENEFICIOSINTEGRALES_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QTextEdit;
class QPushButton;

class BeneficiosIntegrales : public QWidget
{
    Q_OBJECT

public:
    BeneficiosIntegrales( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~BeneficiosIntegrales();

    QLabel* textLabel1;
    QLineEdit* QLEArriba;
    QLabel* textLabel1_2;
    QLineEdit* QLEIzquierda;
    QLabel* textLabel1_3;
    QLineEdit* QLEAbajo;
    QLabel* textLabel1_2_2;
    QLineEdit* QLEDerecha;
    QTextEdit* QTEFormato;
    QPushButton* QPBSelCredito;
    QPushButton* QPBCreditos;
    QPushButton* QPBGeneralesContrato;
    QPushButton* QPBGenerales;
    QPushButton* QPBComunicacion;
    QPushButton* QPBCapDirParticular;
    QPushButton* QPBCapDatEmpleo;
    QPushButton* QPBCapDatComplementarios;
    QPushButton* QPBCapDatCentroTrabajo;
    QPushButton* QPBPosBeneficios;
    QPushButton* QPBImprimir;
    QPushButton* QPBImprimeAArchivo;
    QPushButton* QPBImprimeFrente;
    QPushButton* QPBImprimeAtras;

protected:
    QGridLayout* BeneficiosIntegralesLayout;
    QHBoxLayout* layout19;
    QHBoxLayout* layout15;
    QVBoxLayout* layout13;
    QVBoxLayout* layout13_2;
    QHBoxLayout* layout15_2;
    QVBoxLayout* layout13_3;
    QVBoxLayout* layout13_2_2;
    QHBoxLayout* layout63;
    QHBoxLayout* layout62;
    QVBoxLayout* layout61;
    QVBoxLayout* layout12;
    QHBoxLayout* layout11;
    QHBoxLayout* layout9;

protected slots:
    virtual void languageChange();

};

#endif // BENEFICIOSINTEGRALES_H
