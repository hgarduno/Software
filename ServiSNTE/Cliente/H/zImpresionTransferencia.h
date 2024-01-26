#ifndef __ZIMPRESIONTRANSFERENCIA_H__
#define __ZIMPRESIONTRANSFERENCIA_H__
class zSiscomRegistro;
class zTransferencia;
class zImpresionTransferencia
{
public:
	zImpresionTransferencia();
	void Transferencia(zTransferencia *pzTransferencia);
	const char *Dato(const char *pchrPtrCampo);
	const char *CampoProducto(const char *pchrPtrCampo);
	void PrimerProducto();
	int SiguienteProducto();
private:
	const char *TiendaOrigen();
	const char *TiendaDestino();
private:
	zTransferencia *zTranDat;
	zSiscomRegistro *zSisRegProducto;
};


#endif
