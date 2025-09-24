 AREA   myData1, DATA, READWRITE  
Array1 DCD 0x00, 0x00, 0x00       ;intialize a zeroed word array

	AREA    main, CODE, READONLY		
	EXPORT	__main				; make __main visible to linker
	ENTRY			


__main	PROC
; main function 
 LDR r0,=Array1 ;load the array
 LDR r1,=0xAAAAAAAA ;first value going to be stored in array
 LDR r2,=0 ;offset pointer
 STR r1,[r0, r2] ;store r1 in first element of the array
 LDR r1,=0xBBBBBBBB ;second value going to be stored in the array
 LDR r2,=4 ;update offset by 4 bytes
 STR r1,[r0, r2] ;store r1 in second element of the array
 LDR r1,=0xCCCCCCCC ;third value going to be stored in the array
 LDR r2,=8 ;update offset from last by 4 bytes
 STR r1,[r0, r2] ;store r1 in third element of the array
 
		
stop 	B 		stop     		; dead loop & program hangs here
	ENDP
							
	
	END