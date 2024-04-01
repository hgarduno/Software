/****************************************************************************
** Form interface generated from reading ui file 'UI/ClienteAlumno.ui'
**
** Created: Wed Jan 31 10:48:06 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CLIENTEALUMNO_H
#define CLIENTEALUMNO_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QLineEdit;
class QButtonGroup;
class QRadioButton;
class QCtrlEscuelasSE;
class QCtrlClientesMayoreo;
class QTextEdit;
class QCtrlOrdenesFavoritas;

class ClienteAlumno : public QDialog
{
    Q_OBJECT

public:
    ClienteAlumno( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~ClienteAlumno();

    QPushButton* QPBOtrosMovimientos;
    QPushButton* QPBAceptar;
    QPushButton* QPBNuevaOrden;
    QPushButton* QPBCancelar;
    QLabel* textLabel1_2;
    QLineEdit* QLECliente;
    QLabel* textLabel1_2_2;
    QLineEdit* QLEEscuela;
    QButtonGroup* QBGTipoOrden;
    QRadioButton* QRBApartado;
    QRadioButton* QRBCotizacion;
    QRadioButton* radioButton5;
    QRadioButton* radioButton12;
    QRadioButton* QPBOrdenActual;
    QRadioButton* QRBCierraApartado;
    QRadioButton* radioButton4;
    QRadioButton* radioButton7;
    QRadioButton* radioButton8;
    QRadioButton* radioButton8_2;
    QRadioButton* radioButton10;
    QRadioButton* radioButton11;
    QRadioButton* radioButton13;
    QLabel* textLabel1;
    QCtrlEscuelasSE* QCtrEscuelas;
    QLabel* textLabel1_3;
    QCtrlClientesMayoreo* QCtrClientesMayoreo;
    QLabel* textLabel1_4;
    QTextEdit* QTEDesVenta;
    QCtrlOrdenesFavoritas* QCtrOrdenesFavoritas;

protected:
    QGridLayout* ClienteAlumnoLayout;
    QHBoxLayout* layout8;
    QHBoxLayout* layout5;
    QVBoxLayout* layout3;
    QVBoxLayout* layout3_2;
    QGridLayout* QBGTipoOrdenLayout;
    QHBoxLayout* layout41;
    QVBoxLayout* layout40;
    QVBoxLayout* layout1;
    QVBoxLayout* layout8_2;
    QVBoxLayout* layout11;

protected slots:
    virtual void languageChange();

};

#endif // CLIENTEALUMNO_H
