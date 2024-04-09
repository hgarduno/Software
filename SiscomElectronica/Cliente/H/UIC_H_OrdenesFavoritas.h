/****************************************************************************
** Form interface generated from reading ui file 'UI/OrdenesFavoritas.ui'
**
** Created: lun abr 1 18:57:48 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef ORDENESFAVORITAS_H
#define ORDENESFAVORITAS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class QTextEdit;
class QLCDNumber;
class QPushButton;
class QCtrlOrdenesFavoritas;

class OrdenesFavoritas : public QWidget
{
    Q_OBJECT

public:
    OrdenesFavoritas( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~OrdenesFavoritas();

    QLabel* textLabel1;
    QTable* QTProductos;
    QLabel* textLabel1_4;
    QTextEdit* QTEDesVenta;
    QLabel* textLabel5_2;
    QLCDNumber* QLCDNImporte;
    QPushButton* QPBSelOrden;
    QPushButton* QPBAsignaOrdenFavorita;
    QPushButton* QPBAgregarOrdenFavorita;
    QPushButton* QPBEliminaOrden;
    QPushButton* QPBRegistraFavoritas;
    QCtrlOrdenesFavoritas* QCtrOrdenesFavoritas;

protected:
    QGridLayout* OrdenesFavoritasLayout;
    QVBoxLayout* layout61;
    QHBoxLayout* layout6;
    QVBoxLayout* layout11;
    QVBoxLayout* layout12_2;
    QHBoxLayout* layout24;

protected slots:
    virtual void languageChange();

};

#endif // ORDENESFAVORITAS_H
