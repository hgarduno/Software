/****************************************************************************
** Form interface generated from reading ui file 'UI/CierraApartado.ui'
**
** Created: Thu Apr 11 21:39:52 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CIERRAAPARTADO_H
#define CIERRAAPARTADO_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class QLineEdit;
class CQControlFecha;
class QPushButton;

class CierraApartado : public QDialog
{
    Q_OBJECT

public:
    CierraApartado( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CierraApartado();

    QLabel* textLabel3;
    QTable* QTApartados;
    QLabel* textLabel2;
    QLineEdit* QLEOrden;
    QLabel* textLabel1;
    CQControlFecha* QCtrFechaIni;
    QLabel* textLabel1_2;
    CQControlFecha* QCtrFechaFin;
    QPushButton* QPBConsultar;
    QPushButton* QPBPagar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* CierraApartadoLayout;
    QVBoxLayout* layout6;
    QVBoxLayout* layout4;
    QVBoxLayout* layout3;
    QVBoxLayout* layout3_2;
    QHBoxLayout* layout36;

protected slots:
    virtual void languageChange();

};

#endif // CIERRAAPARTADO_H
