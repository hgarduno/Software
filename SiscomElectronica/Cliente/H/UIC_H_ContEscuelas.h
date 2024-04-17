/****************************************************************************
** Form interface generated from reading ui file 'UI/ContEscuelas.ui'
**
** Created: Fri Apr 12 21:35:25 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CONTESCUELAS_H
#define CONTESCUELAS_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QTable;
class QPushButton;

class ContEscuelas : public QDialog
{
    Q_OBJECT

public:
    ContEscuelas( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~ContEscuelas();

    QLabel* textLabel4;
    QLineEdit* QLEEscuela;
    QTable* QTDatos;
    QPushButton* QPBAnexar;
    QPushButton* QPBRegistrar;
    QPushButton* QPBSelEscuela;
    QPushButton* pushButton27_3;

protected:
    QGridLayout* ContEscuelasLayout;
    QVBoxLayout* layout64;
    QHBoxLayout* layout68;

protected slots:
    virtual void languageChange();

};

#endif // CONTESCUELAS_H
