/****************************************************************************
** Form interface generated from reading ui file 'UI/EstadosPedido.ui'
**
** Created: Wed Jan 31 10:48:06 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef ESTADOSPEDIDO_H
#define ESTADOSPEDIDO_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class CQControlFecha;
class QPushButton;

class EstadosPedido : public QDialog
{
    Q_OBJECT

public:
    EstadosPedido( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~EstadosPedido();

    QLabel* textLabel2;
    QTable* table3;
    QLabel* textLabel1;
    CQControlFecha* QCtrFechaInicio;
    QLabel* textLabel1_2;
    CQControlFecha* QCtrFechaFin;
    QPushButton* pushButton14;
    QPushButton* QPBConsulta;
    QPushButton* pushButton14_2;
    QPushButton* pushButton14_2_2;

protected:
    QGridLayout* EstadosPedidoLayout;
    QVBoxLayout* layout28;
    QHBoxLayout* layout31;
    QSpacerItem* spacer3;
    QHBoxLayout* layout29;
    QVBoxLayout* layout26;
    QVBoxLayout* layout26_2;

protected slots:
    virtual void languageChange();

};

#endif // ESTADOSPEDIDO_H
