/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/TransferenciaParcial.ui'
**
** Created: Thu Apr 11 21:05:33 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef TRANSFERENCIAPARCIAL_H
#define TRANSFERENCIAPARCIAL_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QGroupBox;
class QTable;
class QPushButton;

class TransferenciaParcial : public QDialog
{
    Q_OBJECT

public:
    TransferenciaParcial( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~TransferenciaParcial();

    QGroupBox* groupBox1;
    QTable* QTProductos;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* TransferenciaParcialLayout;
    QSpacerItem* spacer1;
    QGridLayout* groupBox1Layout;
    QHBoxLayout* layout89;

protected slots:
    virtual void languageChange();

};

#endif // TRANSFERENCIAPARCIAL_H
