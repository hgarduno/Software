#ifndef __EJECUTANDOMODULOSISCOMELECTRONICA_H__
#define __EJECUTANDOMODULOSISCOMELECTRONICA_H__

class zSiscomConexion;
class EmpresaN;
class zLineaComandosEjecutaModuloSe;

QWidget *CargaModulo(const char *pchrPtrBiblioteca,
		     const char *pchrPtrModulo);
zSiscomConexion *Conectate(const char *,int);
char **Argumentos();
EmpresaN *Expendio();
SiscomRegistro3 *ExpendioRegistro3();
SiscomDatCom *SiscomDatComConexion(const char *pchrPtrDirIp,int pintPuerto);

void EjecutandoModulo(zLineaComandosEjecutaModuloSe *pzLnCmnEjModSe);
void CambiaLetra(zLineaComandosEjecutaModuloSe *,QApplication *);


#endif
