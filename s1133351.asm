### 1133351
### 排版跟註解還有部分暫存器選擇是由AI協助完成

.data
str0:   .string "s1133351\n"                        ### Student ID string [cite: 6, 20]
str1:   .string "input number M="                   ### Prompt for input M [cite: 46]
str2:   .string "input number N="                   ### Prompt for input N [cite: 47]
strErr: .string "No output(C、H、P、M^N)\n"        ### Error message for invalid inputs
strP:   .string "P(M,N)="                           ### Prefix string for P [cite: 48]
strC:   .string "\nC(M,N)="                         ### Prefix string for C [cite: 49]
strH:   .string "\nH(M,N)="                         ### Prefix string for H
strD:   .string "\nM^N="                            ### Prefix string for M^N

.text
main:
    jal printStudentID      ### Output student ID

    ### --- Read M ---
    jal printMsg1           ### Print prompt for M
    jal inputInt            ### Read integer from user
    mv s1, a0               ### Store M in s1

    ### --- Read N ---
    jal printMsg2           ### Print prompt for N
    jal inputInt            ### Read integer from user
    mv s2, a0               ### Store N in s2

    ### --- Edge Cases & Invalid Input Protection ---
    blt s1, x0, noOutput    ### If M < 0, go to error output
    blt s2, x0, noOutput    ### If N < 0, go to error output
    beq s2, x0, N_is_zero   ### If N == 0, go to N_is_zero shortcut
    
    li t0, 12               ### Load 12 (max factorial limit for 32-bit)
    bgt s1, t0, noOutput    ### If M > 12, go to error output (prevent overflow)
    blt s1, s2, noOutput    ### If M < N, go to error output [cite: 29]

    ### --- 1. Calculate P(M,N) = M! / (M-N)! ---
    mv a0, s1               ### Pass M as argument
    jal factorial           ### Calculate M!
    mv s3, a0               ### s3 = M!

    sub a0, s1, s2          ### a0 = M - N
    jal factorial           ### Calculate (M-N)!
    mv s4, a0               ### s4 = (M-N)!
    
    div s5, s3, s4          ### s5 = M! / (M-N)! = P(M,N)

    ### --- 2. Calculate C(M,N) = P(M,N) / N! ---
    mv a0, s2               ### Pass N as argument
    jal factorial           ### Calculate N!
    mv s6, a0               ### s6 = N!              

    div s7, s5, s6          ### s7 = P(M,N) / N! = C(M,N)

    ### --- 3. Calculate M^N  ---
    mv a0, s1               ### Pass base M
    mv a1, s2               ### Pass exponent N
    jal power               ### Calculate M^N
    mv s8, a0               ### s8 = M^N

    ### --- 4. Calculate H(M,N) = C(M+N-1, N) ---
    add t0, s1, s2          ### t0 = M + N
    addi a0, t0, -1         ### a0 = M + N - 1
    jal factorial           ### Calculate (M+N-1)!
    mv s10, a0              ### s10 = (M+N-1)!
    
    addi a0, s1, -1         ### a0 = M - 1
    jal factorial           ### Calculate (M-1)!
    mv s11, a0              ### s11 = (M-1)!
    
    mul t3, s6, s11         ### t3 = N! * (M-1)!
    div s9, s10, t3         ### s9 = (M+N-1)! / (N! * (M-1)!) = H(M,N)

    j print                 ### Jump to print section

N_is_zero:
    ### --- Shortcut for N = 0 ---
    li s5, 1                ### P(M,0) = 1
    li s7, 1                ### C(M,0) = 1
    li s8, 1                ### M^0 = 1
    li s9, 1                ### H(M,0) = 1

print:
    ### --- Output Format Section ---
    
    ### Print P(M,N)
    la a0, strP             ### Load string address for P
    li a7, 4                ### Syscall 4: print string
    ecall
    mv s0, s5               ### Pass result P
    jal printResult         ### Print result

    ### Print C(M,N)
    la a0, strC             ### Load string address for C
    li a7, 4                ### Syscall 4: print string
    ecall
    mv s0, s7               ### Pass result C
    jal printResult         ### Print result

    ### Print H(M,N)
    la a0, strH             ### Load string address for H
    li a7, 4                ### Syscall 4: print string
    ecall
    mv s0, s9               ### Pass result H
    jal printResult         ### Print result

    ### Print M^N
    la a0, strD             ### Load string address for M^N
    li a7, 4                ### Syscall 4: print string
    ecall
    mv s0, s8               ### Pass result M^N
    jal printResult         ### Print result
    
    j end                   ### Jump to end of program

noOutput:
    ### --- Error Output ---
    la a0, strErr           ### Load error message address
    li a7, 4                ### Syscall 4: print string
    ecall
    j end                   ### Jump to end of program

# ==========================================
#               Functions
# ==========================================

factorial: 
    li t0, 1                ### Load constant 1
    beq a0, x0, is_zero     ### If n == 0, return 1
    mv t1, a0               ### t1 = n (loop counter)
loop: 
    addi t1, t1, -1         ### Decrement counter (t1 = t1 - 1)
    beq t1, x0, endfactorial ### If t1 == 0, break loop
    mul a0, a0, t1          ### Multiply accumulated result by t1
    jal x0, loop            ### Jump back to loop start
is_zero:
    li a0, 1                ### 0! = 1
endfactorial: 
    jr ra                   ### Return to caller

power:
    li t0, 1                ### Initialize result to 1
    beq a1, x0, p_zero      ### If exponent == 0, return 1
    mv t1, a1               ### t1 = exponent (loop counter)
p_loop:
    mul t0, t0, a0          ### Multiply result by base M
    addi t1, t1, -1         ### Decrement exponent counter
    bne t1, x0, p_loop      ### If counter != 0, repeat loop
    mv a0, t0               ### Move final result to a0
    jr ra                   ### Return to caller
p_zero:
    li a0, 1                ### M^0 = 1
    jr ra                   ### Return to caller

printResult:
    mv a0, s0               ### Move number to a0 for printing
    li a7, 1                ### Syscall 1: print integer
    ecall                   ### Execute syscall
    ret                     ### Return to caller

inputInt:                   ### Read integer function [cite: 10, 15]
    li a7, 5                ### Syscall 5: read integer
    ecall                   ### Execute syscall
    ret                     ### Return to caller

printMsg2:
    la a0, str2             ### Load address of string 2
    li a7, 4                ### Syscall 4: print string
    ecall                   ### Execute syscall
    ret                     ### Return to caller

printMsg1:
    la a0, str1             ### Load address of string 1
    li a7, 4                ### Syscall 4: print string
    ecall                   ### Execute syscall
    ret                     ### Return to caller

printStudentID:
    la a0, str0             ### Load address of student ID string
    li a7, 4                ### Syscall 4: print string
    ecall                   ### Execute syscall
    ret                     ### Return to caller
    
end:
    li a7, 10               ### Syscall 10: exit program
    ecall                   ### Execute syscall