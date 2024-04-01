/****************************************************************************
** Form interface generated from reading ui file 'UI/AdministracionCajas.ui'
**
** Created: Wed Jan 31 10:48:05 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef ADMINISTRACIONCAJAS_H
#define ADMINISTRACIONCAJAS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QTabWidget;
class QLabel;
class QTable;
class QLineEdit;

class AdministracionCajas : public QWidget
{
    Q_OBJECT

public:
    AdministracionCajas( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~AdministracionCajas();

    QPushButton* QPBRangoFechas;
    QPushButton* QPBRangoFechas_2;
    QPushButton* QPBRangoFechas_2_2;
    QPushButton* QPBRangoFechas_2_3;
    QTabWidget* QTWOCajas;
    QWidget* tab;
    QLabel* textLabel1;
    QTable* QTCajasRegistradas;
    QLabel* textLabel4;
    QLineEdit* QLEImporteCaja;
    QPushButton* QPBRegistrarImporte;
    QPushButton* QPBActualizar;

protected:
    QGridLayout* AdministracionCajasLayout;
    QVBoxLayout* layout15;
    QSpacerItem* spacer2;
    QVBoxLayout* layout9;
    QGridLayout* tabLayout;
    QVBoxLayout* layout1;
    QVBoxLayout* layout11;

protected slots:
    virtual void languageChange();

};

#endif // ADMINISTRACIONCAJAS_H
