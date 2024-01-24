create table CredencialAlumno(IdPersona integer references personas(idpersona),
			      Credencial varchar(13) primary key);
