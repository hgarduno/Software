/****************************************************************************
** Form interface generated from reading ui file 'UI/ListaPuntosEntrega.ui'
**
** Created: Wed Apr 10 20:52:31 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef LISTAPUNTOSENTREGA_H
#define LISTAPUNTOSENTREGA_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QTable;
class QTextEdit;

class ListaPuntosEntrega : public QDialog
{
    Q_OBJECT

public:
    ListaPuntosEntrega( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~ListaPuntosEntrega();

    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;
    QLabel* textLabel1;
    QTable* QTPuntosEntrega;
    QLabel* textLabel2;
    QTextEdit* QTEReferencias;

protected:
    QGridLayout* ListaPuntosEntregaLayout;
    QHBoxLayout* layout1;
    QHBoxLayout* layout5;
    QVBoxLayout* layout3;
    QVBoxLayout* layout4;

protected slots:
    virtual void languageChange();

};

#endif // LISTAPUNTOSENTREGA_H
