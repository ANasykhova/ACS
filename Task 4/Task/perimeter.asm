;------------------------------------------------------------------------------
; perimeter.asm - единица компиляции, вбирающая функции вычисления периметра
;------------------------------------------------------------------------------

extern RECTANGLE
extern TRIANGLE
extern CIRCLE

;----------------------------------------------
; Вычисление периметра прямоугольника
;double Perimeter(rectangle *r) {
;    return 2.0 * (r->x2 - r->x1 + r->y2 - r->y1);
;}
;----------------------------------------------
global PerimeterRectangle
PerimeterRectangle:
section .text
push rbp
mov rbp, rsp

    ; В rdi адрес прямоугольника
    mov     eax, [rdi+8]
    add     eax, [rdi+12]
    
    mov ebx, [rdi]
    add ebx, [rdi+4]
    
    cmp eax, ebx
    jl .abs
    
    sub     eax, ebx
    cvtsi2sd        xmm0, eax
    
.abs:
    mov     eax, [rdi+8]
    add     eax, [rdi+12]
    mov ebx, [rdi]
    add ebx, [rdi+4]
    sub ebx, eax
    cvtsi2sd xmm0, ebx

leave
ret

;----------------------------------------------
; double Perimeter(void *t) {
;     double a = sqrt((*((int*)(t+2*intSize)) - *((int*)t)) * (*((int*)(t+2*intSize)) - *((int*)t)) + 
;     (*((int*)(t+3*intSize)) - *((int*)(t+intSize))) * (*((int*)(t+3*intSize)) - *((int*)(t+intSize))));
;     double b = sqrt((*((int*)(t+4*intSize)) - *((int*)t)) * (*((int*)(t+4*intSize)) - *((int*)t)) + 
;     (*((int*)(t+5*intSize)) - *((int*)(t+intSize))) * (*((int*)(t+5*intSize)) - *((int*)(t+intSize))));
;     double c = sqrt((*((int*)(t+4*intSize)) - *((int*)(t+2*intSize))) * (*((int*)(t+4*intSize)) - *((int*)(t+2*intSize))) + 
;     (*((int*)(t+5*intSize)) - *((int*)(t+3*intSize))) * (*((int*)(t+5*intSize)) - *((int*)(t+3*intSize)));
;     return double(a + b + c);
; }
;----------------------------------------------
global PerimeterTriangle
PerimeterTriangle:
section .text
push rbp
mov rbp, rsp

    ; В rdi адрес треугольника
    mov         eax, [rdi]
    mov         edx, [rdi+8]
    sub         edx, eax
    cvtsi2sd    xmm0, edx
    mulsd       xmm0, xmm0  
    mov         eax, [rdi+4]
    mov         edx, [rdi+12]
    sub         edx, eax
    cvtsi2sd    xmm3, edx
    mulsd       xmm3, xmm3  
    addsd         xmm0, xmm3
    fsqrt
    
    mov         eax, [rdi]
    mov         edx, [rdi+16]
    sub         edx, eax
    cvtsi2sd    xmm1, edx
    mulsd       xmm1, xmm1  
    mov         eax, [rdi+4]
    mov         edx, [rdi+20]
    sub         edx, eax
    cvtsi2sd    xmm3, edx
    mulsd       xmm3, xmm3  
    addsd        xmm1, xmm3
    fsqrt
    
    mov         eax, [rdi+8]
    mov         edx, [rdi+16]
    sub         edx, eax
    cvtsi2sd    xmm2, edx
    mulsd       xmm2, xmm2 
    mov         eax, [rdi+12]
    mov         edx, [rdi+20]
    sub         edx, eax
    cvtsi2sd    xmm3, edx
    mulsd       xmm3, xmm3  
    addsd         xmm2, xmm3
    fsqrt
    
    addsd         xmm0, xmm1
    addsd         xmm0, xmm2

leave
ret

;----------------------------------------------
; double PerimeterCircle(void *c) {
;     return 2*3.1416*(*(int*)(c+3*intSize));
;}
;----------------------------------------------
global PerimeterCircle
PerimeterCircle:
section .data
numb dq 6.2832
section .text
push rbp
mov rbp, rsp

    ; В rdi адрес круга
    mov eax, [rdi+8]
    cvtsi2sd    xmm0, eax
    movsd xmm1, [numb]
    mulsd xmm0, xmm1
    
leave
ret

;----------------------------------------------
; Вычисление периметра фигуры
;double PerimeterShape(void *s) {
;    int k = *((int*)s);
;    if(k == RECTANGLE) {
;        return PerimeterRectangle(s+intSize);
;    }
;    else if(k == TRIANGLE) {
;        return PerimeterTriangle(s+intSize);
;    }
;    else if(k == CIRCLE) {
;        return PerimeterCircle(s+intSize);
;    }
;    else {
;        return 0.0;
;    }
;}
;----------------------------------------------
global PerimeterShape
PerimeterShape:
section .text
push rbp
mov rbp, rsp

    ; В rdi адрес фигуры
    mov eax, [rdi]
    cmp eax, [RECTANGLE]
    je rectPerimeter
    cmp eax, [TRIANGLE]
    je trianPerimeter
    cmp eax, [CIRCLE]
    je circPerimeter
    xor eax, eax
    cvtsi2sd    xmm0, eax
    jmp     return
rectPerimeter:
    ; Вычисление периметра прямоугольника
    add     rdi, 4
    call    PerimeterRectangle
    jmp     return
trianPerimeter:
    ; Вычисление периметра треугольника
    add     rdi, 4
    call    PerimeterTriangle
    jmp     return
circPerimeter:
    ; Вычисление периметра круга
    add     rdi, 4
    call    PerimeterCircle
    jmp     return
return:
leave
ret

;----------------------------------------------
;// Сортировка элементов в контейнере
;void Container::QuickSort(void *c, int len, int first, int last) {
;    if (last == -1)
;        last = len - 1;
;    Shape *mid, *count;
;    int f = first, l = last;
;    mid = cont[(f+l) / 2]; //вычисление опорного элемента
;    do {
;        while (cont[f]->Perimeter() < mid->Perimeter()) f++;
;        while (cont[l]->Perimeter() > mid->Perimeter()) l--;
;        if (f <= l) { //перестановка элементов
;            count = cont[f];
;            cont[f] = cont[l];
;            cont[l] = count;
;            f++;
;            l--;
;        }
;    } while (f < l);
;    if (first < l) QuickSort(first, l);
;    if (f < last) QuickSort(f, last);
;}
;----------------------------------------------
global SortContainer
SortContainer:
section .data
    .numb  dq  20
section .bss
    .pcont  resq    1   ; адрес контейнера
    .len    resd    1   ; адрес для сохранения числа введенных элементов
section .text
push rbp
mov rbp, rsp
    
    mov [.pcont], rdi     ; сохраняется указатель на контейнер
    mov [.len],   esi     ; сохраняется число элементов
    
    ; В rdi адрес начала контейнера
    mov rbx, rsi            ; число фигур len
    mov r8, rdx             ; first
    mov r9, rcx             ; last
    
    cmp r9, -1
    jg .next

    mov r9, rbx
    dec r9
.next:
	xor r10, r10
	add r10, r8   ;f
	xor r11, r11
	add r11, r9   ;l
	xor r12, r12
	add r12, r8
	add r12, r9
	sar r12, 1
	mul qword [.numb]
	mov r13, rdi
	add rdi, r12
	call PerimeterShape
	movsd xmm1, xmm0
	mov rdi, r13
	.loop:
	    cmp r10, r11            ; проверка на окончание цикла
	    jge .afterloop            

           .loop2:
                xor r12, r12
                add r12, r10
                mul qword [.numb]
                mov r13, rdi
	        add rdi, r12
	        call PerimeterShape
	        movsd xmm2, xmm0    ;first perimeter
	        mov rdi, r13
	        comiss xmm2, xmm1
	        jae .loop3
	        
	        inc r10
	        jmp .loop2
	    .loop3:
	        xor r12, r12
                add r12, r11
                mul qword [.numb]
                mov r13, rdi
	        add rdi, r12
	        call PerimeterShape
	        movsd xmm3, xmm0    ;last perimeter
	        mov rdi, r13
	        comiss xmm1, xmm3
	        jae .next2
	        
	        dec r10
	        jmp .loop3
	    .next2:
	        cmp r11, r10
	        jge .change

	    jmp .loop
	    
	.change:
	    xor r12, r12
            add r12, r10
            mul qword [.numb]
            mov r13, rdi
	    add rdi, r12
	    mov r12, rdi
	    mov rdi, r13
	    
	    xor r14, r14
            add r14, r11
            mul qword [.numb]
            mov r13, rdi
	    add rdi, r14
	    mov r14, rdi
	    mov rdi, r13
	    
	    mov r13, r12
	    mov r12, r14
	    mov r14, r13
	    inc r10
	    dec r11
	    jmp .loop
	.afterloop:
	    cmp r8, r11
	    jl .qsort1
	    
	    cmp r10, r9
	    jl .qsort2
	    
	    jmp .end
	    
	.qsort1:
	    mov r9, r11
	    jmp .next
	.qsort2:
	    mov r8, r10
	    jmp .next

.end:
leave
ret
