#include <Probando.h>
#include <zSiscomConexion.h>
#include <stdio.h>
FILE *gPtrFleArchivoLog;
zSiscomConexion *gzSiscomConexion;
int main(int pintArgc,
	 char **pchrPtrArgv)
{


gPtrFleArchivoLog=stdout;
zDatosPersonales *lzDatPersonales=new zDatosPersonales("Heli","Garduno","Esquivel");
zDatosPersonales *lzDatPersonales1=new zDatosPersonales("Said","Garduno","Esquivel");
zDatosPersonales *lzDatPersonales2=new zDatosPersonales("Azael","Garduno","Esquivel");
zDatosPersonales *lzDatPersonales3=new zDatosPersonales("Briseida","Garduno","Esquivel");
zDatosPersonales *lzDatPersonales4=new zDatosPersonales("Guadalupe","Casasola","Estrada");
zDatosPersonales *lzDatPersonales5=new zDatosPersonales("Itzel","Garduno","Casasola");
zDatosPersonales *lzDatPersonales6=new zDatosPersonales("Yoltzin","Garduno","Casasola");
zDatosPersonales *lzDatPersonales7=new zDatosPersonales("Margarita","Pena","Gonzalez");
zDatosPersonales *lzDatPersonales8=new zDatosPersonales("Angelica","Gavaldon","Gonzalez");
zSisLista<zDatosPersonales> lzSisDatPruebas;
lzSisDatPruebas.Agrega(lzDatPersonales);
lzSisDatPruebas.Agrega(lzDatPersonales1);
lzSisDatPruebas.Agrega(lzDatPersonales2);
lzSisDatPruebas.Agrega(lzDatPersonales3);
lzSisDatPruebas.Agrega(lzDatPersonales4);
lzSisDatPruebas.Agrega(lzDatPersonales5);
lzSisDatPruebas.Agrega(lzDatPersonales6);


printf("Todos\n");
ImprimeLista(&lzSisDatPruebas);

/*
EliminaElemento(&lzSisDatPruebas,0);
EliminaElemento(&lzSisDatPruebas,4);
EliminaElemento(&lzSisDatPruebas,3);
EliminaElemento(&lzSisDatPruebas,4);
EliminaElemento(&lzSisDatPruebas,2);
EliminaElemento(&lzSisDatPruebas,0);
*/
lzSisDatPruebas.Elimina(lzDatPersonales6);

lzSisDatPruebas.Agrega(lzDatPersonales8);
lzSisDatPruebas.Agrega(lzDatPersonales7);


ImprimeLista(&lzSisDatPruebas);


}

void ImprimeLista(zSisLista<zDatosPersonales> *pzSisLtaDatos)
{
zDatosPersonales *lzDatPersonalesRec=pzSisLtaDatos->Primer(); 
printf("Imprimiento %d Nodos\n",pzSisLtaDatos->NNodos());
    while(lzDatPersonalesRec)
    {
   printf("%s %s %s (%x) \n",
   	  lzDatPersonalesRec->Nombre(),
   	  lzDatPersonalesRec->APaterno(),
   	  lzDatPersonalesRec->AMaterno(),
	  lzDatPersonalesRec);
        lzDatPersonalesRec=pzSisLtaDatos->Siguiente();
    }
 printf("--------------\n");
}

void EliminaElemento(zSisLista<zDatosPersonales> *pzSisLtaDatos,
		    int pintNNodo)
{
   printf("Eliminando el Nodo:%d\n",pintNNodo);
   pzSisLtaDatos->Elimina(pintNNodo);
   ImprimeLista(pzSisLtaDatos);
}
