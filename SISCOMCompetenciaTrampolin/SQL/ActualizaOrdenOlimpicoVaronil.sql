--Piso
update  aparatoscompetencia set ordenolimpico=1  
where idaparato=1 and 
      idtipocompetencia=1;

--Caballo con arzones
update  aparatoscompetencia set ordenolimpico=2  
where idaparato=6 and 
      idtipocompetencia=1;

--Anillos
update  aparatoscompetencia set ordenolimpico=3  
where idaparato=5 and 
      idtipocompetencia=1;
--Salto Caballo
update  aparatoscompetencia set ordenolimpico=4  
where idaparato=2 and 
      idtipocompetencia=1;




-- Barras Paralelas
update  aparatoscompetencia set ordenolimpico=5  
where idaparato=8 and 
      idtipocompetencia=1;

-- Barra Fija 
update  aparatoscompetencia set ordenolimpico=6  
where idaparato=7 and 
      idtipocompetencia=1;
