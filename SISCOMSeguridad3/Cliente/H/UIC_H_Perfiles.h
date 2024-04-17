/****************************************************************************
** Form interface generated from reading ui file 'UI/UI_Perfiles.ui'
**
** Created: Fri Apr 12 21:23:52 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PERFILES_H
#define PERFILES_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QTable;
class QPushButton;

class Perfiles : public QWidget
{
    Q_OBJECT

public:
    Perfiles( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~Perfiles();

    QLabel* textLabel1;
    QLabel* textLabel2_2;
    QLineEdit* QLEDscPerfil;
    QTable* QTDatos;
    QPushButton* QPBRPerfil;
    QPushButton* pushButton1_2;
    QLabel* textLabel2;
    QLineEdit* QLENmbPerfil;

protected:
    QGridLayout* PerfilesLayout;
    QSpacerItem* spacer1;
    QHBoxLayout* layout3;
    QSpacerItem* spacer1_2;
    QVBoxLayout* layout1_2;
    QVBoxLayout* layout1;

protected slots:
    virtual void languageChange();

};

#endif // PERFILES_H
