/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/ActivaServidor.ui'
**
** Created: Thu Apr 11 21:05:33 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef ACTIVASERVIDOR_H
#define ACTIVASERVIDOR_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlTiendasEntrega;
class QTable;
class QPushButton;

class ActivaServidor : public QWidget
{
    Q_OBJECT

public:
    ActivaServidor( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ActivaServidor();

    QLabel* textLabel1;
    QCtrlTiendasEntrega* QCtrTiendas;
    QTable* QTServidores;
    QPushButton* QPBConsulta;
    QPushButton* QPBCambiarConexionA;

protected:
    QGridLayout* ActivaServidorLayout;
    QHBoxLayout* layout14;

protected slots:
    virtual void languageChange();

};

#endif // ACTIVASERVIDOR_H
