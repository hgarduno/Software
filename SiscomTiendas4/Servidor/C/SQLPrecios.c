#include <SQLPrecios.h>

void SQLRegistraPrecios(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Prim,
		  *lLCSiscomPro2Act;
LCamposSiscomPro2 *lLCSiscomPro2Contador;
int lintNRegistros;
char lchrArrSQL[1024];
ObtenInformacionArgumento("Precios",
			  pSAgsSiscom,
			  &lLCSiscomPro2Prim,
			  &lLCSiscomPro2Act,
			  &lintNRegistros);
for(lLCSiscomPro2Contador=pSAgsSiscom->LCSiscomPro2Dat;
    lLCSiscomPro2Contador;
    lLCSiscomPro2Contador=lLCSiscomPro2Contador->SCP2PtrSig)
{
  sprintf(lchrArrSQL,
  	  "insert into Precios values(%s,'%s','%s');",
	  SiscomObtenDato(lLCSiscomPro2Contador,"IdPrecio"),
	  SiscomObtenDato(lLCSiscomPro2Contador,"Nombre"),
	  SiscomObtenDato(lLCSiscomPro2Contador,"Dsc"));
  SiscomAnexaRegistroPro2(&lLCSiscomPro2Prim,
  			  &lLCSiscomPro2Act,
			  &lintNRegistros,
			  "ComandoSQL,EdoRegistro",
			  lchrArrSQL,"");
}
AsignaInformacionArgumento("Precios",
			   pSAgsSiscom,
			   lLCSiscomPro2Prim,
			   lLCSiscomPro2Act,
			   lintNRegistros);

}

void SQLPreciosRegistrados(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[1024];
	sprintf(lchrArrSQL,
		"select * from precios order by nombre");
	EjecutaConsultaYResponde(pSAgsSiscom,lchrArrSQL);
}

void SQLObtenProductos(SArgsSiscom *pSAgsSiscom)
{

LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
int lintNRespuesta;

SiscomConsultaBaseDatosSinDatosConexion(
	"select * from producto order by clave",
	pSAgsSiscom->chrArrDirIpAD,
	pSAgsSiscom->intPtoComAD,
	&lLCSiscomPro2Reg,
	&lintNRespuesta);
AsignaInformacionArgumento("Productos",
			    pSAgsSiscom,
			    lLCSiscomPro2Reg,
			    0,
			    lintNRespuesta);
}
void SQLObtenPrecios(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
int lintNRespuesta;
SiscomConsultaBaseDatosSinDatosConexion(
	"select * from precios order by nombre",
	pSAgsSiscom->chrArrDirIpAD,
	pSAgsSiscom->intPtoComAD,
	&lLCSiscomPro2Reg,
	&lintNRespuesta);
AsignaInformacionArgumento("Precios",
			    pSAgsSiscom,
			    lLCSiscomPro2Reg,
			    0,
			    lintNRespuesta);
}
void SQLIniciaPreciosProductos(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Precios;
LCamposSiscomPro2 *lLCSiscomPro2Productos;
LCamposSiscomPro2 *lLCSiscomPro2RegistroPrim=0,
		  *lLCSiscomPro2RegistroAct=0;
int lintNRegistros=0;
char lchrArrSQL[1024];
lLCSiscomPro2Productos=SiscomArgumentoOperacionPrim("Productos",pSAgsSiscom);
for(;
    lLCSiscomPro2Productos;
    lLCSiscomPro2Productos=lLCSiscomPro2Productos->SCP2PtrSig)
for(lLCSiscomPro2Precios=SiscomArgumentoOperacionPrim("Precios",pSAgsSiscom);
    lLCSiscomPro2Precios;
    lLCSiscomPro2Precios=lLCSiscomPro2Precios->SCP2PtrSig)
{
sprintf(lchrArrSQL,
	"insert into PreciosProducto values(%s,%s,0.0);",
	SiscomObtenDato(lLCSiscomPro2Productos,"idproducto"),
	SiscomObtenDato(lLCSiscomPro2Precios,"idprecio"));
SiscomAnexaRegistroPro2(&lLCSiscomPro2RegistroPrim,
			&lLCSiscomPro2RegistroAct,
			&lintNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}
AsignaInformacionArgumento("Registrar",
                           pSAgsSiscom,
			   lLCSiscomPro2RegistroPrim,
			   lLCSiscomPro2RegistroAct,
			   lintNRegistros);
}

void SQLPreciosProducto(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[1024];

	sprintf(lchrArrSQL,
		"select	a.precio,				\
			a.cantidad,				\
			b.idprecio,				\
			b.nombre,				\
			b.dsc					\
		 from 	preciosproducto	as a inner join		\
		 	precios as b using(idprecio)		\
		 where idproducto=%s				\
		 order by a.precio",
		 pSAgsSiscom->chrPtrArgConsulta[1]);
	EjecutaConsultaYResponde(pSAgsSiscom,lchrArrSQL);
}
void SQLActualizaPrecioProducto(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Prim=0,
		  *lLCSiscomPro2Act=0;
LCamposSiscomPro2 *lLCSiscomPro2Contador=0;
int lintNRegistros;
char lchrArrSQL[1024];
ObtenInformacionArgumento("Precios",
			  pSAgsSiscom,
			  &lLCSiscomPro2Prim,
			  &lLCSiscomPro2Act,
			  &lintNRegistros);
sprintf(lchrArrSQL,
	"update preciosproducto set precio=%s,	\
				    cantidad=%s	\
	 where idproducto=%s and		\
	       idprecio=%s",
	 pSAgsSiscom->chrPtrArgConsulta[3],
	 pSAgsSiscom->chrPtrArgConsulta[4],
	 pSAgsSiscom->chrPtrArgConsulta[1],
	 pSAgsSiscom->chrPtrArgConsulta[2]);
SiscomAnexaRegistroPro2(&lLCSiscomPro2Prim,
  			  &lLCSiscomPro2Act,
			  &lintNRegistros,
			  "ComandoSQL,EdoRegistro",
			  lchrArrSQL,"");
AsignaInformacionArgumento("Precios",
			   pSAgsSiscom,
			   lLCSiscomPro2Prim,
			   lLCSiscomPro2Act,
			   lintNRegistros);
}
