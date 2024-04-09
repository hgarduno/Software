/****************************************************************************
** Form interface generated from reading ui file 'UI/DatosFacturacion.ui'
**
** Created: lun abr 1 18:57:47 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DATOSFACTURACION_H
#define DATOSFACTURACION_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;
class QTable;
class QCtrlFormaPagoSat;
class QCtrlMetodoPagoSat;
class QCtrlUsoCFDISat;
class QCtrlRFCs;
class QCtrlRegimenFiscal;

class DatosFacturacion : public QDialog
{
    Q_OBJECT

public:
    DatosFacturacion( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~DatosFacturacion();

    QLabel* textLabel6_2_2;
    QLineEdit* QLENombre;
    QLabel* textLabel6_2_2_2;
    QLineEdit* QLEAPaterno;
    QLabel* textLabel6_2_2_2_2;
    QLineEdit* QLEAMaterno;
    QLabel* textLabel6_3;
    QLineEdit* QLECalle;
    QLabel* textLabel6_3_2;
    QLineEdit* QLENumero;
    QLabel* textLabel6_3_2_2;
    QLineEdit* QLENumeroInt;
    QLabel* textLabel6_3_3_2;
    QLineEdit* QLEColonia;
    QLabel* textLabel6_3_3_2_2;
    QLineEdit* QLECP;
    QLabel* textLabel6_3_3;
    QLineEdit* QLEDelegacion;
    QLabel* textLabel6_3_3_2_2_3;
    QLineEdit* QLEEstado;
    QLabel* textLabel6_3_3_2_2_2;
    QLineEdit* QLECorreo;
    QLabel* textLabel6_3_3_2_2_2_2;
    QLineEdit* QLECorreoOtraVez;
    QLabel* textLabel6_3_3_2_2_2_2_2;
    QLineEdit* QLETelefono;
    QPushButton* QPBAgregarCorreo;
    QPushButton* QPBRegistrar;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;
    QLabel* textLabel1;
    QTable* QTCorreos;
    QLabel* textLabel1_2;
    QCtrlFormaPagoSat* QCtrFormaPagoSat;
    QLineEdit* QLEFormaPago;
    QLabel* textLabel1_3;
    QCtrlMetodoPagoSat* QCtrMetodoPago;
    QLineEdit* QLEMetodoPago;
    QLabel* textLabel2;
    QCtrlUsoCFDISat* QCtrUsoCFDI;
    QLineEdit* QLEUsoFactura;
    QLabel* textLabel6;
    QCtrlRFCs* QCtrRFCs;
    QLabel* textLabel6_2;
    QLineEdit* QLERazonSocial;
    QLabel* textLabel1_4;
    QCtrlRegimenFiscal* QCtrRegimenFiscal;

protected:
    QGridLayout* DatosFacturacionLayout;
    QHBoxLayout* layout25;
    QVBoxLayout* layout19_2_2;
    QVBoxLayout* layout19_2_2_2;
    QVBoxLayout* layout19_2_2_2_2;
    QHBoxLayout* layout35;
    QVBoxLayout* layout19_3;
    QVBoxLayout* layout19_3_2;
    QVBoxLayout* layout19_3_2_2;
    QVBoxLayout* layout19_3_3_2;
    QVBoxLayout* layout19_3_3_2_2;
    QVBoxLayout* layout19_3_3;
    QVBoxLayout* layout19_3_3_2_2_3;
    QHBoxLayout* layout39;
    QVBoxLayout* layout19_3_3_2_2_2;
    QVBoxLayout* layout19_3_3_2_2_2_2;
    QVBoxLayout* layout19_3_3_2_2_2_2_2;
    QHBoxLayout* layout20;
    QHBoxLayout* layout32;
    QVBoxLayout* layout21;
    QVBoxLayout* layout31;
    QVBoxLayout* layout30;
    QVBoxLayout* layout29;
    QVBoxLayout* layout28;
    QVBoxLayout* layout27;
    QHBoxLayout* layout31_2;
    QVBoxLayout* layout22;
    QVBoxLayout* layout19_2;
    QVBoxLayout* layout29_2;

protected slots:
    virtual void languageChange();

};

#endif // DATOSFACTURACION_H
