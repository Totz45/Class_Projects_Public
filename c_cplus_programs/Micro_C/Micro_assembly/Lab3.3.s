	AREA   myData1, DATA, READWRITE  ; your variables and arrays are defined here 
Array1 DCD 0xAAAAAAAA, 0xBBBBBBBB, 0xCCCCCCCC ;Array1 is the initialized array
Array2 DCD 0x00, 0x00, 0x00	;Array2 is the zeroed array

	AREA    main, CODE, READONLY		
	EXPORT	__main				; make __main visible to linker
	ENTRY			


__main	PROC
; main function 
 LDR r0, =Array1 ;load the first array in r0
 LDR r1, =Array2 ;load the second array in r1
 LDR r2,[r0], #4 ;load value from first element in r0, now on second element
 STR r2,[r1], #4 ;store value in first element of r1, now on second element
 LDR r2,[r0], #4 ;load value from second element in r0, now on third element
 STR r2,[r1], #4 ;store value in second element of r1, now on third element
 LDR r2,[r0], #4 ;load value from third element in r0, now on fourth element
 STR r2,[r1], #4 ;store value in third element of r1, now on fourth element
		
stop 	B 		stop     		; dead loop & program hangs here
	ENDP
							 
	
	END