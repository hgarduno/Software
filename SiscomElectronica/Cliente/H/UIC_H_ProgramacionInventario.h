/****************************************************************************
** Form interface generated from reading ui file 'UI/ProgramacionInventario.ui'
**
** Created: Thu Dec 21 12:53:39 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PROGRAMACIONINVENTARIO_H
#define PROGRAMACIONINVENTARIO_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlMotivoInventario;
class QTextEdit;
class QPushButton;

class ProgramacionInventario : public QWidget
{
    Q_OBJECT

public:
    ProgramacionInventario( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ProgramacionInventario();

    QLabel* textLabel1_2;
    QCtrlMotivoInventario* QCtrMotivoInventario;
    QLabel* textLabel2;
    QTextEdit* QTEDescripcion;
    QPushButton* QPBRegistra;
    QPushButton* QPBTerminaInventario;

protected:
    QGridLayout* ProgramacionInventarioLayout;
    QVBoxLayout* layout6;
    QVBoxLayout* layout8;
    QHBoxLayout* layout10;

protected slots:
    virtual void languageChange();

};

#endif // PROGRAMACIONINVENTARIO_H
