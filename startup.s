.syntax unified
.cpu cortex-m3
.thumb

.global _start
.global _estack
.global _sdata, _edata, _sbss, _ebss
.global _etext

.set STACK_TOP, 0x20020000

_start:
    ldr sp, =STACK_TOP
    mov r0, #0
    bl copy_data
    bl zero_bss
    bl main
halt:
    b halt

copy_data:
    ldr r1, =_sdata
    ldr r2, =_edata
    ldr r3, =_etext
    cmp r1, r2
    beq copy_done
copy_loop:
    ldr r4, [r3]
    add r3, r3, #4
    str r4, [r1]
    add r1, r1, #4
    cmp r1, r2
    bne copy_loop
copy_done:
    bx lr

zero_bss:
    ldr r1, =_sbss
    ldr r2, =_ebss
    cmp r1, r2
    beq zero_done
    mov r0, #0
zero_loop:
    str r0, [r1]
    add r1, r1, #4
    cmp r1, r2
    bne zero_loop
zero_done:
    bx lr

.size _start, .-_start