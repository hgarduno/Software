/****************************************************************************
** Form interface generated from reading ui file 'UI/UI_SelIconos.ui'
**
** Created: Fri Apr 12 21:23:37 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef SELICONOS_H
#define SELICONOS_H

#include <qvariant.h>
#include <qpixmap.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QIconView;
class QIconViewItem;
class QLabel;
class QLineEdit;

class SelIconos : public QDialog
{
    Q_OBJECT

public:
    SelIconos( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~SelIconos();

    QPushButton* QPBSelDirectorio;
    QIconView* QIVArchivos;
    QLabel* QPIcono;
    QLabel* textLabel1;
    QLineEdit* QLEArchivo;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* SelIconosLayout;
    QHBoxLayout* layout6;
    QVBoxLayout* layout5;
    QVBoxLayout* layout1;
    QHBoxLayout* layout4;

protected slots:
    virtual void languageChange();

private:
    QPixmap image0;

};

#endif // SELICONOS_H
