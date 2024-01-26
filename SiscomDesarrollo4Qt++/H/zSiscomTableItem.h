#ifndef __ZSISCOMTABLEITEM_H__
#define __ZSISCOMTABLEITEM_H__
#include <qtable.h>

class zSiscomTableItem:public QTableItem
{
public:
	zSiscomTableItem(QTable *,
				const QColor &, 
				EditType ,
				const QString &);
	void paint(QPainter *,const QColorGroup &,const QRect &,bool );
private:
	const QColor QCColor;
};
#endif
