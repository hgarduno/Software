/****************************************************************************
** Form interface generated from reading ui file 'UI/CotizaPractica.ui'
**
** Created: Wed Jan 31 10:57:45 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef COTIZAPRACTICA_H
#define COTIZAPRACTICA_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QComboBox;
class QTable;
class QPushButton;
class QLCDNumber;

class CotizaPractica : public QDialog
{
    Q_OBJECT

public:
    CotizaPractica( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CotizaPractica();

    QLabel* textLabel1;
    QComboBox* QCBEscuelas;
    QLabel* textLabel1_2;
    QComboBox* QCBMaterias;
    QLabel* textLabel1_2_2;
    QComboBox* QCBPracticas;
    QTable* QTDatos;
    QPushButton* QPBAnexar;
    QPushButton* QPBVende;
    QPushButton* QPBCancelar;
    QLCDNumber* QLCNTotal;

protected:
    QGridLayout* CotizaPracticaLayout;
    QVBoxLayout* layout10;
    QVBoxLayout* layout10_2;
    QVBoxLayout* layout10_2_2;
    QHBoxLayout* layout7;
    QVBoxLayout* layout6;

protected slots:
    virtual void languageChange();

};

#endif // COTIZAPRACTICA_H
