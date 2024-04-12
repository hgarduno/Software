/****************************************************************************
** Form interface generated from reading ui file 'UI/ProductosPaquete.ui'
**
** Created: Thu Apr 11 22:09:36 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PRODUCTOSPAQUETE_H
#define PRODUCTOSPAQUETE_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTable;
class QPushButton;

class ProductosPaquete : public QDialog
{
    Q_OBJECT

public:
    ProductosPaquete( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~ProductosPaquete();

    QTable* QTDatos;
    QPushButton* QPBAnexar;
    QPushButton* QPBEliminar;
    QPushButton* QPBCCantidad;

protected:
    QGridLayout* ProductosPaqueteLayout;
    QHBoxLayout* layout1;

protected slots:
    virtual void languageChange();

};

#endif // PRODUCTOSPAQUETE_H
