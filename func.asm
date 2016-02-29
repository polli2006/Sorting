section .bss
global sw
global cm
sw resd 1
cm resd 1


section .text
;функция сравнения
global cmp1
cmp1:
push ebp
mov ebp, esp
xor eax, eax
finit
fld qword[ebp + 16]
fabs
fld qword[ebp + 8]
fabs
fucomi
setb al
inc dword[cm]
pop ebp
ret

;функция перемещения элементов
global change
change:
 push ebp
mov ebp, esp
push ebx
mov eax, dword[ebp + 8]
mov ebx, dword[ebp + 12]
mov ecx, dword[eax]
mov edx, dword[ebx]
mov dword[eax], edx
mov dword[ebx], ecx
mov ecx, dword[eax + 4]
mov edx, dword[ebx + 4]
mov dword[eax + 4], edx
mov dword[ebx + 4], ecx
inc dword[sw]
pop ebx
pop ebp
ret

;Таймер
GLOBAL timestamp
timestamp:
RDTSC
RET


