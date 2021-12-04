; file.asm - использование файлов в NASM
extern printf
extern rand

extern RECTANGLE
extern TRIANGLE
extern CIRCLE

;----------------------------------------------
; // rnd.c - содержит генератор случайных чисел в диапазоне от 1 до 20
; int Random() {
;     return rand() % 20 + 1;
; }
global Random
Random:
section .data
    .i20     dq      20
    .rndNumFmt       db "Random number = %d",10,0
section .text
push rbp
mov rbp, rsp

    xor     rax, rax    ;
    call    rand        ; запуск генератора случайных чисел
    xor     rdx, rdx    ; обнуление перед делением
    idiv    qword[.i20]       ; (/%) -> остаток в rdx
    mov     rax, rdx
    inc     rax         ; должно сформироваться случайное число


leave
ret

;----------------------------------------------
; // Случайный ввод параметров прямоугольника
; void InRndRectangle(void *r) {
;     int x1 = Random();
;     *((int*)r) = x1;
;     int y1 = Random();
;     *((int*)(r+intSize)) = y1;
;     int x2 = Random();
;     *((int*)(r+2*intSize)) = x2;
;     int y2 = Random();
;     *((int*)(r+3*intSize)) = y2;
; }
;----------------------------------------------
global InRndRectangle
InRndRectangle:
section .bss
    .prect  resq 1   ; адрес прямоугольника
section .text
push rbp
mov rbp, rsp

    ; В rdi адрес прямоугольника
    mov     [.prect], rdi
    ; Генерация сторон прямоугольника
    call    Random
    mov     rbx, [.prect]
    mov     [rbx], eax      ; x1
    call    Random
    mov     rbx, [.prect]
    mov     [rbx+4], eax    ; y1
    call    Random
    mov     rbx, [.prect]
    mov     [rbx+8], eax    ; x2
    call    Random
    mov     rbx, [.prect]
    mov     [rbx+12], eax   ; y2
    xor     rax, rax
    call    rand        ; запуск генератора случайных чисел
    and     eax, 6      ; очистка результата кроме младшего разряда (0 или 1)
    inc     eax         ; фомирование признака фигуры (1 или 2)
    mov     rbx, [.prect]
    mov     [rbx+16], eax      ; color

leave
ret

;----------------------------------------------
;// Случайный ввод параметров треугольника
;void InRndTriangle(void *t) {
;    int a, b, c;
;    a = *((int*)t) = Random();
;    b = *((int*)(t+intSize)) = Random();
;    do {
;        c = *((int*)(t+2*intSize)) = Random();
;    } while((c >= a + b) || (a >= c + b) || (b >= c + a));
;}
;----------------------------------------------
global InRndTriangle
InRndTriangle:
section .bss
    .ptrian  resq 1   ; адрес треугольника
section .text
push rbp
mov rbp, rsp

    ; В rdi адрес треугольника
    mov     [.ptrian], rdi
    ; Генерация сторон треугольника
    call    Random
    mov     rbx, [.ptrian]
    mov     [rbx], eax      ; x1
    call    Random
    mov     rbx, [.ptrian]
    mov     [rbx+4], eax    ; y1
    call    Random
    mov     rbx, [.ptrian]
    mov     [rbx+8], eax    ; x2
    call    Random
    mov     rbx, [.ptrian]
    mov     [rbx+12], eax   ; y2
    call    Random
    mov     rbx, [.ptrian]
    mov     [rbx+16], eax    ; x3
    call    Random
    mov     rbx, [.ptrian]
    mov     [rbx+20], eax   ; y3
    xor     rax, rax
    call    rand        ; запуск генератора случайных чисел
    and     eax, 6      ; очистка результата кроме младшего разряда (0 или 1)
    inc     eax         ; фомирование признака фигуры (1 или 2)
    mov     rbx, [.ptrian]
    mov     [rbx+24], eax      ; color

leave
ret

;----------------------------------------------
;// Случайный ввод параметров круга
;void InRndCircle(void *c) {
;    int x = Random();
;    *((int*)r) = x;
;    int y = Random();
;    *((int*)(r+intSize)) = y;
;    int r = Random();
;    *((int*)(r+2*intSize)) = r;
;    int color = Random();
;    *((int*)(r+3*intSize)) = color;
;}
;----------------------------------------------
global InRndCircle
InRndCircle:
section .bss
    .pcirc  resq   1   ; адрес круга
section .text
push rbp
mov rbp, rsp

    ; В rdi адрес круга
    mov     [.pcirc], rdi
    ; Генерация сторон круга
    call    Random
    mov     rbx, [.pcirc]
    mov     [rbx], eax      ; x
    call    Random
    mov     rbx, [.pcirc]
    mov     [rbx+4], eax    ; y
    call    Random
    mov     rbx, [.pcirc]
    mov     [rbx+8], eax    ; r    
    xor     rax, rax
    call    rand        ; запуск генератора случайных чисел
    and     eax, 6      ; очистка результата кроме младшего разряда (0 или 1)
    inc     eax         ; фомирование признака фигуры (1 или 2)
    mov     rbx, [.pcirc]
    mov     [rbx+12], eax      ; color

leave
ret

;----------------------------------------------
;// Случайный ввод обобщенной фигуры
;int InRndShape(void *s) {
;    int k = rand() % 2 + 1;
;    switch(k) {
;        case 1:
;            *((int*)s) = RECTANGLE;
;            InRndRectangle(s+intSize);
;            return 1;
;        case 2:
;            *((int*)s) = TRIANGLE;
;            InRndTriangle(s+intSize);
;            return 1;
;        case 3:
;            *((int*)s) = CIRCLE;
;            InRndCircle(s+intSize);
;            return 1;
;        default:
;            return 0;
;    }
;}
;----------------------------------------------
global InRndShape
InRndShape:
section .data
    .rndNumFmt       db "Random number = %d",10,0
    .numb  dq 3
section .bss
    .pshape     resq    1   ; адрес фигуры
    .key        resd    1   ; ключ
section .text
push rbp
mov rbp, rsp

    ; В rdi адрес фигуры
    mov [.pshape], rdi

    ; Формирование признака фигуры
    xor     rax, rax    ;
    call    rand        ; запуск генератора случайных чисел
    xor     rdx, rdx    ; обнуление перед делением
    idiv    qword[.numb]       ; (/%) -> остаток в rdx
    mov     rax, rdx
    inc     rax         ; должно сформироваться случайное число

    mov     rdi, [.pshape]
    mov     [rdi], eax      ; запись ключа в фигуру
    cmp eax, [RECTANGLE]
    je .rectInrnd
    cmp eax, [TRIANGLE]
    je .trianInRnd
    cmp eax, [CIRCLE]
    je .circInRnd
    xor eax, eax        ; код возврата = 0
    jmp     .return
.rectInrnd:
    ; Генерация прямоугольника
    add     rdi, 4
    call    InRndRectangle
    mov     eax, 1      ;код возврата = 1
    jmp     .return
.trianInRnd:
    ; Генерация треугольника
    add     rdi, 4
    call    InRndTriangle
    mov     eax, 1      ;код возврата = 1
    jmp     .return
.circInRnd:
    ; Генерация круга
    add     rdi, 4
    call    InRndCircle
    mov     eax, 1      ;код возврата = 1

.return:
leave
ret

;----------------------------------------------
;// Случайный ввод содержимого контейнера
;void InRndContainer(void *c, int *len, int size) {
    ;void *tmp = c;
    ;while(*len < size) {
        ;if(InRndShape(tmp)) {
            ;tmp = tmp + shapeSize;
            ;(*len)++;
        ;}
    ;}
;}
;----------------------------------------------
global InRndContainer
InRndContainer:
section .bss
    .pcont  resq    1   ; адрес контейнера
    .plen   resq    1   ; адрес для сохранения числа введенных элементов
    .psize  resq    1   ; число порождаемых элементов
section .text
push rbp
mov rbp, rsp

    mov [.pcont], rdi   ; сохраняется указатель на контейнер
    mov [.plen], rsi    ; сохраняется указатель на длину
    mov [.psize], edx    ; сохраняется число порождаемых элементов
    ; В rdi адрес начала контейнера
    xor ebx, ebx        ; число фигур = 0
.loop:
    cmp ebx, edx
    jge     .return
    ; сохранение рабочих регистров
    push rdi
    push rbx
    push rdx

    call    InRndShape     ; ввод фигуры
    cmp rax, 0          ; проверка успешности ввода
    jle  .return        ; выход, если признак меньше или равен 0

    pop rdx
    pop rbx
    inc rbx

    pop rdi
    add rdi, 32             ; адрес следующей фигуры

    jmp .loop
.return:
    mov rax, [.plen]    ; перенос указателя на длину
    mov [rax], ebx      ; занесение длины
leave
ret
