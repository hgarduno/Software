/****************************************************************************
** Form interface generated from reading ui file 'UI/DatosPedido.ui'
**
** Created: Fri Apr 12 21:25:58 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DATOSPEDIDO_H
#define DATOSPEDIDO_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QCtrlFechaHora;
class QTextEdit;
class QPushButton;

class DatosPedido : public QDialog
{
    Q_OBJECT

public:
    DatosPedido( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~DatosPedido();

    QLabel* textLabel1_2;
    QLineEdit* QLEPEntrega;
    QLabel* textLabel1;
    QCtrlFechaHora* QCtrFechaHora;
    QLabel* textLabel2;
    QLineEdit* QLEPagaCon;
    QLabel* textLabel2_2;
    QLineEdit* QLECambio;
    QLabel* textLabel3;
    QTextEdit* QTEObservaciones;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* DatosPedidoLayout;
    QVBoxLayout* layout37;
    QVBoxLayout* layout36;
    QHBoxLayout* layout35;
    QVBoxLayout* layout38;
    QVBoxLayout* layout39;
    QVBoxLayout* layout39_2;
    QVBoxLayout* layout42;
    QHBoxLayout* layout43;

protected slots:
    virtual void languageChange();

};

#endif // DATOSPEDIDO_H
