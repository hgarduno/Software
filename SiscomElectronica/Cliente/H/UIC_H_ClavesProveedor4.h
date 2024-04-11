/****************************************************************************
** Form interface generated from reading ui file 'UI/ClavesProveedor4.ui'
**
** Created: Wed Apr 10 20:52:31 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CLAVESPROVEEDOR4_H
#define CLAVESPROVEEDOR4_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class QPushButton;
class QCtrlProveedoresSE;
class QCtrlProductosSE;
class QLineEdit;
class QTextEdit;

class ClavesProveedor4 : public QWidget
{
    Q_OBJECT

public:
    ClavesProveedor4( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ClavesProveedor4();

    QLabel* textLabel4;
    QTable* QTClaves;
    QPushButton* QPBAnexar;
    QPushButton* QPBActualizar;
    QPushButton* QPBRegistra;
    QLabel* textLabel1;
    QCtrlProveedoresSE* QCtrProveedores;
    QLabel* textLabel2;
    QCtrlProductosSE* QCtrProductos;
    QLabel* textLabel3;
    QLineEdit* QLEClaveP;
    QLabel* textLabel5;
    QTextEdit* QTEDescripcionS;
    QLabel* textLabel5_2;
    QTextEdit* QTEDescripcionP;

protected:
    QGridLayout* ClavesProveedor4Layout;
    QVBoxLayout* layout12;
    QHBoxLayout* layout37;
    QHBoxLayout* layout13;
    QVBoxLayout* layout13_2;
    QVBoxLayout* layout9;
    QVBoxLayout* layout12_2;
    QVBoxLayout* layout11;
    QHBoxLayout* layout15;
    QVBoxLayout* layout13_3;
    QVBoxLayout* layout13_2_2;

protected slots:
    virtual void languageChange();

};

#endif // CLAVESPROVEEDOR4_H
