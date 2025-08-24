.include "/usr/share/avra/m328Pdef.inc"

    ldi r16, 0b11111111
    out DDRB, r16

    ldi r16, 0b00000000
    out PORTB, r16

Start:
    rjmp Start
