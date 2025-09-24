 AREA   myData1, DATA, READWRITE  ; your variables and arrays are defined here 
Number1 DCD 0xFFFFFFFF
Passwords DCD 1234, 34567, 345676, 87654, 902345, 56784, 0x00000000
input_password DCD 290657
Array DCD 200, -14, 0, 0, 22, 0, -100, 0, -80, -180

	AREA    main, CODE, READONLY		
	EXPORT	__main				; make __main visible to linker
	ENTRY			  

__main	PROC
	
	;uncomment to skip to task/used for debugging each individual task
		;B task1
		;B task2
		;B task3
		;B task4
 
 ;Task 1 - count number of ones 
task1	LDR r0, =Number1
		LDR r1, [r0]
		MOV r2, #0
		MOV r3, #0
loop 	CMP r3, #32 ;iterates 32 times
		BGE endloop
		LSRS r1, r1, #1 ;check carry flag for 1
		ADDHS r2, #1 ;add to r2 if carry
		ADD r3, #1
		B loop
endloop
		;check r2 for result
		
		
	;Task 2 - check specific bit
task2	LDR r0, =0xF0000000
		MOV r2, #1
		LSRS r0, r0, #5
		ANDS r0, r2 ;after LSRS and AND, lsb is bit 5
		CMP r0, r2
		BNE else1
		MOV r1, #0xFFFFFFFF ;set if bit 5 is 1
		B fi
else1
		MOV r1, #0x00000000 ;set if bit 5 is 0
fi
		;check r1 for result
		
		
	;Task 3 - search for match
task3	LDR r0, =Passwords
		LDR r1, =input_password
		LDR r2, [r0], #4 ;set to obtain next element, on the next call
		LDR r3, [r1]
search  CMP r2, r3
		BEQ found ;branch if input_password matches
		CMP r2, #0x00000000
		BEQ notfound ;branch if input_password does not match by end of array
		MOV r4, #0x00000000
		LDR r2, [r0], #4
		B search
found
		MOV r4, #0xFFFFFFFF
notfound
		;check r4 for result
	
	
	;Task 4 - count zeroes and negatives
task4	LDR r0, =Array
		LDR r1, [r0], #4
		MOV r2, #10
negative CMP r2, #0
		BLE endnegative
		ADDS r1, r1, #0 ;set flag only
		ADDMI r4, r4, #1 ;add if negative flag is set
		ADDEQ r5, r5, #1 ;add if zero flag is set
		LDR r1, [r0], #4
		SUB r2, r2, #1
		B negative
endnegative
		;check r4 for # of negatives
		;check r5 for # of zeros
		
		
stop 	B 		stop     		; dead loop & program hangs here
	ENDP
							
 ; if you have more functions put them here  
	
	END