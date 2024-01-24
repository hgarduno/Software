/****************************************************************************
** Form interface generated from reading ui file 'UI/RegistrarEntrega.ui'
**
** Created: Sun Feb 9 03:08:48 2020
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REGISTRARENTREGA_H
#define REGISTRARENTREGA_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class QTextEdit;
class QPushButton;

class RegistrarEntrega : public QWidget
{
    Q_OBJECT

public:
    RegistrarEntrega( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~RegistrarEntrega();

    QLabel* textLabel5;
    QTable* QTDatos;
    QLabel* textLabel6;
    QTextEdit* QTEComentario;
    QPushButton* QPBRegistra;
    QLabel* textLabel4;

protected:
    QGridLayout* RegistrarEntregaLayout;
    QVBoxLayout* layout23;
    QVBoxLayout* layout25;
    QVBoxLayout* layout4;

protected slots:
    virtual void languageChange();

};

#endif // REGISTRARENTREGA_H
