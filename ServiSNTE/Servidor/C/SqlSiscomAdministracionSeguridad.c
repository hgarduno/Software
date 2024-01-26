#include <SqlSiscomAdministracionSeguridad.h>
#include <SiscomDesarrolloMacros.h>
#include <stdio.h>


int SqlUsuarioSistema(SiscomOperaciones *pSiscomOpePtrDat)
{
 char lchrArrBuffer[512],
      lchrArrSqlUsuario[512];
sprintf(lchrArrSqlUsuario,
"select *						\n\
from FirmasSistema as a inner join 			\n\
	personas as b using(idpersona) inner join	\n\
	PersonasPorTipoPersona as c using(idPersona)	\n\
where usuario='%s'",
SiscomCampoAsociadoEntradaOperacion("Envio","Usuario",pSiscomOpePtrDat));
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDat,
			     "UsuarioSistema%",
			      lchrArrSqlUsuario);
return 0;
}
int SqlSiscomMenusSistema(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[1024];
char lchrArrSqlPopupMenus[1024],
     lchrArrSqlPopupMenusPropiedades[1024],
     lchrArrSqlOpcionesPopupMenu[1024],
     lchrArrSqlMenus[1024];
SqlPopupMenus(pSiscomOpePtrDat,lchrArrSqlPopupMenus);
SqlPopupMenusPropiedades(pSiscomOpePtrDat,lchrArrSqlPopupMenusPropiedades);
SqlOpcionesPopupMenu(pSiscomOpePtrDat,lchrArrSqlOpcionesPopupMenu);
SqlMenus(pSiscomOpePtrDat,lchrArrSqlMenus);
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDat,
			     "PopupMenus%PopupMenusPropiedades%OpcionesPopupMenu%Menus%",
			      lchrArrSqlPopupMenus,
			      lchrArrSqlPopupMenusPropiedades,
			      lchrArrSqlOpcionesPopupMenu,
			      lchrArrSqlMenus);
return 0;
}

void SqlPopupMenus(SiscomOperaciones *pSiscomOpePtrDat,char *pchrPtrSql)

{
sprintf(pchrPtrSql,
	"select * 			\n\
	 from popupmenu inner join 	\n\
	      menus using(idmenu);");
}

void SqlPopupMenusPropiedades(SiscomOperaciones *pSiscomOpePtrDat,char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select * 					\n\
	 from menuspropiedades inner join 		\n\
	      propiedadesmenu using(idpropiedad)	\n\
	 where idmenu in(select idmenu 			\n\
	                 from popupmenu inner join 	\n\
			      menus using(idmenu)) and 	\n\
		idtipopersona=%s;",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdTipoPersona",pSiscomOpePtrDat));

}
			
void SqlOpcionesPopupMenu(SiscomOperaciones *pSiscomOpePtrDat,char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"									\n\
select a.idmenu as idpopupmenu,							\n\
       a.idmenuopcion,								\n\
       b.idpropiedad,								\n\
       c.nombre,								\n\
       b.valor									\n\
from popupmenumenu as a  inner join 						\n\
     menuspropiedades as b  on a.idmenuopcion=b.idmenu  inner join		\n\
     propiedadesmenu as c on b.idpropiedad=c.idpropiedad			\n\
where idtipopersona=%s								\n\
order by a.idmenu desc,								\n\
         a.idmenuopcion asc,							\n\
	 b.idpropiedad asc",
SiscomCampoAsociadoEntradaOperacion("Envio","IdTipoPersona",pSiscomOpePtrDat));
}

void SqlMenus(SiscomOperaciones *pSiscomOpePtrDat,char *pchrPtrSql)
{
sprintf(pchrPtrSql,
        "select * 					\n\
	 from menus 					\n\
	 where idmenu not in(select idmenu 		\n\
	                     from popupmenu)");
}
