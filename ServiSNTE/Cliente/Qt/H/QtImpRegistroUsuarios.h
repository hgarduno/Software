#ifndef __QTIMPREGISTROUSUARIOS_H__
#define __QTIMPREGISTROUSUARIOS_H__
#include <RegistroUsuarios.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;
class zUsuario;
class QtImpRegistroUsuarios:public RegistroUsuarios
{
Q_OBJECT
public:
	QtImpRegistroUsuarios(QWidget *pQWParent=0,
				const char *pchrPtrName=0);
private:
	void IniciaVariables();
	void ConectaSlots();
	void Conexion(zSiscomConexion *pzSisConexion);
	zUsuario *FormaUsuario();
private:
	zSiscomConexion *zSisConexion;
	zUsuario *zPerUsuario;
private:
	void RegistrarUsuario();
private slots:
	void SlotNombre();
	void SlotApellidoPaterno();
	void SlotApellidoMaterno();
	void SlotCtrPerfiles();
	void SlotFirma();
	void SlotContrasena();
	void SlotRepetirContrasena();
	void SlotRegistrar();	
};

#endif
