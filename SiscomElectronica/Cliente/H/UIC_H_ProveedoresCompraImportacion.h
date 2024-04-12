/****************************************************************************
** Form interface generated from reading ui file 'UI/ProveedoresCompraImportacion.ui'
**
** Created: Thu Apr 11 21:39:53 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PROVEEDORESCOMPRAIMPORTACION_H
#define PROVEEDORESCOMPRAIMPORTACION_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;

class ProveedoresCompraImportacion : public QDialog
{
    Q_OBJECT

public:
    ProveedoresCompraImportacion( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~ProveedoresCompraImportacion();

    QLabel* textLabel1;
    QTable* QTProveedores;

protected:
    QGridLayout* ProveedoresCompraImportacionLayout;
    QVBoxLayout* layout63;

protected slots:
    virtual void languageChange();

};

#endif // PROVEEDORESCOMPRAIMPORTACION_H
