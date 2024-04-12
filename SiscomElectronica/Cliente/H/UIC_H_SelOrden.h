/****************************************************************************
** Form interface generated from reading ui file 'UI/SelOrden.ui'
**
** Created: Thu Apr 11 21:52:05 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef SELORDEN_H
#define SELORDEN_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QIconView;
class QIconViewItem;
class QPushButton;

class SelOrden : public QDialog
{
    Q_OBJECT

public:
    SelOrden( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~SelOrden();

    QIconView* QIVIOrdenes;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* SelOrdenLayout;
    QHBoxLayout* layout36;

protected slots:
    virtual void languageChange();

};

#endif // SELORDEN_H
