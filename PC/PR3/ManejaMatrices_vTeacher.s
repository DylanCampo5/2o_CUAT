#// Solución PR3 curso 23-24
#// Manejo de matrices con funciones
#
#
#typedef struct {
#  int nFil;
nFil = 0	# El desplazamiento al campo dentro de la estructura
#  int nCol;
nCol = 4	# El desplazamiento al campo dentro de la estructura
#  float elementos[];
elementos = 8	# El desplazamiento al campo dentro de la estructura
#} structMat;
#

sizeF = 4	# Numero de bytes de un float
LF = 10		# Caracter salto de línea
	.data
#structMat mat1 {
#  6,
#  6,
#  {
#    11.11, 12.12, 13.13, 14.14, 15.15, 16.16,
#    21.21, 22.22, 23.23, 24.24, 25.25, 26.26,
#    31.31, 32.32, 33.33, 34.34, 35.35, 36.36,
#    41.41, 42.42, 43.43, 44.44, 45.45, 46.46,
#    51.51, 52.52, 53.53, 54.54, 55.55, 56.56,
#    61.61, 62.62, 63.63, 64.64, 65.65, 66.66
#  }
#};
mat1:	.word	6
	.word	6
	.float	11.11, 12.12, 13.13, 14.14, 15.15, 16.16,
	.float	21.21, 22.22, 23.23, 24.24, 25.25, 26.26,
	.float	31.31, 32.32, 33.33, 34.34, 35.35, 36.36,
	.float	41.41, 42.42, 43.43, 44.44, 45.45, 46.46,
	.float	51.51, 52.52, 53.53, 54.54, 55.55, 56.56,
	.float	61.61, 62.62, 63.63, 64.64, 65.65, 66.66

#structMat mat2 {
#  7,
#  10,
#  {
#    -36.886, -58.201,  78.671,  19.092, -50.781,  33.961, -59.511, 12.347,  57.306,  -1.938,
#    -86.858, -81.852,  54.623, -22.574,  88.217,  64.374,  52.312, 47.918, -83.549,  19.041,
#     4.255, -36.842,  82.526,  27.394,  56.527,  39.448,  18.429, 97.057,  76.933,  14.583,
#    67.79 ,  -9.861, -96.191,  32.369, -18.494, -43.392,  39.857, 80.686, -36.87 , -17.786,
#    30.073,  89.938,  -6.889,  64.601, -85.018,  70.559, -48.853, -62.627, -60.147,  -5.524,
#    84.323, -51.718,  93.127, -10.757,  32.119,  98.214,  69.471, 73.814,   3.724,  57.208,
#    -41.528, -17.458, -64.226, -71.297, -98.745,   7.095, -79.112, 33.819,  63.531, -96.181
#  }
#};
mat2:	.word	7
	.word	10
	.float	-36.886, -58.201,  78.671,  19.092, -50.781,  33.961, -59.511, 12.347,  57.306,  -1.938,
	.float	-86.858, -81.852,  54.623, -22.574,  88.217,  64.374,  52.312, 47.918, -83.549,  19.041,
	.float	4.255, -36.842,  82.526,  27.394,  56.527,  39.448,  18.429, 97.057,  76.933,  14.583,
	.float	67.79 ,  -9.861, -96.191,  32.369, -18.494, -43.392,  39.857, 80.686, -36.87 , -17.786,
	.float	30.073,  89.938,  -6.889,  64.601, -85.018,  70.559, -48.853, -62.627, -60.147,  -5.524,
	.float	84.323, -51.718,  93.127, -10.757,  32.119,  98.214,  69.471, 73.814,   3.724,  57.208,
	.float	-41.528, -17.458, -64.226, -71.297, -98.745,   7.095, -79.112, 33.819,  63.531, -96.181

# structMat mat3 {
#   1,
#   8,
#   {
#     -36.52,  35.3 ,  79.05, -58.69, -55.23, -19.44, -88.63, -93.61
#   }
# };
mat3:	.word	1
	.word	8
	.float	-36.52,  35.3 ,  79.05, -58.69, -55.23, -19.44, -88.63, -93.61

# structMat mat4 {
#   16,
#   1,
#   { -90.57, -65.11, -58.21, -73.23, -89.38, -79.25,  16.82,  66.3 ,
#     -96.14, -97.16, -24.66,   5.27, -33.5 , -13.09,  27.13, -74.83 }
# };
mat4:	.word	16
	.word	1
	.float	-90.57, -65.11, -58.21, -73.23, -89.38, -79.25,  16.82,  66.3
	.float	-96.14, -97.16, -24.66,   5.27, -33.5 , -13.09,  27.13, -74.83

# structMat mat5 {
#   1,
#   1,
#   { 78.98 }
# };
mat5:	.word	1
	.word	1
	.float	78.98

# structMat mat6 {
#   0,
#   0,
#   { 0 }
# };
mat6:	.word	0
	.word	0
	.float	0.0

#float infinito = INFINITY;
infinito:	.word	0x7F800000

# Cadenas de caracteres
str_titulo:		.asciiz	"\nComienza programa manejo matrices con funciones\n"
str_menu:		.ascii	"(0) Terminar el programa\n"
				.ascii	"(1) Cambiar la matriz de trabajo\n"
				.ascii	"(3) Cambiar el valor de un elemento\n"
				.ascii	"(4) Intercambiar un elemento con su opuesto\n"
				.ascii	"(7) Encontrar el minimo\n"
				.asciiz	"\nIntroduce opción elegida: "
str_errorOpc:	.asciiz	"Error: opcion incorrecta\n"
str_termina:	.asciiz	"\nTermina el programa\n"
str_elijeMat:	.asciiz	"\nElije la matriz de trabajo (1..6): "
str_numMatMal:	.asciiz	"Numero de matriz de trabajo incorrecto\n"
str_errorFil:	.asciiz	"Error: dimension incorrecta.  Numero de fila incorrecto\n"
str_errorCol:	.asciiz	"Error: dimension incorrecta.  Numero de columna incorrecto\n"
str_indFila:	.asciiz	"\nIndice de fila: "
str_indCol:		.asciiz	"Indice de columna: "
str_nuevoValor:	.asciiz	"Nuevo valor para el elemento: "
str_valMin:		.asciiz	"\nEl valor minimo esta en ("
str_conValor:	.asciiz	") con valor "

str_matTiene:	.asciiz	"\n\nLa matriz tiene dimension "
msg_matriz: 	.asciiz "\nLa matriz es "
msg_x:      	.asciiz "x"
separador:  	.asciiz " "
newline:    	.asciiz "\n"
# ---------------------------------------------------------------------------------------------------------------------------------------------------------
# ---------------------------------------------------------------------------------------------------------------------------------------------------------
    .text

print_mat:
		#Para entero a0, a1, a2, a3
		#Para float f12, f14, f16
		#Tutoría academica número 6

		li $v0, 4
		la $a0, str_matTiene  # Imprimir mensaje de matriz
		syscall

		lw $t0, 0($s0)                                         # $t0 número de filas
		lw $t1, 4($s0)  									   # $t1 número de columnas
		move $s3, $t0		# $t0 número de filas
		move $s6, $t1		# $t1 número de columnas

		li $v0, 1		
    	move $a0, $t0   # Número de filas
    	syscall

		li $v0, 4
		la $a0, msg_x	# x
		syscall

		li $v0, 1
    	move $a0, $t1   # Número de columnas
    	syscall

		li $v0, 4
		la $a0, newline
		syscall 				

    	mul $s4, $s6, sizeF # ncol * size = size_salto
    	mul $s5, $s3, $s4 # nfil * size_salto = size_matriz
		
		la $t7, elementos # Obtener la dirección base de la matriz
		li $t1, 0 # Inicializar contador de fila

		# addi $sp, -28
		# sw $s0, 0($sp)
		# sw $s0, 4($sp)
		# sw $s0, 8($sp)
		mul $s6, $s6, sizeF
		mul $s3, $s3, $s4

		For1: 
			bge $t1, $s3, Fin_For1
			li $t3, 0 # Inicializar contador de columna
			# std::cout << std::endl;
			li $v0, 4
			la $a0, newline
			syscall
			# for (int j = 0; j < ncol; j++) {
			For2:
				bge $t3, $s6, Fin_For2
				addu $t2, $t1, $t3 
				addu $t2, $t2, $s0 
				addu $t2, $t2, 8		# (IndFil * nCol + IndCol) * sizeF
				# std::cout << matriz[i][j] << " ";
				li $v0, 2
				l.s $f12, 0($t2)
				syscall

				li $v0, 4
				la $a0, separador
				syscall
				
				addu $t3, $t3, sizeF # j++
				b For2
			# }
			Fin_For2:
			addu $t1, $t1, $s4 # i++
			b For1
			# }
		Fin_For1:
		# lw $s0, 0($sp)
		# lw $s0, 4($sp)
		# lw $s0, 8($sp)
		# addi $sp, -28
print_mat_fin: jr $ra

change_elto:
	# $t0 => En donde esta la mat1
	# $t1 => número de filas (nFil)																	
	# $t2 => número de columnas (nCol)																		
	# $t3 => elementos
	# $t4 => IndFil
	# $t5 => IndCol
	# $t6 => Nuevo valor
	# $t7 => La dirección en la que se realizará en cambio   

	# $s5 => Nuevo valor			$s2 => IndFil			$s0 => En donde esta la mat1			$s4 => IndCol
		
	lw $t1, 0($s0)   				
	lw $t2, 4($s0)
	# sub $t1, $t1, 1
	# sub $t2, $t2, 1		
	addi $t3, $s0, 8   

	# Para ir a buscar la pos de una wea concreta con la formulika aquella
	mul $t7, $s2, $t2		# $t7 = IndFIl * nCol
	add $t7, $t7, $s4		# 	  = + IndCol
	mul $t7, $t7, sizeF		#     = * sizeF
	add $t7, $t7, $t3		# [ (IndFil * nCol + IndCol) * sizeF ]
				
	s.s $f20, 0($t7)

change_elto_fin: jr $ra

swap:
	lwc1 $f4, 0($a0)
	lwc1 $f6, 0($a1)

	swc1 $f6, 0($a0)
	swc1 $f4, 0($a1)

swap_fin: jr $ra

intercambia:
	# $t0 => En donde esta la mat1
	# $t1 => número de filas (nFil)									
	# $t2 => número de columnas (nCol)								
	# $t3 => elementos
	# $t4 => IndFil
	# $t5 => IndCol
	# $t6 => Pos de los ind
	# $t7 => Pos opuesto
	# $t1 => Para un restika										

	# $s2 => IndFil			# $s4 => IndCol			# $s0 => En donde esta la mat1

	lw $t1, 0($s0)                                         
	lw $t2, 4($s0)										 
	addi $t3, $s0, 8										   
		
	#Para ir a buscar la pos de una wea concreta con la formulika aquella
	mul $t6, $s2, $t2			# $t6 = IndF * nCol     
	addu $t6, $t6, $s4			# $t6 = $t6 + IndCol 
	mul $t6, $t6, sizeF     	# $t6 = $t6 * Tmñ_Int	  
	addu $t6, $t6, $t3			# $t6 = $t6 + (matX + 8)

	sub $t7, $t1, $s2		# nFil - IndFil
	sub $t7, $t7, 1			# - 1
	mul $t7, $t7, $t2		# * nCol
	sub $t1, $t2, $s4		# nCol - IndCol
	sub $t1, $t1, 1			# - 1
	addu $t7, $t7, $t1		# $t7 = $t7 + $t1
	mul $t7, $t7, sizeF 	# $t7 * sizeF
	addu $t7, $t7, $t3		# CON LA DIRECCION DE MEMORIA

	#LLAMAMOS A LA FUKIN FUNCION SWAP
	addi $sp, $sp, -4
	sw $ra, 0($sp)

	move $a0, $t6
	move $a1, $t7
	jal swap

	lw $ra, 0($sp)
	addi $sp, $sp, 4
	
intercambia_fin: jr $ra

find_min:
	# $s0 = mat
	# $t0 => nFil
	# $t1 => nCol
	# $s3 => elementos
	# $a0 => infinito
	# $t4 => infinito
	# $t6 => fmin
	# $t7 => cmin
	# $t2 => f
	# $t3 => c
	# $t5 => valor

	# $t0 = mat
	# $t1 => nFil
	# $t2 => nCol
	# $t3 => elementos
	# $a0 => infinito
	# $t4 => infinito
	# $t5 => fmin
	# $t6 => cmin
	# $t7 => f
	# $   => c
	# $   => valor

	lw $t0, 0($s0)              # $t0 número de filas
	lw $t1, 4($s0)				# $t1 número de columnas
	addi $s3, $s0, 8    		# Como antes, si uso la var "elementos" de arriba, pos tendremos lo mismo

	la $a0, infinito
	l.s $f12, 0($a0)			# min

	li $t6, -1 				# Inicializar el fmin
	li $t7, -1					# Inicializar el cmin

	li $t2, 0						# Inicializar la f = 0
	for:
		add $t2, $t2, 1
		bge $t2, $t0, fores_fin			# Si f > nFil, se va
		li $t3, 0						# Inicializar la c = 0
		for2:
			add $t3, $t3, 1
			bge $t3, $t1, for			# Si c > nCol, se va

			mul $f4, $t2, $t1 			# valor
			add $f4, $f4, $t3 
			mul $f4, $f4, sizeF
			add $f4, $f4, $s3

			# (IndFil * nCol + IndCol) * sizeF

			ifMin:
				bge $f4, $t4, for2		# min > valor = se va
				move $t4, $f4			# min = valor;
				move $t6, $t2			# fmin = f;
				move $t7, $t3			# cmin = c;
				# $f0, $v0, $v1
				b for2
	fores_fin:
		jr $ra

find_min_fin:

#mainmainmainmainmainmainmainmainmainmainmainmainmainmainmainmainmainmainmainmainmainmainmainmainmainmainmainmainmainmainmainmainmainmainmainmain

main:

	# std::cout << "\nPráctica PR3 de Principios de Computadores. Matrices.\n";
	li $v0, 4
	la $a0, str_titulo
	syscall

	# Inicializo en $a0 la mat1 y de paso voy para la f(x) print_mat
	Mat1:
		la $a0, mat1
		move $s0, $a0
	Matriz:
		jal print_mat

	li $v0, 4
	la $a0, newline
	syscall
	li $v0, 4
	la $a0, newline
	syscall

	Menu:
		li $v0, 4
		la $a0, str_menu
		syscall

		# std::cin >> opcion;
		li $v0, 5
		syscall
		move $s1, $v0 								# $s1 = opcion

		if_negativo:
			bltz $s1, if_NumMal 

			if_Num0:
				beq $s1, 0, Num0_then
				b Num0_fin
				Num0_then:
					b FINIQUITO   						
					# Si el número que pone el user por pantalla es 0, acabará el programa
			Num0_fin:

			if_Num1:
				beq $s1, 1, Num1_then
				b Num1_fin
				Num1_then:
					b EleccionMatricial_main
					# Si el número que pone el user por pantalla es 1, cambiará la matriz que puede usar
			Num1_fin:

			if_Num3:
				beq $s1, 3, Num3_then
				b Num3_fin
				Num3_then:   
					b Opciones
					# Si el número que pone el user por pantalla es 3, podrás cambiar el valor de un elemento
			Num3_fin:

			if_Num4:
				beq $s1, 4, Num4_then
				b Num4_fin
				Num4_then:   
					b Opciones
					# Si el número que pone el user por pantalla es 5, podrás ver el intercambia 
			Num4_fin:

			if_Num7:
				beq $s1, 7, Num7_then
				b Num7_fin
				Num7_then:
					# jal find_min   
					b Mat1
					# Si el número que pone el user por pantalla es 7, podrás encontrar el minimo de la fila que gustes
			Num7_fin:

			if_NumMal:
				li $v0, 4
				la $a0, str_errorOpc
				syscall
				b Mat1
				# Si el número que pone el user por pantalla es 7, podrás encontrar el minimo de la fila que gustes
			NumMal_fin:
		if_negativo_fin:

	Menu_fin:

	EleccionMatricial_main:
		li $v0, 4
		la $a0, str_elijeMat
		syscall

		#std::cin >> matT;
		li $v0, 5
		syscall
		move $t1, $v0       # $s1 = matT

		# if (matT == 1) {
		if_M1:
			beq $t1, 1, if_M1_then
			b 	if_M2
			if_M1_then:
				la $s0, mat1
				b Matriz

		if_M2:
			beq $t1, 2, if_M2_then
			b 	if_M3
			if_M2_then:
				la $s0, mat2
				b Matriz

		if_M3:
			beq $t1, 3, if_M3_then
			b 	if_M4
			if_M3_then:
				la $s0, mat3
				b Matriz

		if_M4:
			beq $t1, 4, if_M4_then
			b 	if_M5
			if_M4_then:
				la $s0, mat4
				b Matriz

		if_M5:
			beq $t1, 5, if_M5_then
			b 	if_M6
			if_M5_then:
				la $s0, mat5
				b Matriz

		if_M6:
			beq $t1, 6, if_M6_then
			b 	error
			if_M6_then:
				la $s0, mat6
				b Matriz
		error:
			li $v0, 4
			la $a0, str_numMatMal
			syscall
			b Mat1

	EleccionMatricial_main_fin:

	Opciones:
		lw $t0, 0($s0)                          # $t0 número de filas 				
		lw $t1, 4($s0)							# $t1 número de columnas			

		li $v0, 4
		la $a0, str_indFila						# Nos pregunta el indice de columna
		syscall
		
		li $v0, 5
		syscall
		move $s2, $v0  							# Indice de fila (i)
		# sub $s2, $s2, 1

		sub $t0, $t0, 1
		if_Fil: 
			bgt $s2, $t0, Mal_Fila   			# Si IndDil > nFil = Mal_Fila
			bltz $s2, Mal_Fila
		add $t0, $t0, 1

		li $v0, 4
		la $a0, str_indCol						# Nos pregunta el indice de columna
		syscall

		li $v0, 5
		syscall
		move $s4, $v0  							# Indice de columna (j) 
		# sub $s4, $s4, 1

		sub $t1, $t1, 1
		if_Col:
			bgt $s4, $t1, Mal_Columna   		# Si IndCol > nCol = Mal_Col
			bltz $s4, Mal_Columna
			add $t1, $t1, 1
			b 	if3

			Mal_Fila:
				li $v0, 4
				la $a0, str_errorFil
				syscall
				b Matriz
			Mal_Columna:
				li $v0, 4
				la $a0, str_errorCol
				syscall 
				b Matriz

		if3: 
			bne $s1, 3, if4			# If para saber que es el tercero

			li $v0, 4
			la $a0, str_nuevoValor				# Pregunta al user que valor usar
			syscall

			li $v0, 6
			syscall
			mov.s $f20, $f0   					# Nuevo valor de user lo meto en $f20

			jal change_elto
			b Matriz

		if4:
			bne $s1, 4, Opciones_fin			# If para saber que es el cuarto

			jal intercambia
			b Matriz

	Opciones_fin:

FINIQUITO:

	li $v0, 4
	la $a0, str_termina
	syscall

    li $v0, 10
    syscall