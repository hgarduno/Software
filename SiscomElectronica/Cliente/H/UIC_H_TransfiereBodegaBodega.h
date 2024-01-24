/****************************************************************************
** Form interface generated from reading ui file 'UI/TransfiereBodegaBodega.ui'
**
** Created: Thu Dec 21 12:53:41 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef TRANSFIEREBODEGABODEGA_H
#define TRANSFIEREBODEGABODEGA_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlCmbBodegas4;
class QPushButton;
class QTable;
class QTextEdit;
class QCtrlProductosSE;
class QLineEdit;

class TransfiereBodegaBodega : public QWidget
{
    Q_OBJECT

public:
    TransfiereBodegaBodega( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~TransfiereBodegaBodega();

    QLabel* textLabel1;
    QCtrlCmbBodegas4* QCmbBodegasO;
    QLabel* textLabel1_2;
    QCtrlCmbBodegas4* QCmbBodegasD;
    QPushButton* QPBTransfiere;
    QLabel* textLabel4;
    QTable* QTDatos;
    QLabel* textLabel5;
    QTextEdit* QTEDescripcion;
    QLabel* textLabel2;
    QCtrlProductosSE* QCtrProductos;
    QLabel* textLabel1_3;
    QLineEdit* QLECantidad;
    QLabel* textLabel3;
    QLineEdit* QLEBodegaO;
    QLabel* textLabel3_3;
    QLineEdit* QLEExistenciaO;
    QLabel* textLabel3_2;
    QLineEdit* QLEBodegaD;
    QLabel* textLabel3_3_2;
    QLineEdit* QLEExistenciaD;

protected:
    QGridLayout* TransfiereBodegaBodegaLayout;
    QHBoxLayout* layout3;
    QVBoxLayout* layout1;
    QVBoxLayout* layout1_2;
    QVBoxLayout* layout6;
    QVBoxLayout* layout8;
    QVBoxLayout* layout4;
    QVBoxLayout* layout10;
    QHBoxLayout* layout15;
    QHBoxLayout* layout13;
    QVBoxLayout* layout16;
    QVBoxLayout* layout16_3;
    QHBoxLayout* layout14;
    QVBoxLayout* layout16_2;
    QVBoxLayout* layout16_3_2;

protected slots:
    virtual void languageChange();

};

#endif // TRANSFIEREBODEGABODEGA_H
