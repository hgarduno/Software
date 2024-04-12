/****************************************************************************
** Form interface generated from reading ui file 'UI/MuestraExistenciaExpendios.ui'
**
** Created: Thu Apr 11 21:39:53 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef MUESTRAEXISTENCIAEXPENDIOS_H
#define MUESTRAEXISTENCIAEXPENDIOS_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class QPushButton;

class MuestraExistenciaExpendios : public QDialog
{
    Q_OBJECT

public:
    MuestraExistenciaExpendios( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~MuestraExistenciaExpendios();

    QLabel* textLabel1;
    QTable* QTExistenciaExpendios;
    QPushButton* pushButton10;
    QPushButton* pushButton11;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* MuestraExistenciaExpendiosLayout;
    QHBoxLayout* layout21;

protected slots:
    virtual void languageChange();

};

#endif // MUESTRAEXISTENCIAEXPENDIOS_H
