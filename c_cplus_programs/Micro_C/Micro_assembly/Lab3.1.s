   AREA   myData1, DATA, READWRITE  
Number1 DCD 0xAAAAAAAA 			; first variable
Number2 DCD 0xBBBBBBBB 			; second variable
	AREA    main, CODE, READONLY		
	EXPORT	__main				; make __main visible to linker
	ENTRY			

 

__main	PROC
; main function 
 LDR r0,=Number1 ;store the address of the first variable in r0
 LDR r1,[r0] ;r1 now has value 0XAAAAAAAA
 LDR r0,=Number2 ;store the address of the second variable in r0
 LDR r2,[r0] ;r2 now has value 0xBBBBBBBB
 STR r1,[r0] ;r1 changed from 0xAAAAAAAA to 0xBBBBBBBB
 LDR r0,=Number1 ;load the first variable
 STR r2,[r0] ;r2 changed from 0xBBBBBBBB to 0xAAAAAAAA
 ;by the end of the program, the values stored in r1 and r2 are now swapped
		
stop 	B 		stop     		; dead loop & program hangs here
	ENDP
							

	
	END