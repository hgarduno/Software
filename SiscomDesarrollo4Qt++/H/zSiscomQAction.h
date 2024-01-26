#ifndef __ZSISCOMQACTION_H__
#define __ZSISCOMQACTION_H__

#include <qaction.h>
class zSiscomMenu;
class QObject;
class QWorkspace;
class zSiscomQAction:public QAction
{
Q_OBJECT
public:
	zSiscomQAction(QObject *pQOParent,zSiscomMenu *pzSisMenu);
	zSiscomMenu *Menu();
	void AreaTrabajo(QWorkspace *pQWSAreaTrabajo);
private:
	zSiscomMenu *zSisMenu;
private:
	void AsignaPropiedades();
	void ConectaSlots();
signals:
	void SignalSelecciono(zSiscomQAction *pzSisQAction);
private slots:
	void SlotSelecciono();
private:
	QWorkspace *QWSAreaTrabajo;
	
};

#endif
