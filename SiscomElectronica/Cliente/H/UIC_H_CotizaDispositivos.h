/****************************************************************************
** Form interface generated from reading ui file 'UI/CotizaDispositivos.ui'
**
** Created: Fri Apr 12 21:34:49 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef COTIZADISPOSITIVOS_H
#define COTIZADISPOSITIVOS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QComboBox;
class QPushButton;
class QTextEdit;
class QLCDNumber;

class CotizaDispositivos : public QWidget
{
    Q_OBJECT

public:
    CotizaDispositivos( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~CotizaDispositivos();

    QLabel* textLabel1;
    QLineEdit* QLECantidad;
    QLabel* textLabel2;
    QComboBox* QCBProductos;
    QPushButton* QPBAnexarOrden;
    QPushButton* QPBPDescripcion;
    QPushButton* pushButton22;
    QLabel* textLabel1_2;
    QTextEdit* QLEDescripcion;
    QLabel* textLabel1_3;
    QLineEdit* QLEPrcVenta;
    QLabel* textLabel1_3_2;
    QLineEdit* QLEExistencia;
    QLabel* textLabel1_3_2_2;
    QLineEdit* QLEExistBodega;
    QLCDNumber* QLCNTotal;

protected:
    QGridLayout* CotizaDispositivosLayout;
    QHBoxLayout* layout13;
    QVBoxLayout* layout8;
    QVBoxLayout* layout9;
    QHBoxLayout* layout99;
    QVBoxLayout* layout10;
    QHBoxLayout* layout19;
    QVBoxLayout* layout18;
    QVBoxLayout* layout8_3;
    QHBoxLayout* layout17;
    QVBoxLayout* layout8_3_2;
    QVBoxLayout* layout8_3_2_2;

protected slots:
    virtual void languageChange();

};

#endif // COTIZADISPOSITIVOS_H
