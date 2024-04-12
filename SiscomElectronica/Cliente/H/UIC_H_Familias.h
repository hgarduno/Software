/****************************************************************************
** Form interface generated from reading ui file 'UI/Familias.ui'
**
** Created: Thu Apr 11 21:52:54 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FAMILIASQ_H
#define FAMILIASQ_H

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

class FamiliasQ : public QWidget
{
    Q_OBJECT

public:
    FamiliasQ( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~FamiliasQ();

    QLabel* textLabel15;
    QLineEdit* QLEFamilia;
    QLabel* textLabel16;
    QLineEdit* QLEDscFamilia;
    QTable* QTDatos;
    QPushButton* QPBAnexar;
    QPushButton* QPBRegistrar;
    QPushButton* QPBModificar;

protected:
    QGridLayout* FamiliasQLayout;
    QVBoxLayout* layout95;
    QVBoxLayout* layout96;

protected slots:
    virtual void languageChange();

};

#endif // FAMILIASQ_H
