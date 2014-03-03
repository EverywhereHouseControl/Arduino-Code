Este sketch prueba el manejo de los módulos de IR y control de luces.

-Funcionamiento
	Recibe una cadena de caracteres del puerto serie como entrada, con el siguiente formato:
	+ El último carácter indica la funcionalidad que se va a usar (0-->luces, 1-->IR)
	+ El resto componen el mensaje que se le quiera pasar a dicha funcionalidad
	
	Devuelve
	+ "-1" si el ultimo carácter no esta asignado a ninguna funcionalidad
	+ La salida del módulo en cuestion en otro caso

-Ejemplo
	+ Mensaje "00"	-->		Cambiar el estado de las luces
	+ Mensaje "31"	-->		Enviar código de television LG, canal 3
	+ Mensaje "70"	-->		Error, mensaje no válido
	+ Mensaje "12"	-->		Error, mensaje no válido
	