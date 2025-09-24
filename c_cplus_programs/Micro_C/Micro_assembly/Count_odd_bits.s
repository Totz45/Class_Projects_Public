 AREA   myData1, DATA, READWRITE  ; your variables and arrays are defined here 

	AREA    main, CODE, READONLY		
	EXPORT	__main				; make __main visible to linker
	ENTRY			  

__main	PROC
 LDR r0, =0xF0F0F0F0
 BL Count_One_Bits
 
Count_One_Bits PROC
	LDR r1, =32
	LDR r3, =0
Loop
	CMP r0, #0
	ADDLT r3, r3, #1
	MOV r0, r0, LSL #1
	SUBS r1, r1, #1
	BNE Loop
	MOV r0, r3
	BX lr
	ENDP
END
 
stop 	B 		stop     		; dead loop & program hangs here
	ENDP
							
 ; if you have more functions put them here  
	
	END