.386 
.MODEL FLAT, C 
EXTERN STRING:BYTE ; export INPUT
.DATA; variable segment
.CODE; code segment
FUNC PROC public 

PUSH EBP ;saving the base of stack for safety (check ASM-manual)
MOV EBP, ESP; 
					;getting parameters from stack
MOV ECX, [EBP]+16 ;length of STRING
MOV ESI, [EBP]+12 ;pointer to RESULT
MOV EAX, [EBP]+8 ; pointer to RES_LENGTH
NEXT:
DEC ECX ; massive index begin from 0;
MOV BL, STRING[ECX] ; compare elements from bot to top (length, ... , 0)
CMP BL, 2Eh 
JE NEXT ; if it`s a dot, go next
MOV [ESI], BL ;else add it to RESULT
INC ESI ; смещаем байт
INC byte ptr [EAX] ; increase RES_LENGTH to 1
CMP ECX, 00h ; if STRING is not over yet
JE FINISH
JMP NEXT

FINISH:
POP EBP ;restore the base of stack
RET ;return
FUNC ENDP 
END