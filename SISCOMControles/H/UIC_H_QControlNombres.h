/****************************************************************************
** Form interface generated from reading ui file 'UI/QControlNombres.ui'
**
** Created: Fri Apr 12 21:24:17 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef QCONTROLNOMBRES_H
#define QCONTROLNOMBRES_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;

class QControlNombres : public QWidget
{
    Q_OBJECT

public:
    QControlNombres( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~QControlNombres();

    QLabel* textLabel1_2_2;
    QLineEdit* QLEAMaterno;
    QLabel* textLabel1;
    QLineEdit* QLENombre;
    QLabel* textLabel1_2;
    QLineEdit* QLEAPaterno;

protected:
    QGridLayout* QControlNombresLayout;
    QVBoxLayout* layout1_2_2;
    QVBoxLayout* layout1;
    QVBoxLayout* layout1_2;

protected slots:
    virtual void languageChange();

};

#endif // QCONTROLNOMBRES_H
