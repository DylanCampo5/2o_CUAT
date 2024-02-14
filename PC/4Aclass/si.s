n $s0
j $s1

	.data
str_titulo:		.asciiz "Programa que encuentra un primo\n"
str_introduzca:		.asciiz "\nIntroduzca numero a estandar: "
str_estdivisible: 	.asciiz "El numero es divisible por: "
str_salto: 		.asciiz "\n"
str_primo: 		.asciiz "Tu numero SI es primo"
str_termina: 		.asciiz "Termina el programa\n"

	li	$v0, 4
	la 	$a0, str_titulo
	syscall
	
	do_while:
		li      $v0, 4                                                                              
        	la      $a0, str_introduzca                                                                     
        	syscall	

		li	$v0, 5
		syscall
		move 	$s0, $v0

		if_break:
			bnez	$s0, if_break_fin
			b 	do_while_fin
		if_break_fin:
	
	do_while_condition:
		bnez $s0, do_while
	do_while_fin:
	
	
	
	li 	$v0, 4
	la 	$a0, str_termina
	syscall
	
	li 	$v0, 10
	syscall
