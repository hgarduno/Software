/****************************************************************************
** Form interface generated from reading ui file 'UI/SeleccionaCompraImp.ui'
**
** Created: Fri Apr 12 21:25:59 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef SELECCIONACOMPRAIMP_H
#define SELECCIONACOMPRAIMP_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class QPushButton;

class SeleccionaCompraImp : public QDialog
{
    Q_OBJECT

public:
    SeleccionaCompraImp( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~SeleccionaCompraImp();

    QLabel* textLabel1;
    QTable* QTCompsImportacion;
    QPushButton* pushButton8;
    QPushButton* QPBAceptar;
    QPushButton* pushButton8_2_2;

protected:
    QGridLayout* SeleccionaCompraImpLayout;
    QVBoxLayout* layout25;
    QHBoxLayout* layout26;

protected slots:
    virtual void languageChange();

};

#endif // SELECCIONACOMPRAIMP_H
