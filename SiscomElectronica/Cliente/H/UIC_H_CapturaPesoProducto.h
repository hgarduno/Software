/****************************************************************************
** Form interface generated from reading ui file 'UI/CapturaPesoProducto.ui'
**
** Created: Thu Apr 11 21:39:53 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAPTURAPESOPRODUCTO_H
#define CAPTURAPESOPRODUCTO_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QLineEdit;

class CapturaPesoProducto : public QDialog
{
    Q_OBJECT

public:
    CapturaPesoProducto( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CapturaPesoProducto();

    QPushButton* QPBRegistrar;
    QPushButton* QPBTerminar;
    QLabel* textLabel1_4_2_2;
    QLineEdit* QLEProducto;
    QLabel* textLabel1_4_2_2_2;
    QLineEdit* QLEPeso;

protected:
    QGridLayout* CapturaPesoProductoLayout;
    QHBoxLayout* layout20;
    QHBoxLayout* layout21;
    QVBoxLayout* layout1_3_2_2;
    QVBoxLayout* layout1_3_2_2_2;

protected slots:
    virtual void languageChange();

};

#endif // CAPTURAPESOPRODUCTO_H
