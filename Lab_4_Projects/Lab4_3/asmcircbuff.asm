;****************************************************************
;circular buffering

      .ARMS_off                     ;enable assembler for ARMS=0
      .CPL_on                      	;enable assembler for CPL=1
      .mmregs                       ;enable mem mapped register names

	.global _circbuff				; Circular Buffer Function Name
	.global _inPtr					; Pointer Contianing the Address of Input
	.global _outPtr					; Pointer Contianing the Address of Output
	.global _coeff					; Pointer Contianing the First Address of Coefficient Array;

; This is a skeleton project for initializing circular buffer

	.data							;data section
									;section where all the data is stored 
buff_length	.set 12  					;length of the impulse response ex: length 5 filter

FIR_len	.set 12 					;length of the impulse response ex: 4 length filter

	.align 16			
firbuff	.space 16*buff_length			; allocating buffer space
									; Each Coefficient of impulse response
									; is represented in 16 Bits
									; 16 times the Filter Length
									

oldindex	.word  0				; Allocate storage to save oldindex 
									; (defines where next sample has to be put in buffer)
currindex	.word  0				; Allocate storage to save currindex
									; (defines where next sample has to be put in buffer)
									

	.text							;this section contains the code 

_circbuff							; Circular Buffering function definition

; section 1: loading address
;ex:-	
	MOV		dbl(*(#_inPtr)), XAR6		; XAR6 contains address to input;
    MOV		dbl(*(#_coeff)), XAR5		; XAR5 contains address to First Address of Coefficient Array;
    MOV		dbl(*(#_outPtr)), XAR7		; XAR7 contains address to Output;

;*************************************************************
;***** Your circular buffer configuration code goes here *****
;*************************************************************
	MOV #buff_length, BK03
	BSET AR1LC
	AMOV #01000h, XAR1
	MOV #firbuff, BSA01
	MOV #0000h, AR1

; Next part of the code assumes that AR1 is set as the circulating pointer over firbuff

 	MOV *(#oldindex),AR1				; Initialing the AR1 to Oldindex i.e, Zero

; once set store the index of oldest state in this register
	MOV AR1,*(#currindex)
	MOV *AR6, *AR1+;				; Receive input and store it in the location pointed by *AR1
	 							; i.e, location BSA01 + AR1
    MOV AR1,*(#oldindex)        ; Saving the oldindex from AR1

;*********************************************
;***** Your convolution code goes here *******
;*********************************************
	MOV *(#currindex), AR1
    MOV #0,AC0;
	MOV #FIR_len-1, BRC0                ; Set up the count
	RPTB _label						    ; Repeat the instructions till _label for "BRC0" times
    ;MPY *AR5+,*AR4+, AC1			    ; AC1= (value at Address(AR5) x value at Address(AR4))
                    					; Also, address at AR5 and AR1 increments by one (points to the next memory location of size word, i.e, 16 bits)
_label:	MAC *AR5+,*AR1-,AC0
	;ADD AC1, AC0					; Accumulate the product in accumulator AC0

	MOV HI(AC0),*AR7					; Move the higher byte of the result to the output pointer, here AR7 is containing the output address

	RET									; Return to the main C-program
