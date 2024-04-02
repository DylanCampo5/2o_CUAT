# PR1. PRINCIPIO DE COMPUTADORES.
# Autor: Dylan Gonzalo Campo Bedoya
# Fecha ultima modificacion:

	.data

titulo:		.asciiz "\nPR1: Principio de computadores.\n"
peticion:	.asciiz "\nIntroduzca maximo error permitido: "
caderr:		.asciiz "\nError: el dato introducido debe cumplir 0.00001 <= dato < 1\n"
cade:		.asciiz "\nNumero e: "
cadent:		.asciiz "\nNumero de terminos: "
cadefin:	.asciiz "\nPR1: Fin del programa.\n"
var:		.double	1.0

	.text

main:	
	# Asignación de valores que vamos a usar 
	# $f20 ---> error
	# $f4 ---> e
	# $f5 ---> fact
	# $f6 ---> numterminos
	# $f7 ---> ultimo_termino

	# Sacamos la cadena del titulo y la peticion del error
	li 	$v0, 4
	la 	$a0, titulo
	syscall

	do_while:
		# Sacamos la cadena que nos pregunta por el error permitido
		li 		$v0, 4
		la 		$a0, peticion
		syscall

		# Para inicializar la var error
		li.s	$v0, 7
		syscall
		mov.d 	$f12, $v0

		if: 
			# Comprueba si error es <= 0.00001 y se va a if_modulo, o si no, se va directamente al fin
			ble $f20, 0.00001, if_then
			b 	if_modulo
		if_modulo:
			# Comprueba si el error > 1
			bgt	$f20, 1, if_then
			b 	fin_if
		if_then:
			# Sacamos la cadena para que nos meta otro valor
			li 	$v0, 4
			la 	$a0, caderr
			syscall
		fin_if: #Final del bucle if

		b 	fin
	fin_dowhile:

	# Meto el valor de var a puro registro temporal para distinto para poder tranajar con ellos
	l.s 	$f4, var 
	l.s 	$f5, var
	l.s 	$f6, var
	l.s 	$f7, var

	# El while
	while:
		bge	$f7, $f20, while_then
		b 	fin_while
	while_then:
		mul.s 	$f5, $f5, $f6
		div.s 	$f7, var, $f5
		mul.s 	$f4, $f4, $f7
		add.s 	$f6, $f6, var
	fin_while:

	# Sacamos la cadena de "Número e: "
	li 	$v0, 4
	la 	$a0, cade
	syscall

	# Sacamos la cadena "Número de terminos es: "
	li 	$v0, 4
	la 	$a0, cadent
	syscall

	# Hacemos para que nos muestre por pantalla la solucion de nuestro e
	li 		$v0, 2
	mov.s 	$f12, $f4
	syscall

	# Sacamos la cadena del final del rpograma
	li 	$v0, 4
	la 	$a0, cadefin
	syscall

	# Terminamos el programa
	li 	$v0, 10
	syscall



