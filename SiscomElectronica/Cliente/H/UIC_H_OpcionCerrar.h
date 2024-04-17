/****************************************************************************
** Form interface generated from reading ui file 'UI/OpcionCerrar.ui'
**
** Created: Fri Apr 12 21:25:35 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef OPCIONCERRAR_H
#define OPCIONCERRAR_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;

class OpcionCerrar : public QDialog
{
    Q_OBJECT

public:
    OpcionCerrar( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~OpcionCerrar();

    QPushButton* QPBRealizarVenta;
    QPushButton* QPBCancelar;
    QLabel* textLabel2;

protected:
    QGridLayout* OpcionCerrarLayout;
    QHBoxLayout* layout1;

protected slots:
    virtual void languageChange();

};

#endif // OPCIONCERRAR_H
