#include <SiscomSqlOperaciones2.h>




/* Domingo 15 de noviembre del 2015 
 * Se agrega el archivo para integrar las funciones
 * que interactuan con las operaciones a base de datos
 */

/* Chiconcuac 15 de Noviembre del 2015
 * Funcion que toma de pSAgsSiscom->LCSiscomPro2Dat y recorre
 * cada uno de los nodos ejecutando SentenciaSql para formar
 * por cada nodo una sentencia Sql, al final del recorrido 
 * de la lista se asignara a pchrPtrArgumentoSalida las
 * sentencias generadas
 */
void SiscomSqlInsercionesDatosEntrada(SArgsSiscom *pSAgsSiscom,
				const char *pchrPtrArgumentoSalida,
				char *pchrPtrBufferSql,
				void (*SentenciaSql)(SArgsSiscom *pSAgsSiscom,
						    char *pchrPtrBuffer,
						     LCamposSiscomPro2 *pLCSiscomPro2Dat))
{
LCamposSiscomPro2 *lLCSiscomPro2SQLPrim=0,
		  *lLCSiscomPro2SQLAct=0,
		  *lLCSiscomPro2DatEntPrim;
int lintNRegistros;
SiscomObtenInformacionArgumento(pchrPtrArgumentoSalida,
				pSAgsSiscom,
				&lLCSiscomPro2SQLPrim,
				&lLCSiscomPro2SQLAct,
				&lintNRegistros);
for(lLCSiscomPro2DatEntPrim=pSAgsSiscom->LCSiscomPro2Dat;
    lLCSiscomPro2DatEntPrim;
    lLCSiscomPro2DatEntPrim=lLCSiscomPro2DatEntPrim->SCP2PtrSig)
{
SentenciaSql(pSAgsSiscom,pchrPtrBufferSql,lLCSiscomPro2DatEntPrim);
SiscomAnexaRegistroPro2(
		&lLCSiscomPro2SQLPrim,
		&lLCSiscomPro2SQLAct,
		&lintNRegistros,
		"ComandoSQL,EdoRegistro",
		pchrPtrBufferSql,
		"");
}
SiscomAsignaInformacionArgumento(pchrPtrArgumentoSalida,
                              pSAgsSiscom,
                              lLCSiscomPro2SQLPrim,
                              lLCSiscomPro2SQLAct,
                              lintNRegistros);
}
