/****************************************************************************
** Form interface generated from reading ui file 'UI/FirmaTiendas.ui'
**
** Created: Fri Apr 12 21:34:41 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FIRMATIENDAS_H
#define FIRMATIENDAS_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QIconView;
class QIconViewItem;
class QPushButton;

class FirmaTiendas : public QDialog
{
    Q_OBJECT

public:
    FirmaTiendas( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~FirmaTiendas();

    QIconView* QIVInforma;
    QPushButton* QPBAnexar;
    QPushButton* QPBEliminar;
    QPushButton* QPBSLetra;
    QPushButton* QPBAceptar;

protected:
    QGridLayout* FirmaTiendasLayout;
    QHBoxLayout* layout21;

protected slots:
    virtual void languageChange();

};

#endif // FIRMATIENDAS_H
