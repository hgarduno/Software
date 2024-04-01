/****************************************************************************
** Form interface generated from reading ui file 'UI/Ordenes.ui'
**
** Created: Wed Jan 31 10:48:05 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef ORDENES_H
#define ORDENES_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class QPushButton;

class Ordenes : public QWidget
{
    Q_OBJECT

public:
    Ordenes( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~Ordenes();

    QLabel* textLabel9;
    QTable* QTOrdenes;
    QLabel* textLabel9_2;
    QTable* QTDetalleOrden;
    QPushButton* QPBRangoFechas;
    QPushButton* QPBAContabilidad;
    QPushButton* QPBCopiar_2;
    QPushButton* QPBCopiar;

protected:
    QGridLayout* OrdenesLayout;
    QVBoxLayout* layout77;
    QVBoxLayout* layout77_2;
    QHBoxLayout* layout3;

protected slots:
    virtual void languageChange();

};

#endif // ORDENES_H
