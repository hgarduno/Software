/****************************************************************************
** Form interface generated from reading ui file 'UI/MaterialPractica.ui'
**
** Created: Thu Apr 11 21:52:35 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef MATERIALPRACTICA_H
#define MATERIALPRACTICA_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTable;
class QLabel;
class QLineEdit;
class QPushButton;
class QLCDNumber;

class MaterialPractica : public QDialog
{
    Q_OBJECT

public:
    MaterialPractica( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~MaterialPractica();

    QTable* QTDatos;
    QLabel* textLabel4;
    QLineEdit* QLEEscuela;
    QLabel* textLabel4_2;
    QLineEdit* QLEMateria;
    QLabel* textLabel4_2_2;
    QLineEdit* QLEPractica;
    QPushButton* QPBAnexar;
    QPushButton* QPBEliminar;
    QPushButton* QPBRegistrar;
    QPushButton* pushButton27_3;
    QLCDNumber* QLCDNTotal;

protected:
    QGridLayout* MaterialPracticaLayout;
    QVBoxLayout* layout64;
    QVBoxLayout* layout64_2;
    QVBoxLayout* layout64_2_2;
    QHBoxLayout* layout78;
    QVBoxLayout* layout76;
    QVBoxLayout* layout77;

protected slots:
    virtual void languageChange();

};

#endif // MATERIALPRACTICA_H
