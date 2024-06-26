/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/TransferenciasEnviadas.ui'
**
** Created: Thu Apr 11 21:05:33 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef TRANSFERENCIASENVIADAS_H
#define TRANSFERENCIASENVIADAS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QTable;
class QPushButton;

class TransferenciasEnviadas : public QWidget
{
    Q_OBJECT

public:
    TransferenciasEnviadas( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~TransferenciasEnviadas();

    QLabel* textLabel1;
    QLineEdit* QLERangoFecha;
    QLabel* textLabel2;
    QTable* QTTransferencias;
    QLabel* textLabel2_2;
    QTable* QTDetalleTransferencia;
    QPushButton* QPBConsultar;
    QPushButton* QPBCopiar;

protected:
    QGridLayout* TransferenciasEnviadasLayout;
    QHBoxLayout* layout3;
    QSpacerItem* spacer1;
    QVBoxLayout* layout1;
    QVBoxLayout* layout2;
    QVBoxLayout* layout2_2;

protected slots:
    virtual void languageChange();

};

#endif // TRANSFERENCIASENVIADAS_H
