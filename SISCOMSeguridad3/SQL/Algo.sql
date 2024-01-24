select	idPantalla,
	a.idObjeto,
	idPerfil,
	a.idPropiedad,
	NmbPropiedad,
	ValorPropiedad

from	objetosxpantalla as a inner join 
	propiedades as b on (a.idObjeto=b.IdObjeto and 
			     a.idPropiedad=b.IdPropiedad)
	
where idPantalla= (select idPantalla 
		   from pantalla 
		   where NmbClase='SISCOMVentanaPrincipal' and
		         idAplicacion=(select idAplicacion
			 	       from aplicaciones
				       where NmbAplicacion='SISCOMElectronica')
		   ) and
       idPerfil=1165409548;
	
 
