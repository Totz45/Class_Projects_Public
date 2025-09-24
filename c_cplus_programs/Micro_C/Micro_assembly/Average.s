 AREA   myData1, DATA, READWRITE  ; your variables and arrays are defined here 


	AREA    code, CODE, READONLY		
	EXPORT AvgFiveNums ;replace with function name
	ENTRY			  

AvgFiveNums	PROC ;function name
	POP {r4} ;pop everything from stack if calling more than 4
	MOVS r5, #0
	
	ADD r5, r0
	ADD r5, r1
	ADD r5, r2
	ADD r5, r3

	ADD r5, r4
	MOVS r6, #5
	MOVS r7, #0
loop CMP r5, r6
    BLT endloop
	SUBS r5, #5
	ADDS r7, #1
    B loop
endloop
	;wanted to use UDIV r5, r5, r6 but system did not allow it
	MOV r0, r7 ;r0 is used to return values
	
	MOV PC, LR ;return statement

	ENDP
							
 ; if you have more functions put them here  
	
	END