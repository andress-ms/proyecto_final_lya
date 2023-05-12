Proceso MenuCitas
	Definir cod, nombre, apellido, celular, email, edad, hora, fecha, dia, cancelar como cadena;
	Definir opcion como entero;
	Definir usuario, contrasena como caracter;
	Definir persona1, persona2 como cadena;
	
	
	Repetir
		escribir "Menu de citas";
		escribir "1. Agregar cliente";
		escribir"2.Ver datos del cliente";
		escribir "3. Editar cliente";
		escribir "4. Agendar cita";
		escribir "5. Ver datos de cita";
		escribir "6. cancelar cita";
		escribir "7. salir";
		Leer opcion;
		
		
		Segun opcion hacer 
			1: 
				Escribir "Dame un usuario: ";
				leer usuario;
				Escribir " Dame una contrasena: ";
				Leer contrasena;
				si usuario == "Administrador" y contrasena == "1234abc" Entonces
					Escribir " Los datos son correctos";
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
					cod= "12345678910 + celular";
					escribir " El codigo de cliente generado es : ", cod;
					
				SiNo
					Escribir " Lo siento, los datos son incorrectos";
				FinSi
				
				
			2: 
				escribir " Nombre: ", nombre;
				escribir " Apellido: ", apellido;
				escribir " Numero de celular:", celular;
				escribir " Email: ", email;
				escribir " Edad:", edad;
				escribir " cod: ", cod;
				
			3:
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
				
			4:
				escribir " Agendar cita del cliente. ";
				Escribir " Hora de la cita: ";
				Leer hora;
				escribir " Fecha en que desea realizar la cita: ";
				leer fecha;
				Escribir " Elegir al manicurista de su preferencia: ";
				Escribir "Presione 1 para elegir a Cristhian.";
				Escribir "Presione 2 para elegir a Belén.";
				
				Leer opcion;
				
				Segun opcion Hacer
					1:
						Escribir "Ha elegido a Cristhian.";
					2:
						Escribir "Ha elegido a Belén.";
					De Otro Modo:
						Escribir "Opción inválida.";
				FinSegun
				
				
			5:
				escribir " hora: ", hora;
				escribir " Fecha : ", fecha;
				
			6:
				escribir " Desea cancelar la cita? (responder y/n)";
				leer cancelar;
				si cancelar == "y" Entonces
					escribir "La cita ha sido cancelada";
				sino 
					escribir "La cita no ha sido cancelada. ";
				FinSi
				
				
				
			7:
				escribir " Gracias por usar el sistema de citas";
			De Otro Modo:
				escribir "Opcion invalida, seleccione de nuevo.";
		FinSegun
		Hasta que opcion = 7
		
		

	
FinProceso
