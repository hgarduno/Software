/****************************************************************************
** Form interface generated from reading ui file 'UI/TransferenciaExpendioAExpendio.ui'
**
** Created: Thu Apr 11 21:39:52 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef TRANSFERENCIAEXPENDIOAEXPENDIO_H
#define TRANSFERENCIAEXPENDIOAEXPENDIO_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class QCtrlExpendios;
class QLineEdit;
class QCtrlProductosSE;
class QPushButton;

class TransferenciaExpendioAExpendio : public QWidget
{
    Q_OBJECT

public:
    TransferenciaExpendioAExpendio( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~TransferenciaExpendioAExpendio();

    QLabel* textLabel1_2_2;
    QTable* QTDatos;
    QLabel* textLabel1;
    QCtrlExpendios* QCtrExpendiosO;
    QLabel* textLabel1_4_2;
    QLineEdit* QLEExistenciaOrigen;
    QLabel* textLabel1_2;
    QCtrlExpendios* QCtrExpendiosD;
    QLabel* textLabel1_4_2_2;
    QLineEdit* QLEExistenciaDestino;
    QLabel* textLabel1_3;
    QCtrlProductosSE* QCtrProductos;
    QLabel* textLabel1_4;
    QLineEdit* QLECantidad;
    QPushButton* QPBAnexar;
    QPushButton* QPBImprimir;
    QPushButton* QPBRegistrar;
    QPushButton* QPBEliminar;

protected:
    QGridLayout* TransferenciaExpendioAExpendioLayout;
    QVBoxLayout* layout3;
    QHBoxLayout* layout20;
    QVBoxLayout* layout17;
    QVBoxLayout* layout6;
    QVBoxLayout* layout8_2;
    QVBoxLayout* layout18;
    QVBoxLayout* layout6_2;
    QVBoxLayout* layout8_2_2;
    QHBoxLayout* layout22;
    QVBoxLayout* layout13;
    QVBoxLayout* layout8;
    QHBoxLayout* layout40;

protected slots:
    virtual void languageChange();

};

#endif // TRANSFERENCIAEXPENDIOAEXPENDIO_H
