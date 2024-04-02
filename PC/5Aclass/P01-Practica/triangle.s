

#include <iostream>
#
	.data
numeros:    	.asciiz "Dime 3 números que serán los lados de mi triángulo: \n"
Triangulo:  	.asciiz "Tu triángulo es: "
Iso:	        .asciiz "Isósceles"
Esca:	        .asciiz "Escaleno"
Equi:	        .asciiz "Equilatero"
No:	            .asciiz "No sirve tu triángulo, la suma de dos de sus lados es menos o igual al tercer lado"
Acabado:	        .asciiz "Termina el programa.\n"

	.text

#int main () {
main:
#  int a, b, c;
#  std::cin >> a >> b >> c;

    li      $v0, 4
    la      $a0, numeros
    syscall

    li      $v0, 7
    syscall
    mov.d   $f20, $f0   # Número a

    li      $v0, 7
    syscall
    mov.d   $f22, $f0   # Número b

    li      $v0, 7
    syscall
    mov.d   $f24, $f0   # Número c
#  
#  if (a == b) {
    if:
        c.eq.d  $f20, $f22
        bc1f    else
#    if (b == c)
        if2:
            c.eq.d  $f22, $f24
            bc1f    else2
#      std::cout << "equi"<< std::endl;
            li      $v0, 4
            la      $a0, Equi
            syscall
            j   FIN
#    else
        else2:
#      std::cout << "iso" << std::endl;
            li      $v0, 4
            la      $a0, Iso
            syscall
            j   FIN
#  }
#
#  else {
    else:
#    if (a == c)
        if3:
            c.eq.d  $f20, $f24
            bc1f    if4
#      std::cout << "iso" << std::endl;
            li      $v0, 4
            la      $a0, Iso
            syscall
            j   FIN
#    if (a != c) {
        if4:
            c.eq.d  $f20, $f24
            bc1t    if5
#      if (a + b <= c)
            elif0:
                add.d   $f30, $f20, $f22
                c.le.d  $f30, $f24
                bc1f    elif
#        std::cout << "NO" << std::endl;
                li      $v0, 4
                la      $a0, No
                syscall
                j   FIN
#      else if (a + c <= b)
            elif:
                add.d   $f30, $f20, $f24
                c.le.d  $f30, $f22
                bc1f    elif2
#        std::cout << "NO" << std::endl;
                li      $v0, 4
                la      $a0, No
                syscall
                j   FIN
#      else if (c + b <= a)
            elif2:
                add.d   $f30, $f22, $f24
                c.le.d  $f30, $f20
                bc1f    elif3
#        std::cout << "NO" << std::endl;
                li      $v0, 4
                la      $a0, No
                syscall
                j   FIN
#      else if (c != b)
            elif3:
                c.eq.d  $f24, $f22
                bc1t    if5
#        std::cout << "Escaleno" << std::endl;
                li      $v0, 4
                la      $a0, Esca
                syscall
                j   FIN
#    }
#    if (b == c) {
        if5:
            c.eq.d  $f22, $f24
            bc1f    FIN
#      std::cout << "iso" << std::endl;
            li      $v0, 4
            la      $a0, Esca
            syscall
            j   FIN
#    }
#  }
    Acabado:
        li  $v0, 4
        la  $a0, FIN
        syscall

        li  $v0, 10
        syscall
#  return 0;
#}      
