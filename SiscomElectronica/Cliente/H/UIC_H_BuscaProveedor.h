/****************************************************************************
** Form interface generated from reading ui file 'UI/BuscaProveedor.ui'
**
** Created: Wed Jan 31 10:48:05 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef BUSCAPROVEEDOR_H
#define BUSCAPROVEEDOR_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QComboBox;
class QLineEdit;
class QTextEdit;
class QPushButton;

class BuscaProveedor : public QDialog
{
    Q_OBJECT

public:
    BuscaProveedor( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~BuscaProveedor();

    QLabel* textLabel1;
    QComboBox* QCBRSocial;
    QLabel* textLabel2;
    QLineEdit* lineEdit15;
    QLabel* textLabel2_2;
    QLineEdit* lineEdit15_2;
    QLabel* textLabel3;
    QTextEdit* QTEDireccion;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* BuscaProveedorLayout;
    QVBoxLayout* layout36;
    QVBoxLayout* layout41;
    QHBoxLayout* layout40;
    QVBoxLayout* layout37;
    QVBoxLayout* layout37_2;
    QVBoxLayout* layout38;

protected slots:
    virtual void languageChange();

};

#endif // BUSCAPROVEEDOR_H
