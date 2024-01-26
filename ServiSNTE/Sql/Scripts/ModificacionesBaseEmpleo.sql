-- Miercoles 3 de febrero del 2016
-- en esta fecha, ya se estan haciendo 
-- pruebas con datos reales, por lo que es necesario
-- que las modificaciones se realicen, con scripts

alter table empleo drop constraint empleo_pkey;
alter table empleo add constraint empleo_primary_key primary key(idpersona);
alter table otrosingresos add constraint  otrosingresos_pkey primary key(idpersona); 
alter table telefonos add column extension varchar(10);

---Correo Empresa, esta en el Sql Correos.sql 

alter table ReferenciaPersonal  drop column ClaveReferencia;
alter table ReferenciaPersonal add column IdCliente integer references Personas(IdPersona);


--- ELimine la referencia duplicada ----
---  Se deberia, mantener 
alter table referenciapersonal drop constraint referenciapersonal_idpersona_key;
