Proceso MenuCitas
	Definir nombre,apellido,celular,email,edad,hora,fecha,dia,cancelar Como Caracter;
	Definir op,cod Como Entero;
	Definir band,band1 Como Logico;
	Definir usuario,contrasena Como Caracter;
	band <- falso;
	band1 <- falso;
	Escribir 'Dame un usuario: ';
	Leer usuario;
	Escribir ' Dame una contrasena: ';
	Leer contrasena;
	Si usuario=='Empleado' Y contrasena=='1234abc' Entonces
		Escribir ' Los datos son correctos';
		Repetir
			Escribir 'Menu de citas';
			Escribir '1. Agregar cliente';
			Escribir ' 2. Ver datos del cliente';
			Escribir '3. Editar cliente';
			Escribir '4. Agendar cita';
			Escribir '5. Ver datos de cita';
			Escribir '6. Cancelar cita';
			Escribir '7. Borrar cliente';
			Escribir '8. Ver datos de administrador';
			Escribir '9. Salir';
			Leer op;
			Segun op  Hacer
				1:
					AgregarCliente(); // Llamando a la funcion AgregarCliente()
					band1 <- Verdadero;
				2:
					Si band1 Entonces
						LeerDatos();
					SiNo
						Escribir 'Todavia no has ingresado ningun cliente.';
					FinSi
				3:
					Si band1 Entonces
						EditarDatos();
					SiNo
						Escribir 'No has ingresado ningun cliente.';
					FinSi
				4:
					AgendarCita();
					band <- Verdadero;
				5:
					Si band Entonces
						DatosCita();
					SiNo
						Escribir 'La cita no ha sido agendada';
					FinSi
				6:
					Si band Entonces
						Escribir 'Cita cancelada';
						CancelarCita();
						band <- falso;
					SiNo
						Escribir 'La cita no ha sido agendada';
					FinSi
				7:
					Escribir 'Datos del cliente borrados. ';
					band <- falso;
					band1 <- falso;
				8:
					Escribir 'usuario: Empleado';
					Escribir 'Contrasena: 1234abc';
				9:
					Escribir ' Gracias por usar el sistema de citas';
				De Otro Modo:
					Escribir 'Opcion invalida, seleccione de nuevo.';
			FinSegun
		Hasta Que opcion=9
	SiNo
		Escribir 'Los datos son incorrectos. Sistema detenido.';
	FinSi
FinProceso

SubProceso AgregarCliente()
	Escribir 'Agregar cliente';
	Escribir 'Nombre: ';
	Leer nombre;
	Escribir 'Apellido: ';
	Leer apellido;
	Escribir 'Número de celular: ';
	Leer celular;
	Escribir 'Email: ';
	Escribir 'El código de cliente generado es: ',cod;
FinSubProceso

SubProceso LeerDatos()
	Escribir ' Nombre: ',nombre;
	Escribir ' Apellido: ',apellido;
	Escribir ' Numero de celular:',celular;
	Escribir ' Email: ',email;
	Escribir ' Edad:',edad;
	Escribir ' cod: ',cod;
FinSubProceso

SubProceso EditarDatos()
	Escribir 'Ingrese los nuevos datos del cliente: ';
	Escribir ' Nombre: ';
	Leer nombre;
	Escribir ' Apellido: ';
	Leer apellido;
	Escribir 'numero de celular: ';
	Leer celular;
	Escribir ' Email: ';
	Leer email;
	Escribir ' Edad: ';
	Leer edad;
	Escribir ' Cliente editado exitosamente. ';
FinSubProceso

SubProceso AgendarCita()
	Escribir ' Agendar cita del cliente. ';
	Escribir ' Hora de la cita: ';
	Leer hora;
	Escribir ' Fecha en que desea realizar la cita: ';
	Leer fecha;
	Escribir 'Tu cita fue agendada con empleado';
FinSubProceso

SubProceso DatosCita()
	Escribir ' hora: ',hora;
	Escribir ' Fecha : ',fecha;
	Escribir 'Tu cita fue agendada con empleado';
FinSubProceso

SubProceso CancelarCita()
	fecha <- '';
	hora <- '';
	lugar <- '';
FinSubProceso
