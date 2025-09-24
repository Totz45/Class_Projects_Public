 AREA   myData1, DATA, READWRITE  ; your variables and arrays are defined here 
matrix DCD 11, 12, 13, 21, 22, 23, 31, 32, 33, 41, 42, 43
matrixT DCD 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
Column DCD 3
Row DCD 4
	AREA    main, CODE, READONLY		
	EXPORT	__main				; make __main visible to linker
	ENTRY			  

__main	PROC
 LDR r0, =matrix
 LDR r9, =matrixT
 LDR r3, =Row
 LDR r1, [r3]
 LDR r3, =column
 LDR r2, [r3]
 MOVS r3, #0
 B check_i
loop_i MOV r4, #0
 B check_j
loop_j MUL r6, r3, r2
 ADD r6, r0, r6, LSL #2
 LDR r5, [r6, r4, LSL #2]
 
 MUL r7, r4, r1
 ADD r7, r9, r7, LSL #2
 STR r5, [r7, r3, LSL #2]
 
 ADDS r4, r4, #1
check_j CMP r4, r2
 BLT loop_j
check_i CMP r3, r1
 BLT loop_i
 
stop 	B 		stop     		; dead loop & program hangs here
	ENDP
							
 ; if you have more functions put them here  
	
	END