; file.asm - использование файлов в NASM
extern printf
extern fprintf

extern PerimeterRectangle
extern PerimeterTriangle
extern PerimeterCircle

extern RECTANGLE
extern TRIANGLE
extern CIRCLE

;----------------------------------------------
;// Вывод параметров прямоугольника в файл
;void OutRectangle(void *r, FILE *ofst) {
;    fprintf(ofst, "It is Rectangle: x1 = %d, y1 = %d, x2 = %d, y2 = %d, 
;            color = %d. Perimeter = %g\n", *((int*)r), *((int*)(r+intSize)), 
;            *((int*)(r+2*intSize)), *((int*)(r+3*intSize)), *((int*)(r+4*intSize)),
;            PerimeterRectangle(r));
;}
;----------------------------------------------
global OutRectangle
OutRectangle:
section .data
    .outfmt db "It is Rectangle: x1 = %d, y1 = %d, x2 = %d, y2 = %d, color = %d. Perimeter = %g",10,0
section .bss
    .prect  resq  1
    .FILE   resq  1       ; временное хранение указателя на файл
    .p      resq  1       ; вычисленный периметр прямоугольника
section .text
push rbp
mov rbp, rsp

    ; Сохранение принятых аргументов
    mov     [.prect], rdi          ; сохраняется адрес прямоугольника
    mov     [.FILE], rsi          ; сохраняется указатель на файл

    ; Вычисление периметра прямоугольника (адрес уже в rdi)
    call    PerimeterRectangle
    movsd   [.p], xmm0          ; сохранение (может лишнее) периметра

    ; Вывод информации о прямоугольнике в файл
    mov     rdi, [.FILE]
    mov     rsi, .outfmt        ; Формат - 2-й аргумент
    mov     rax, [.prect]        ; адрес прямоугольника
    mov     edx, [rax]          ; x1
    mov     ecx, [rax+4]        ; y1
    mov     r8, [rax+8]         ; x2
    mov     r9, [rax+12]        ; y2
    mov     r10, [rax+16]       ; color
    movsd   xmm0, [.p]          ; perimeter
    mov     rax, 1              ; есть числа с плавающей точкой
    call    fprintf

leave
ret

;----------------------------------------------
; // Вывод параметров треугольника в файл
; void OutTriangle(void *t, FILE *ofst) {
;     fprintf(ofst, "It is Triangle: x1 = %d, y1 = %d, x2 = %d, y2 = %d, x3 = %d, y3 = %d, color = %d. Perimeter = %g\n",
;             *((int*)t), *((int*)(t+intSize)), *((int*)(t+2*intSize)), *((int*)(t+3*intSize)), *((int*)(t+4*intSize)),
;             *((int*)(t+5*intSize)), *((int*)(t+6*intSize)), PerimeterTriangle(t));
; }
;----------------------------------------------
global OutTriangle
OutTriangle:
section .data
    .outfmt db "It is Triangle: x1 = %d, y1 = %d, x2 = %d, y2 = %d, x3 = %d, y3 = %d, color = %d. Perimeter = %g",10,0
section .bss
    .ptrian  resq  1
    .FILE   resq  1       ; временное хранение указателя на файл
    .p      resq  1       ; вычисленный периметр треугольника
section .text
push rbp
mov rbp, rsp

    ; Сохранени принятых аргументов
    mov     [.ptrian], rdi        ; сохраняется адрес треугольника
    mov     [.FILE], rsi          ; сохраняется указатель на файл

    ; Вычисление периметра треугольника (адрес уже в rdi)
    call    PerimeterTriangle
    movsd   [.p], xmm0          ; сохранение (может лишнее) периметра

    ; Вывод информации о треугольнике в файл
    mov     rdi, [.FILE]
    mov     rsi, .outfmt        ; Формат - 2-й аргумент
    mov     rax, [.ptrian]      ; адрес треугольника
    mov     edx, [rax]          ; x1
    mov     ecx, [rax+4]        ; y1
    mov      r8, [rax+8]        ; x2
    mov     r9, [rax+12]       ; y2
    mov     r10, [rax+16]       ; x3
    mov     r11, [rax+20]       ; y3
    mov     r12, [rax+24]       ; color
    movsd   xmm0, [.p]          ; perimeter
    mov     rax, 1              ; есть числа с плавающей точкой
    call    fprintf

leave
ret

;----------------------------------------------
;// Вывод параметров прямоугольника в файл
;void OutCircle(void *c, FILE *ofst) {
;    fprintf(ofst, "It is Circle: x = %d, y = %d, r = %d, color = %d. Perimeter = %g\n", 
;            *((int*)r), *((int*)(r+intSize)), *((int*)(r+2*intSize)),
;            *((int*)(r+3*intSize)), PerimeterRectangle(r));
;}
;----------------------------------------------
global OutCircle
OutCircle:
section .data
    .outfmt db "It is Circle: x = %d, y = %d, r = %d, color = %d. Perimeter = %g",10,0
section .bss
    .pcirc  resq  1
    .FILE   resq  1       ; временное хранение указателя на файл
    .p      resq  1       ; вычисленный периметр круга
section .text
push rbp
mov rbp, rsp

    ; Сохранение принятых аргументов
    mov     [.pcirc], rdi          ; сохраняется адрес прямоугольника
    mov     [.FILE], rsi          ; сохраняется указатель на файл

    ; Вычисление периметра круга (адрес уже в rdi)
    call    PerimeterCircle
    movsd   [.p], xmm0          ; сохранение (может лишнее) периметра

    ; Вывод информации о круге в файл
    mov     rdi, [.FILE]
    mov     rsi, .outfmt        ; Формат - 2-й аргумент
    mov     rax, [.pcirc]       ; адрес круга
    mov     edx, [rax]          ; x
    mov     ecx, [rax+4]        ; y
    mov     r8, [rax+8]         ; r
    mov     r9, [rax+12]       ; color
    movsd   xmm0, [.p]          ; perimeter
    mov     rax, 1              ; есть числа с плавающей точкой
    call    fprintf

leave
ret

;----------------------------------------------
; // Вывод параметров текущей фигуры в файл
; void OutShape(void *s, FILE *ofst) {
;     int k = *((int*)s);
;     if(k == RECTANGLE) {
;         OutRectangle(s+intSize, ofst);
;     }
;     else if(k == TRIANGLE) {
;         OutTriangle(s+intSize, ofst);
;     }
;     else if(k == CIRCLE) {
;         OutCircle(s+intSize, ofst);
;     }
;     else {
;         fprintf(ofst, "Incorrect figure!\n");
;     }
; }
;----------------------------------------------
global OutShape
OutShape:
section .data
    .erShape db "Incorrect figure!",10,0
section .text
push rbp
mov rbp, rsp

    ; В rdi адрес фигуры
    mov eax, [rdi]
    cmp eax, [RECTANGLE]
    je rectOut
    cmp eax, [TRIANGLE]
    je trianOut
    cmp eax, [CIRCLE]
    je circOut
    mov rdi, .erShape
    mov rax, 0
    call fprintf
    jmp     return
rectOut:
    ; Вывод прямоугольника
    add     rdi, 4
    call    OutRectangle
    jmp     return
trianOut:
    ; Вывод треугольника
    add     rdi, 4
    call    OutTriangle
    jmp     return
circOut:
    ; Вывод круга
    add     rdi, 4
    call    OutCircle
    jmp     return
return:
leave
ret

;----------------------------------------------
; // Вывод содержимого контейнера в файл
; void OutContainer(void *c, int len, FILE *ofst) {
;     void *tmp = c;
;     fprintf(ofst, "Container contains %d elements.\n", len);
;     for(int i = 0; i < len; i++) {
;         fprintf(ofst, "%d: ", i);
;         OutShape(tmp, ofst);
;         tmp = tmp + shapeSize;
;     }
; }
;----------------------------------------------
global OutContainer
OutContainer:
section .data
    numFmt  db  "%d: ",0
section .bss
    .pcont  resq    1   ; адрес контейнера
    .len    resd    1   ; адрес для сохранения числа введенных элементов
    .FILE   resq    1   ; указатель на файл
section .text
push rbp
mov rbp, rsp

    mov [.pcont], rdi     ; сохраняется указатель на контейнер
    mov [.len],   esi     ; сохраняется число элементов
    mov [.FILE],  rdx     ; сохраняется указатель на файл

    ; В rdi адрес начала контейнера
    mov rbx, rsi            ; число фигур
    xor ecx, ecx            ; счетчик фигур = 0
    mov rsi, rdx            ; перенос указателя на файл
.loop:
    cmp ecx, ebx            ; проверка на окончание цикла
    jge .return             ; Перебрали все фигуры

    push rbx
    push rcx

    ; Вывод номера фигуры
    mov     rdi, [.FILE]    ; текущий указатель на файл
    mov     rsi, numFmt     ; формат для вывода фигуры
    mov     edx, ecx        ; индекс текущей фигуры
    xor     rax, rax,       ; только целочисленные регистры
    call fprintf

    ; Вывод текущей фигуры
    mov     rdi, [.pcont]
    mov     rsi, [.FILE]
    call OutShape           ; Получение периметра первой фигуры

    pop rcx
    pop rbx
    inc ecx                 ; индекс следующей фигуры

    mov     rax, [.pcont]
    add     rax, 32      ; адрес следующей фигуры
    mov     [.pcont], rax
    jmp .loop
.return:
leave
ret

