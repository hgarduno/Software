create table ClaveSatSiscom(Id integer unique,
			    Clave varchar(50) references productos(cveproducto),
			    Sat varchar(25),
			    PalabrasClave text, 
			    primary key(Clave,Sat));

