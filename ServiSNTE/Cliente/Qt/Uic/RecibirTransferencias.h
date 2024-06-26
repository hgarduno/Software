/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/RecibirTransferencias.ui'
**
** Created: Thu Apr 11 21:05:33 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef RECIBIRTRANSFERENCIAS_H
#define RECIBIRTRANSFERENCIAS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QGroupBox;
class QLabel;
class QLineEdit;
class QTable;
class QTextEdit;
class QPushButton;

class RecibirTransferencias : public QWidget
{
    Q_OBJECT

public:
    RecibirTransferencias( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~RecibirTransferencias();

    QGroupBox* groupBox3;
    QLabel* textLabel2;
    QLineEdit* QLETienda;
    QLabel* textLabel2_2;
    QLineEdit* QLEResponsable;
    QLabel* textLabel2_4;
    QLineEdit* QLECamion;
    QLabel* textLabel2_3;
    QLineEdit* QLEChofer;
    QTable* QTDetalleTransferencias;
    QGroupBox* groupBox4;
    QTextEdit* QTEObservacionGeneral;
    QGroupBox* groupBox2;
    QTable* QTTransferencias;
    QPushButton* QPBRecibir;
    QPushButton* QPBParcial;
    QPushButton* QPBActualizar;

protected:
    QGridLayout* RecibirTransferenciasLayout;
    QGridLayout* groupBox3Layout;
    QHBoxLayout* layout6;
    QHBoxLayout* layout7;
    QHBoxLayout* layout8;
    QHBoxLayout* layout9;
    QGridLayout* groupBox4Layout;
    QGridLayout* groupBox2Layout;
    QHBoxLayout* layout44;

protected slots:
    virtual void languageChange();

};

#endif // RECIBIRTRANSFERENCIAS_H
