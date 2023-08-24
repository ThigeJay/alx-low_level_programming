section .data
format:  db "Hello, Holberton", 10, 0   ; 10 is the ASCII value for newline

section .text
global main
extern printf

; Entry point of our program
main:
    ; Set up arguments for printf
    mov   rdi, format        ; First argument is format string
    xor   eax, eax           ; Clear eax to pass the number of vector used for arguments

    ; Call printf function
    call  printf

    ; Return from main
    mov   eax, 0             ; Return 0 status
    ret
