Proceso MenuCitas
	Definir cod, nombre, apellido, celular, email, edad, hora, fecha, dia, cancelar como cadena;
	Definir opcion como entero;
	Repetir
		escribir "Menu de citas";
		escribir "1. Agregar cliente";
		escribir "2. Generar codigo de cliente";
		escribir"3.Ver datos del cliente";
		escribir "4. Editar cliente";
		escribir "5. Agendar cita";
		escribir "6. Ver datos de cita";
		escribir "7. cancelar cita";
		escribir "8.elegir empleados";
		escribir "9. Ingreso del admi";
		escribir "10. salir";
		Leer opcion;
		
		
		Segun opcion hacer 
			1:
				escribir "Agregar cliente";
				escribir "Nombre: ";
				leer nombre;
				escribir " Apellido: ";
				leer apellido;
				Escribir "numero de celular: ";
				leer celular;
				Escribir " Email: ";
				leer email;
				escribir "edad: ";
				leer edad;
				escribir " Cliente agregado exitosamente.";
			2:
				cod = " 12345678 + celular " ;
				escribir " El codigo de cliente generado es : ", cod;
			3: 
				escribir " Nombre: ", nombre;
				escribir " Apellido: ", apellido;
				escribir " Numero de celular:", celular;
				escribir " Email: ", email;
				escribir " Edad:", edad;
				escribir " cod: ", cod;
				
			4:
				escribir "Ingrese los nuevos datos del cliente: ";
				escribir " Nombre: ";
				Leer nombre;
				escribir " Apellido: ";
				Leer apellido;
				escribir "numero de celular: ";
				leer celular;
				escribir " Email: ";
				leer email;
				escribir " Edad: ";
				leer edad;
				escribir " Cliente editado exitosamente. ";
				
			5:
				escribir " Agendar cita del cliente. ";
				Escribir " Hora de la cita: ";
				Leer hora;
				escribir " Fecha en que desea realizar la cita: ";
				leer fecha;
				
				
			6:
				escribir " hora: ", hora;
				escribir " Fecha : ", fecha;
				
			7:
				escribir " Deseo cancelar la cita";
				leer cancelar;
			8:
				escribir " Elegir empleados: ";
				
			9:
				escribir " Ingresar como admi o empleado: ";
				
				
			10:
				escribir " Gracias por usar el sistema de citas";
			De Otro Modo:
				escribir "Opcion invalida, seleccione de nuevo.";
		FinSegun
		Hasta que opcion = 10
		
		

	
FinProceso
