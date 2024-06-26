/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/FijaFechaCompra.ui'
**
** Created: Thu Apr 11 21:05:33 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FIJAFECHACOMPRA_H
#define FIJAFECHACOMPRA_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlProveedoresSS;
class QLineEdit;
class QPushButton;

class FijaFechaCompra : public QWidget
{
    Q_OBJECT

public:
    FijaFechaCompra( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~FijaFechaCompra();

    QLabel* textLabel1;
    QCtrlProveedoresSS* QCtrProveedores;
    QLabel* textLabel3;
    QLineEdit* QLEFecha;
    QPushButton* QPBRegistraFecha;
    QPushButton* pushButton17;

protected:
    QGridLayout* FijaFechaCompraLayout;
    QVBoxLayout* layout1;
    QVBoxLayout* layout39;
    QHBoxLayout* layout45;

protected slots:
    virtual void languageChange();

};

#endif // FIJAFECHACOMPRA_H
