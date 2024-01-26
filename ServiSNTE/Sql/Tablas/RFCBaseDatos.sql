---  
--- El Id Persona no se ocupa ahorita , lo unico es que
-- se pueda almacenar la informacion para validar los 
-- rfcs que pueden tener credito

create table RFCBaseDatos(RFC varchar(15) unique ,
			  IdPersona integer);
