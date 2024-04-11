/****************************************************************************
** Form interface generated from reading ui file 'UI/UI_Firmas.ui'
**
** Created: Sat Jan 27 16:42:40 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FIRMAS_H
#define FIRMAS_H

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

class Firmas : public QWidget
{
    Q_OBJECT

public:
    Firmas( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~Firmas();

    QTable* QTDatos;
    QLabel* textLabel1;
    QLineEdit* QLEUsuario;
    QLabel* textLabel1_2;
    QLineEdit* QLEFirma;
    QLabel* textLabel1_2_2;
    QLineEdit* QLEPassword;
    QPushButton* QPBRegistraF;
    QPushButton* pushButton15_2;

protected:
    QGridLayout* FirmasLayout;
    QSpacerItem* spacer6;
    QVBoxLayout* layout18;
    QVBoxLayout* layout18_2;
    QVBoxLayout* layout18_2_2;

protected slots:
    virtual void languageChange();

};

#endif // FIRMAS_H
