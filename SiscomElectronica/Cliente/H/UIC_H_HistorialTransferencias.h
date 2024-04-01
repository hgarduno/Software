/****************************************************************************
** Form interface generated from reading ui file 'UI/HistorialTransferencias.ui'
**
** Created: Wed Jan 31 10:48:05 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef HISTORIALTRANSFERENCIAS_H
#define HISTORIALTRANSFERENCIAS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QTable;
class CQControlFecha;

class HistorialTransferencias : public QWidget
{
    Q_OBJECT

public:
    HistorialTransferencias( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~HistorialTransferencias();

    QPushButton* QPBConsulta;
    QLabel* textLabel1;
    QTable* QTDatos;
    QPushButton* QPBReEnviaTrans;
    QLabel* textLabel2;
    CQControlFecha* QCtrFecha;
    QLabel* textLabel2_2;
    CQControlFecha* QCtrFechaFin;
    QPushButton* QPBSeleccionaExpendio;

protected:
    QGridLayout* HistorialTransferenciasLayout;
    QVBoxLayout* layout11;
    QVBoxLayout* layout4;
    QVBoxLayout* layout4_2;

protected slots:
    virtual void languageChange();

};

#endif // HISTORIALTRANSFERENCIAS_H
