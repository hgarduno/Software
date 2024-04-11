/****************************************************************************
** Form interface generated from reading ui file 'UI/RegistroPlaca.ui'
**
** Created: Wed Apr 10 20:52:31 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REGISTROPLACA_H
#define REGISTROPLACA_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QTable;
class QTextEdit;
class QComboBox;
class QLineEdit;
class QCtrlFechaHora;
class QLCDNumber;

class RegistroPlaca : public QDialog
{
    Q_OBJECT

public:
    RegistroPlaca( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~RegistroPlaca();

    QPushButton* QPBRegistraCelular;
    QPushButton* QPBRegistra;
    QPushButton* QPBImprimeComprobante;
    QPushButton* QPBCancelar;
    QPushButton* QPBAceptar;
    QPushButton* QPBRegistraPersonales;
    QLabel* textLabel2_5;
    QTable* QTDatos;
    QLabel* textLabel1;
    QTextEdit* QTEArchivo;
    QLabel* textLabel1_2;
    QTextEdit* QTEMemoria;
    QLabel* textLabel2_6;
    QComboBox* QCBProductos;
    QLabel* textLabel2;
    QLineEdit* QLENombre;
    QLabel* textLabel2_2;
    QLineEdit* QLEAPaterno;
    QLabel* textLabel2_3;
    QLineEdit* QLEAMaterno;
    QLabel* textLabel2_4;
    QLineEdit* QLECelular;
    QLabel* textLabel2_4_2;
    QLineEdit* QLEReCelular;
    QLabel* textLabel1_3;
    QCtrlFechaHora* QCtrFechaEntrega;
    QLabel* textLabel1_4;
    QLCDNumber* QLCDNNImpresos;
    QLabel* textLabel1_4_2;
    QLCDNumber* QLCDNNImpRegistrados;

protected:
    QGridLayout* RegistroPlacaLayout;
    QGridLayout* layout25;
    QVBoxLayout* layout42;
    QHBoxLayout* layout78;
    QHBoxLayout* layout17;
    QVBoxLayout* layout16;
    QVBoxLayout* layout16_2;
    QHBoxLayout* layout90;
    QVBoxLayout* layout82;
    QHBoxLayout* layout74;
    QVBoxLayout* layout24;
    QVBoxLayout* layout2;
    QVBoxLayout* layout2_2;
    QVBoxLayout* layout2_3;
    QHBoxLayout* layout80;
    QVBoxLayout* layout2_4;
    QVBoxLayout* layout13;
    QVBoxLayout* layout15;
    QHBoxLayout* layout89;
    QVBoxLayout* layout65;
    QVBoxLayout* layout65_2;

protected slots:
    virtual void languageChange();

};

#endif // REGISTROPLACA_H
