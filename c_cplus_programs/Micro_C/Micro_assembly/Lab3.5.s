	AREA   myData1, DATA, READWRITE  ; your variables and arrays are defined here 
Array1 DCD 0xAAAAAAAA, 0xBBBBBBBB, 0xCCCCCCCC ;Array 1 is the initialized array
Array2 DCD 0x00, 0x00, 0x00	;Array 2 is the zeroed array

	AREA    main, CODE, READONLY		
	EXPORT	__main				; make __main visible to linker
	ENTRY			
 

__main	PROC
; main function 
 LDR r0, =Array1 ;load array1 into r0
 LDR r1, =Array2 ;load array2 into r1
 SUB r0, #4 ;update offset for pre-index
 SUB r1, #4 ;update offset for pre-index
 LDR r2,[r0, #4] ;load from first element in r0
 STR r2,[r1, #4] ;store value of first element in r1
 ADD r0, #4 ;update offset for next element
 ADD r1, #4 ;update offset for next element
 LDR r2,[r0, #4] ;load from second element in r0
 STR r2,[r1, #4] ;store value of second element in r1
 ADD r0, #4 ;update offset for next element
 ADD r1, #4 ;update offset for next element
 LDR r2,[r0, #4] ;load from third element in r0
 STR r2,[r1, #4] ;store value of third element in r1
		
stop 	B 		stop     		; dead loop & program hangs here
	ENDP
							
	
	END