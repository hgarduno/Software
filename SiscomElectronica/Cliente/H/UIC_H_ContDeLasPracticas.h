/****************************************************************************
** Form interface generated from reading ui file 'UI/ContDeLasPracticas.ui'
**
** Created: Wed Jan 31 10:58:11 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CONTDELASPRACTICAS_H
#define CONTDELASPRACTICAS_H

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

class ContDeLasPracticas : public QDialog
{
    Q_OBJECT

public:
    ContDeLasPracticas( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~ContDeLasPracticas();

    QLabel* textLabel4;
    QLineEdit* QLEPractica;
    QTable* QTDatos;
    QPushButton* QPBAnexar;
    QPushButton* QPBRegistrar;
    QPushButton* QPBSelEscuela;
    QPushButton* pushButton27_3;

protected:
    QGridLayout* ContDeLasPracticasLayout;
    QVBoxLayout* layout64;
    QHBoxLayout* layout68;

protected slots:
    virtual void languageChange();

};

#endif // CONTDELASPRACTICAS_H
