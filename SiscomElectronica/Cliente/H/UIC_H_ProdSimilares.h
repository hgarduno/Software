/****************************************************************************
** Form interface generated from reading ui file 'UI/ProdSimilares.ui'
**
** Created: Thu Dec 21 13:54:47 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PRODSIMILARES_H
#define PRODSIMILARES_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTable;

class ProdSimilares : public QDialog
{
    Q_OBJECT

public:
    ProdSimilares( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~ProdSimilares();

    QTable* QTDatos;

protected:
    QGridLayout* ProdSimilaresLayout;

protected slots:
    virtual void languageChange();

};

#endif // PRODSIMILARES_H