--select  b.oid,*
--from Pantalla as a inner join 
--     ObjetosXPantalla as b using(idPantalla) inner join
--     Objeto as c using(idObjeto) inner join
--     Propiedades as d using(idObjeto,idPropiedad)
--
--where a.idAplicacion= 1138122369 and
--      a.idPantalla=1138122127 and
--      b.idPerfil=0 and
--      c.idObjeto=2;
--

--insert into ObjetosXPantalla (select idPantalla,
--				     idObjeto,
--				     1138721481,
--				     idPropiedad,
--				     valorPropiedad
--			       from objetosXPantalla
--			       where idPerfil=1138720211);
--


---select 
---	a.idUsuario,
---	a.idAplicacion,
---	a.idPerfil,
---	a.NmbUsuario,
---	a.APaterno,
---	a.AMaterno,
---	b.Firma,
---	b.Password
---       
---from usuarios as a left outer join firmas as b on(a.idUsuario=b.idUsuario)
---where idPerfil=1138750165 and
---      idAplicacion=1138749636;


select  *
from 	Pantalla as a 
	inner join  ObjetosXPantalla as b 
	using(idPantalla) inner join Objeto as c 
	using(idObjeto) inner join Propiedades as d 
	using(idObjeto,idPropiedad) 
where a.idAplicacion=1138799897 and 
      a.idPantalla=1138799278   and  
       b.idPerfil=1138799864;


select idObjeto,
       idPropiedad,
       'IdPantalla',
       'IdAplicacion',
       'NmbPantalla',
       'Archivo',
       'IdPerfil',
       'Valor Propiedad',
       nmbClase,
       nmbPropiedad
from objeto 
     inner join  propiedades using(idObjeto)


SELECT 'IdPerfil',idPerfil
from usuarios    
where idUsuario=(select idUsuario 
		 from firmas 
SELECT 'IdPerfil',idPerfi                     union                   select 'IdAplicacion',idAplicacion                      from aplicaciones                       where nmbAplicacion='SISCOMSeguridad3'                          union                           select 'IdPantalla',idPantalla                  from pantalla                   where nmbClase='Aplicaciones'
     
