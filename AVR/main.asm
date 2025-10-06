.include "/usr/share/avra/m328Pdef.inc"

.def temp = r16
.def overflows = r17

.org 0x0000
rjmp reset

.org 0x0020
rjmp overflow_handler


reset:
    ldi temp, 0b00000101
    out TCCR0B, temp

    ldi temp, 0b00000001
    sts TIMSK0, temp

    ldi temp, 0b10000000
    out SREG, temp

    ldi temp, 0b00000000
    out TCNT0, temp

    ldi temp, 0b11111111
    out DDRB, temp

blink:
    ldi temp, 0b00100000
    out PORTB, temp
    rcall delay
    ldi temp, 0b00000000
    out PORTB, temp
    rcall delay
    rjmp blink

delay:
    ldi overflows, 0b00000000
    sec_count:
        cpi overflows, 30
    brne sec_count
    ret

overflow_handler:
    inc overflows
    cpi overflows, 61
    brne PC+2
    ldi overflows, 0b00000000
    reti
















