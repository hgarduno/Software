--- Electronica Basica Sabado 29 3 sabados  , 8:00-12:00
--- Ensamblador 2 Semanas Proximo Lunes 31  13:30-15:30

insert into Cursos values(9,'ElectronicaBasica','Electronica Basica');
insert into Cursos values(10,'EnsambladorPIC','PICS programando en esamblador');

insert into RegistroProgramaCurso values(3,'Electronica Basica Marzo 2014');
insert into RegistroProgramaCurso values(4,'Ensamblador Marzo 2014');

---- Electronica basica 
insert into ProgramacionCursos values(3,9,'2014-03-29');
insert into FechasCursos values(9,'2014-03-29',3,20,20);
insert into HorariosCursos values(9,'2014-03-29','8:00','12:00');
insert into HorariosCursos values(9,'2014-04-05','8:00','12:00');
insert into HorariosCursos values(9,'2014-04-12','8:00','12:00');

insert into CostosCursos values(9,1,300,3);
 
--- Ensamblador 


insert into ProgramacionCursos values(4,10,'2014-03-31');
insert into FechasCursos values(10,'2014-03-31',2,10,10);
insert into HorariosCursos values(10,'2014-03-31','13:30','15:30');
insert into HorariosCursos values(10,'2014-04-02','13:30','15:30');
insert into HorariosCursos values(10,'2014-04-03','13:30','15:30');
insert into HorariosCursos values(10,'2014-04-04','13:30','15:30');


insert into HorariosCursos values(10,'2014-04-07','13:30','15:30');
insert into HorariosCursos values(10,'2014-04-09','13:30','15:30');
insert into HorariosCursos values(10,'2014-04-10','13:30','15:30');
insert into HorariosCursos values(10,'2014-04-11','13:30','15:30');




insert into CostosCursos values(10,1,350,4);
