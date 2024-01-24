/****************************************************************************
** Form interface generated from reading ui file 'UI/CotizaVdys.ui'
**
** Created: Sun Feb 9 03:08:48 2020
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef COTIZAVDYS_H
#define COTIZAVDYS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTable;
class QLabel;
class QLineEdit;
class QPushButton;

class CotizaVdys : public QWidget
{
    Q_OBJECT

public:
    CotizaVdys( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~CotizaVdys();

    QTable* table3;
    QLabel* textLabel1;
    QLineEdit* QLECliente;
    QPushButton* QPBSCliente;

protected:
    QGridLayout* CotizaVdysLayout;
    QHBoxLayout* layout23;
    QVBoxLayout* layout22;

protected slots:
    virtual void languageChange();

};

#endif // COTIZAVDYS_H
