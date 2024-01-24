/****************************************************************************
** Form interface generated from reading ui file 'UI/CambiaEliminaClaveProducto.ui'
**
** Created: Thu Dec 21 12:53:39 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAMBIAELIMINACLAVEPRODUCTO_H
#define CAMBIAELIMINACLAVEPRODUCTO_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlProdSiscomElectronica;
class QTextEdit;
class QLineEdit;
class QPushButton;

class CambiaEliminaClaveProducto : public QDialog
{
    Q_OBJECT

public:
    CambiaEliminaClaveProducto( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CambiaEliminaClaveProducto();

    QLabel* textLabel1;
    QCtrlProdSiscomElectronica* QCtrProdSiscom;
    QLabel* textLabel4_2;
    QTextEdit* QTEDescripcion;
    QLabel* textLabel2;
    QLineEdit* QLECveNueva;
    QPushButton* QPBCClave;
    QPushButton* QPBEProducto;
    QPushButton* QPBAnexar_2_2;

protected:
    QGridLayout* CambiaEliminaClaveProductoLayout;
    QVBoxLayout* layout53;
    QVBoxLayout* layout51;
    QVBoxLayout* layout49;
    QVBoxLayout* layout85;
    QVBoxLayout* layout52;
    QHBoxLayout* layout54;

protected slots:
    virtual void languageChange();

};

#endif // CAMBIAELIMINACLAVEPRODUCTO_H
