 AREA   myData1, DATA, READWRITE  ; your variables and arrays are defined here 
Array1_bytes 	DCB 	0x02, 0x03, 0xFE, 0xFF ;byte array
Array1_Signed_words 	DCD 0x00000000, 0x00000000, 0x00000000, 0x00000000 ;array of signed words
Array1_Unsigned_words 	DCD 0x00000000, 0x00000000, 0x00000000, 0x00000000 ;array of unsigned words
Array1_Add_words 	DCD 0x00000000, 0x00000000, 0x00000000, 0x00000000 ;array of signed + unsigned
Array1_Mul_words 	DCD 0x00000000, 0x00000000, 0x00000000, 0x00000000 ;array of unsigned * 10
Array1_Div_words 	DCD 0x00000000, 0x00000000, 0x00000000, 0x00000000 ;array of unsigned / 2

	AREA    main, CODE, READONLY		
	EXPORT	__main				; make __main visible to linker
	ENTRY			



__main	PROC
	
	LDR r0, =Array1_bytes ;put values from first array into r0
	LDR r1, =Array1_Signed_words ;put values from second array into r1
	LDR r2, =Array1_Unsigned_words ;put values from third array into r2
	LDR r3, =Array1_Add_words ;put values from fourth array into r3
	LDR r4, =Array1_Mul_words ;put values from fifth array into r4 
	LDR r5, =Array1_Div_words ;put values from sixth array into r5
	
	;load, extend unsigned, and store first element 
	LDRB r6, [r0]
	UXTB r6, r6
	STR r6, [r2], #4
	;load, extend signed, and store first element 
	LDRB r7, [r0], #1
	SXTB r7, r7
	STR r7, [r1], #4
	;add r6 and r7, store in r3 
	ADD r9, r6, r7
	STR r9, [r3], #4 
	;multiply r6 by 10, store in r4
	MOV r8, #10
	MUL r9, r6, r8
	STR r9, [r4], #4
	;divide r6 by 2, store in r5
	MOV r8, #2
	UDIV r9, r6, r8
	STR r9, [r5], #4
	;load, extend unsigned, and store second element
	LDRB r6, [r0]
	UXTB r6, r6
	STR r6, [r2], #4
	;load, extend signed, and store second element
	LDRB r7, [r0], #1
	SXTB r7, r7
	STR r7, [r1], #4
	;add r6 and r7, store in r3 
	ADD r9, r6, r7
	STR r9, [r3], #4 
	;multiply r6 by 10, store in r4
	MOV r8, #10
	MUL r9, r6, r8
	STR r9, [r4], #4
	;divide r6 by 2, store in r5
	MOV r8, #2
	UDIV r9, r6, r8
	STR r9, [r5], #4
	;load, extend unsigned, and store third element
	LDRB r6, [r0]
	UXTB r6, r6
	STR r6, [r2], #4
	;load, extend signed, and store third element
	LDRB r7, [r0], #1
	SXTB r7, r7
	STR r7, [r1], #4
	;add r6 and r7, store in r3 
	ADD r9, r6, r7
	STR r9, [r3], #4 
	;multiply r6 by 10, store in r4
	MOV r8, #10
	MUL r9, r6, r8
	STR r9, [r4], #4
	;divide r6 by 2, store in r5
	MOV r8, #2
	UDIV r9, r6, r8
	STR r9, [r5], #4
	;load, extend unsigned, and store fourth element
	LDRB r6, [r0]
	UXTB r6, r6
	STR r6, [r2], #4
	;load, extend signed, and store fourth element
	LDRB r7, [r0], #1
	SXTB r7, r7
	STR r7, [r1], #4
	;add r6 and r7, store in r3 
	ADD r9, r6, r7
	STR r9, [r3], #4 
	;multiply r6 by 10, store in r4
	MOV r8, #10
	MUL r9, r6, r8
	STR r9, [r4], #4
	;divide r6 by 2, store in r5
	MOV r8, #2
	UDIV r9, r6, r8
	STR r9, [r5], #4
	
	
	
stop 	B 		stop     		; dead loop & program hangs here
	ENDP
							
 ; if you have more functions put them here  
	
	END