%include "./pc_io.inc"
section .data	;Datos inicializados
  message db " ",10,0

section .bss	;Datos no inicializados
  N resb 2
  hex_string   resb  8
section .text
 global _start:

_start:
;inciso a)
  mov ebx, 0x5C4B2A60
  add ebx, 0x1288685;Sumamos a ebx nuestra matricula
  mov eax,ebx;Introducimos datos en eax
  mov esi, hex_string;Todos los valores se guardaran en hex_string que estara guardado en esi
  call print_hex;Llamamos a la funcion para imprimir
  mov edx,message;;Salto de linea
  call puts

;inciso b)
  push bx;Metemos 16 bits a la pila
  call print_hex
  mov edx,message
  call puts

  ;inciso_c)
  mov al,8
  mul bl
  mov word[N],ax;Almacenamos los 2 bytes de datos con word en N
  call print_hex
  mov edx,message
  call puts

  ;inciso_d)
  inc word[N]
  mov ax,[N]
  call print_hex
  mov edx,message
  call puts

  ;inciso_e)
  mov eax,0
  mov ax,bx
  mov cl,0xFF
  div cl
  call print_hex
  mov edx,message
  call puts

  ;inciso_f)
  add byte[N],ah
  dec word[N]
  mov ax,[N]

  pushf ;mete los 32 bits mas significativos (en teoria deberian ser 16
  ;pero hubo una confusion) En esta parte las banderas del 
  ;31 al 0 estan activas puesto que hemos metido todos los bits del
  ;registro de banderas a la pila
  call print_hex 

  mov edx,message
  call puts
  pop eax ;
  call print_hex

  mov edx,message
  call puts

  pop ax;Idealmente se espera que aqui se saque la mitad de lo que habia
  ;al inicio en eax, como tal anteriormente sacamos eax del registro
  call print_hex

  mov eax, 1
  mov ebx, 0
  int 80h

print_hex:
	pushad	;Meter a la pila todos los registros de proposito general
	mov cl, 28	;CL sera el registro para desplazar
.next:
	mov ebx, eax	;Utilizamos EBX para almacenar el dato original
	shr ebx, cl 	;Desplazamos EBX a la derecha para colocar en los 4 bits mas a la derecha, los bits a analizar
	and ebx, 0xf	;Utilizamos una AND y una mascara para determinar el estado de los 4 bits menos significativos
	cmp bl, 9		;Comparamos si el resultado es 9 o menos
	jbe .menor
	add bl, 7		;Si el resultado es 10 o mas se representa con 'A-F'

.menor:
	add bl, '0'		;Convertir al valor de los caracteres ASCII
	mov byte [esi], bl
	inc esi 		;Almacenar caracter en [esi] e incrementar ESI
	sub cl, 4		;Actualizar numero de bits a desplazar
	cmp cl, 0 		;Comprobar si se deben seguir convirtiendo datos o no
	jl .print
	jmp .next
.print:
	mov edx, hex_string
	call puts
	popad
	ret




