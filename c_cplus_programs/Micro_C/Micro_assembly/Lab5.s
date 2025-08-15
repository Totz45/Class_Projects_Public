 AREA   myData1, DATA, READWRITE  ; your variables and arrays are defined here 
Number1 DCD 0x0000000F ;for task 1
Number2 DCD 0x000000FF ;for task 2
Number3 DCD 0x000000AF ;for task 3
Number4 DCD 0x00000000 ;for task 3
Number5 DCD 0x000007F8 ;for task 4
Number6 DCD 0x00000000 ;for task 4
Number7 DCD 1 ;for task 5
Number8 DCD 80 ;for task 6
Number9 DCD -88 ;for task 7

	AREA    main, CODE, READONLY		
	EXPORT	__main				; make __main visible to linker
	ENTRY			  

__main	PROC
 ;Task 1 - Changing bits 
 LDR r0, =Number1
 LDR r1, [r0] 
 MOVS r4, #1 ;intitialize logical 1
 ORRS r1, r1, r4, LSL #31 ;set bit 31, part 1 complete
 
 LDR r0, =Number1
 LDR r1, [r0] 
 BICS r1, r1, r4, LSL #0 ;clear bit 0, part 2 complete
 
 LDR r0, =Number1
 LDR r1, [r0] 
 EORS r1, r1, r4, LSL #3 ; toggle bit 3
 STR r1, [r0] ;task 1 complete in memory
		
 ;Task 2 - Masking
 LDR r0, =Number2
 LDR r1, [r0]
 LDR r4, =0x00000007
 AND r1, r1, r4 ;r1 = mask value
 EORS r1, r1, r4 ;r1 = all bits clear
 STR r1, [r0] ;task 2 complete in memory
 
 ;Task 3 - Copying bits
 LDR r0, =Number3
 LDR r1, =Number4
 LDR r2, [r0]
 LDR r3, [r1]
 BFI r3, r2, #5, #5 ;copy first five bits of Number3 and put them in bits 5-9 of Number4
 STR r3, [r1] ;task 3 complete in memory
 
 ;Task 4 - reversing bits
 LDR r0, =Number5
 LDR r1, =Number6
 LDR r2, [r0]
 RBIT r2, r2 ;reverse the bits in r2 which holds Number5 and storing new value
 STR r2, [r1] ;task 4 complete in memory
 
 ;Task 5 - Multiply by 10 using bit shift and addition
 LDR r0, =Number7
 LDR r1, [r0]
 LSLS r1, r1, #2 ;Multiply value by 4
 MOVS r4, #1
 ADDS r1, r1, r4 ;Add 1 to value -- total is now 5
 LSLS r1, r1, #1 ;Multiply value by 2 -- total is 10
 STR r1, [r0] ;task 5 complete in memory
 
 ;Task 6 - Divide unsigned value by 8, only bit shift
 LDR r0, =Number8
 LDR r1, [r0]
 LSRS r1, r1, #3 ;Divide value by 8
 STR r1, [r0] ;task 6 complete in memory
 
 ;Task 7 - Divide signed value by 8, only bit shift
 LDR r0, =Number9
 LDR r1, [r0]
 ASRS r1, r1, #3 ;Divide value by 8, arithmetic keeps bits so it remains signed
 STR r1, [r0] ;task 7 complete in memory
 
stop 	B 		stop     		; dead loop & program hangs here
	ENDP
							
 ; if you have more functions put them here  
	
	END