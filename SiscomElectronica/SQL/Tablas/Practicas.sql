create table Practica2(IdProducto integer references ProductoPorTipoProducto(IdProducto) unique,
		       Nombre varchar(50),
		       Materia varchar(50),
		       IdEscuela integer references Escuelas(IdEscuela));

create table Profesor(IdPersona integer references Personas(IdPersona),
                      IdProducto integer references Practica2(IdProducto));
 
		
