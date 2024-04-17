/****************************************************************************
** Form interface generated from reading ui file 'UI/ClientesRegistrados4.ui'
**
** Created: Fri Apr 12 21:25:58 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CLIENTESREGISTRADOS4_H
#define CLIENTESREGISTRADOS4_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class QPushButton;

class ClientesRegistrados4 : public QDialog
{
    Q_OBJECT

public:
    ClientesRegistrados4( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~ClientesRegistrados4();

    QLabel* textLabel1;
    QTable* QTClientes;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* ClientesRegistrados4Layout;
    QVBoxLayout* layout24;
    QHBoxLayout* layout25;

protected slots:
    virtual void languageChange();

};

#endif // CLIENTESREGISTRADOS4_H
