/****************************************************************************
** Form interface generated from reading ui file 'UI/BuscaPersonas.ui'
**
** Created: Thu Apr 11 21:37:04 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef BUSCAPERSONAS_H
#define BUSCAPERSONAS_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;
class QTabWidget;
class QWidget;
class QTable;

class BuscaPersonas : public QDialog
{
    Q_OBJECT

public:
    BuscaPersonas( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~BuscaPersonas();

    QLabel* textLabel3_4;
    QLineEdit* QLENombre;
    QLabel* textLabel3_2_3;
    QLineEdit* QLEAPaterno;
    QLabel* textLabel3_2_2_2;
    QLineEdit* QLEAMaterno;
    QLabel* textLabel6;
    QLineEdit* QLEIdPersona;
    QPushButton* QPBConsulta;
    QPushButton* QPBSPersona;
    QPushButton* QPBCancelar;
    QTabWidget* tabWidget5;
    QWidget* tab;
    QLabel* textLabel1;
    QTable* QTDatos;
    QWidget* tab_2;
    QWidget* TabPage;

protected:
    QGridLayout* BuscaPersonasLayout;
    QVBoxLayout* layout34;
    QHBoxLayout* layout19_2;
    QVBoxLayout* layout5_3;
    QVBoxLayout* layout5_2_3;
    QVBoxLayout* layout5_2_2_2;
    QHBoxLayout* layout75;
    QSpacerItem* spacer10;
    QVBoxLayout* layout74;
    QHBoxLayout* layout36;
    QGridLayout* tabLayout;
    QVBoxLayout* layout35;

protected slots:
    virtual void languageChange();

};

#endif // BUSCAPERSONAS_H
