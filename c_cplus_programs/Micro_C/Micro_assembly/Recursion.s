 AREA   myData1, DATA, READWRITE  ; your variables and arrays are defined here 
AM DCD 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12
BM DCD 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12
p DCD 3
m DCD 4
n DCD 4
CM SPACE 64
	AREA    main, CODE, READONLY		
	EXPORT	__main				; make __main visible to linker
	ENTRY			  

__main	PROC
 LDR r1, =m
 LDR r1, [r1]
 LDR r2, =p
 LDR r2, [r2]
 LDR r3, =n
 LDR r3, [r3]
 LDR r4, =AM
 LDR r5, =BM
 LDR r6, =CM
 ;edit using picture
 B check_i
loop_i MOV r8, #0
 B check_j
loop_j MOV r0, #0
	MOV r9, #0
	B check_k
loop_k MUL r10, r2, r7
 ADD r10, r4, r10, LSL #2
 LDR r10, [r10, r9, LSL #2]
 
 MUL r11, r3, r9
 ADD r11, r5, r11, LSL #2
 LDR r11, [r11, r8, LSL #2]
 
 MLA r0, r10, r11, r0
 
 ADD r9, r9, #1
check_k
	CMP r9, r2
	BLT loop_k
	
	MUL r12, r3, r7
	ADD r12, r6, r12, LSL #2
	STR r0, [r12, r8, LSL #2]
	
	ADD r8, r8, #1
check_j CMP r8, r3
 BLT loop_j
 ADD r7, r7, #1
check_i CMP r7, r1
 BLT loop_i
 
stop 	B 		stop     		; dead loop & program hangs here
	ENDP
							
 ; if you have more functions put them here  
	
	END