 AREA   myData1, DATA, READWRITE  ; your variables and arrays are defined here 
x DCD 4
y DCD 2
z DCD 0
	AREA    main, CODE, READONLY		
	EXPORT	__main				; make __main visible to linker
	ENTRY			



__main	PROC
 LDR r0, =x
 LDR r0, [r0]
 LDR r1, =y
 LDR r1, [r1]
 
 MUL r2, r0, r0 ;x^2
 MOV r4, #7
 MUL r2, r2, r4 ;7x^2
 
 MUL r3, r0, r1 ;x*y
 MOV r4, #9
 MUL r3, r3, r4 ;9xy
 ADD r2, r2, r3 ;7x^2 + 9xy
 
 UDIV r3, r0, r1 ;x/y
 MOV r4, #3
 MUL r3, r3, r4 ;3(x/y)
 ADD r2, r2, r3 ;7x^2 + 9xy + 3(x/y)
 
 MOV r4, #11
 MUL r3, r0, r4 ;11x
 ADD r2, r2, r3 ;7x^2 + 9xy + 3(x/y) + 11x
 
 MOV r4, #13
 MUL r3, r1, r4 ;13y
 ADD r2, r2, r3 ;7x^2 + 9xy + 3(x/y) + 11x + 13y
 
 ADD r2, r2, #5 ;7x^2 + 9xy + 3(x/y) + 11x + 13y + 5
 LDR r4, =z
 STR r2, [r4] ;store answer in memory of z
stop 	B 		stop     		; dead loop & program hangs here
	ENDP
						
 ; if you have more functions put them here  
	
	END