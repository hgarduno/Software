--- El id de la pantalla frmPrincipalSistemaTiendas
INSERT INTO objetosxpantalla select 1,
                                    idObjeto,
				    idPerfil,
				    idPropiedad,
				    valorpropiedad 
			       from objetosxpantalla 
			       where idPantalla=(select idPantalla
			       	                 from pantalla
						 where nmbClase='frmPrincipalSistemaTiendas');
