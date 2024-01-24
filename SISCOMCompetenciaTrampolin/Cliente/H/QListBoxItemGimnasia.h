#ifndef __QLISTBOXITEMGIMNASIA_H__
#define __QLISTBOXITEMGIMNASIA_H__
#include <qlistbox.h>
class CQSisClase;
class CQSisClaseNivel;
class CQSisGrupo;
class QPainter;
class QListBoxItemClase:public QListBoxItem
{
public:
	QListBoxItemClase(CQSisClase *);
	CQSisClase *Clase();
			   
private:
	CQSisClase *CQSClase;
private:
	virtual void paint(QPainter *);
	virtual int width(const QListBox *) const ; 
	virtual int height(const QListBox *) const ; 

};
class QListBoxItemNivel:public QListBoxItem
{
public:
	QListBoxItemNivel(CQSisClaseNivel *);
	CQSisClaseNivel *ClaseNivel();
private:
	CQSisClaseNivel *CQSCNivel;
	virtual void paint(QPainter *);
	virtual int width(const QListBox *) const;
	virtual int height(const QListBox *) const;

};


class QListBoxItemGrupo:public QListBoxItem
{
public:
	QListBoxItemGrupo(CQSisGrupo*);
	CQSisGrupo *Grupo();
private:
	CQSisGrupo *CQSGrupo;
	virtual void paint(QPainter *);
	virtual int width(const QListBox *) const;
	virtual int height(const QListBox *) const;

};
#endif
