Proceso Algoritmo_citas
	Definir nombre como cadena;
	Definir apellido como cadena;
	Definir cedula como cadena;
	Definir edad como entero;
	Definir mes, dias como entero;
	Definir hora como cadena;
	Definir num_celular como entero;
	Definir email como cadena;
	
	
	Escribir "Ingrese el nombre: ";
	Leer nombre;
	Escribir "Ingrese el apellido: ";
	Leer apellido;
	Escribir "Ingrese su numero de cedula: ";
	leer cedula;
    Escribir "Ingresa la edad: ";
	Leer edad;
	Escribir "Ingrese su numero de celular: ";
	Leer num_celular;
	Escribir "Ingrese su email: ";
	Leer email;
	Escribir "Ingrese el numero correspondiente al mes del año corriente en el que desea realizar la cita: ";
	Leer mes;
	Escribir " Ingrese la hora en que sea realizar la cita: ";
	Leer hora;
	
	//edad mayor a 15
	Si edad >=15 Entonces
		Escribir " Su edad es aceptada";
	SiNo
		Escribir " Su edad no es aceptada";
	FinSi
	
	//tipo de mes
	Segun mes Hacer
		1:
			Escribir "Enero";
		2:
			Escribir "Febrero";
		3:
			Escribir "Marzo";
		4:
			Escribir "Abril";
		5:
			Escribir "Mayo";
		6:
			Escribir "Junio";		
		7:
			Escribir "Julio";
		8:
			Escribir "Agosto";
		9:
			Escribir "Septiembre";		
		10:
			Escribir "Octubre";
		11:
			Escribir "Noviembre";
		12:
			Escribir "Diciembre";		
			
		De Otro Modo:
			Escribir " Ingresó un número fuera del rango";
			
			
	FinSegun
	
	Definir cod Como Entero;
	cod <- Aleatorio(0, 9999);
	Escribir "El aleatorio es " , cod;
	
	
FinProceso
