create table Correos(IdCorreo integer unique,
                    Correo varchar(120),
                    Descripcion varchar(128));

create table CorreoCliente(IdPersona integer references Personas(IdPersona),
			   IdCorreo integer references Correos(IdCorreo));
			  
create table CorreoEmpresa(IdEmpresa integer references Empresas(IdEmpresa),
			   IdCorreo integer references Correos(IdCorreo));
