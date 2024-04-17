/****************************************************************************
** Form interface generated from reading ui file 'UI/ClientePedido.ui'
**
** Created: Fri Apr 12 21:25:58 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CLIENTEPEDIDO_H
#define CLIENTEPEDIDO_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlEscuelasSE;
class QLineEdit;
class QPushButton;
class QTextEdit;
class QTable;

class ClientePedido : public QDialog
{
    Q_OBJECT

public:
    ClientePedido( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~ClientePedido();

    QLabel* textLabel1;
    QCtrlEscuelasSE* QCtrEscuelas;
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
    QLabel* textLabel2_3_2;
    QLineEdit* QLEEscuela;
    QLabel* textLabel5;
    QLineEdit* QLENumCliente;
    QPushButton* QPBPuntoEntrega;
    QPushButton* QPBDireccionCliente;
    QPushButton* QPBDireccionCliente_2;
    QLabel* textLabel2_5;
    QLineEdit* QLECalle;
    QLabel* textLabel2_5_2;
    QLineEdit* QLENumero;
    QLabel* textLabel2_5_2_2_3_2;
    QLineEdit* QLECP;
    QLabel* textLabel2_5_2_2_2;
    QLineEdit* QLEDelegacion;
    QLabel* textLabel2_5_2_2;
    QLineEdit* QLEColonia;
    QLabel* textLabel2_5_2_2_3;
    QLineEdit* QLEEstado;
    QLabel* textLabel1_3;
    QLabel* textLabel2_5_3;
    QLineEdit* QLECalle1;
    QLabel* textLabel2_5_3_2;
    QLineEdit* QLECalle2;
    QLabel* textLabel4;
    QTextEdit* QTEReferencias;
    QPushButton* QPBRegistraPersonales;
    QPushButton* QPBRegistraCelular;
    QPushButton* QPBRegistraCorreo;
    QPushButton* QPBRegistraDireccion;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;
    QLabel* textLabel2_6;
    QLineEdit* QLETarifa;
    QLabel* textLabel2_6_2;
    QLineEdit* QLEDiasEntrega;
    QLabel* textLabel1_4;
    QTable* table3;
    QLabel* textLabel1_2;
    QTable* QTDirecciones;

protected:
    QGridLayout* ClientePedidoLayout;
    QVBoxLayout* layout48;
    QHBoxLayout* layout45;
    QHBoxLayout* layout47;
    QHBoxLayout* layout44;
    QVBoxLayout* layout1;
    QHBoxLayout* layout28;
    QVBoxLayout* layout2;
    QVBoxLayout* layout2_2;
    QVBoxLayout* layout2_3;
    QHBoxLayout* layout46;
    QVBoxLayout* layout2_4;
    QVBoxLayout* layout2_4_2;
    QHBoxLayout* layout43;
    QVBoxLayout* layout2_3_2;
    QVBoxLayout* layout29;
    QHBoxLayout* layout42;
    QHBoxLayout* layout47_2;
    QVBoxLayout* layout36;
    QVBoxLayout* layout32;
    QHBoxLayout* layout69;
    QVBoxLayout* layout2_5;
    QVBoxLayout* layout2_5_2;
    QVBoxLayout* layout2_5_2_2_3_2;
    QHBoxLayout* layout23;
    QVBoxLayout* layout2_5_2_2_2;
    QVBoxLayout* layout2_5_2_2;
    QVBoxLayout* layout2_5_2_2_3;
    QVBoxLayout* layout35;
    QHBoxLayout* layout34;
    QVBoxLayout* layout2_5_3;
    QVBoxLayout* layout2_5_3_2;
    QVBoxLayout* layout25;
    QHBoxLayout* layout53;
    QVBoxLayout* layout44_2;
    QHBoxLayout* layout39;
    QVBoxLayout* layout37;
    QVBoxLayout* layout37_2;
    QVBoxLayout* layout41;
    QVBoxLayout* layout70;
    QHBoxLayout* layout49;

protected slots:
    virtual void languageChange();

};

#endif // CLIENTEPEDIDO_H
