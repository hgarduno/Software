create table AmbientesFacturacionPhp(IdAmbiente integer unique,
				 BinarioPhp varchar(128),
				 ScriptFacturacion varchar(128),
			         RutaSistemaPhpFacturacion varchar(1024),
				 RutaArchivoFactura varchar(1024));

create table AmbienteFacturacionActivo(IdAmbiente integer references 
					 	  AmbientesFacturacionPhp(IdAmbiente),
				       Descripcion varchar(128));

create table CorreosEnvioFacturacion(IdCorreo integer unique,
				     Correo varchar(128),
				     Password varchar(128));

create table CorreoActivoEnvioFacturacion(IdCorreo integer references 
						 CorreosEnvioFacturacion(IdCorreo),
					  Descripcion varchar(128));

