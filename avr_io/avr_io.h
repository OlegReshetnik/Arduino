#pragma once

// PORT A
#define IOA0_MASK	(1<<0)
#define IOA0_PIN	PINA
#define IOA0_PORT	PORTA
#define IOA0_DDR	DDRA

#define IOA1_MASK	(1<<1)
#define IOA1_PIN	PINA
#define IOA1_PORT	PORTA
#define IOA1_DDR	DDRA

#define IOA2_MASK	(1<<2)
#define IOA2_PIN	PINA
#define IOA2_PORT	PORTA
#define IOA2_DDR	DDRA

#define IOA3_MASK	(1<<3)
#define IOA3_PIN	PINA
#define IOA3_PORT	PORTA
#define IOA3_DDR	DDRA

#define IOA4_MASK	(1<<4)
#define IOA4_PIN	PINA
#define IOA4_PORT	PORTA
#define IOA4_DDR	DDRA

#define IOA5_MASK	(1<<5)
#define IOA5_PIN	PINA
#define IOA5_PORT	PORTA
#define IOA5_DDR	DDRA

#define IOA6_MASK	(1<<6)
#define IOA6_PIN	PINA
#define IOA6_PORT	PORTA
#define IOA6_DDR	DDRA

#define IOA7_MASK	(1<<7)
#define IOA7_PIN	PINA
#define IOA7_PORT	PORTA
#define IOA7_DDR	DDRA

// PORT B
#define IOB0_MASK	(1<<0)
#define IOB0_PIN	PINB
#define IOB0_PORT	PORTB
#define IOB0_DDR	DDRB

#define IOB1_MASK	(1<<1)
#define IOB1_PIN	PINB
#define IOB1_PORT	PORTB
#define IOB1_DDR	DDRB

#define IOB2_MASK	(1<<2)
#define IOB2_PIN	PINB
#define IOB2_PORT	PORTB
#define IOB2_DDR	DDRB

#define IOB3_MASK	(1<<3)
#define IOB3_PIN	PINB
#define IOB3_PORT	PORTB
#define IOB3_DDR	DDRB

#define IOB4_MASK	(1<<4)
#define IOB4_PIN	PINB
#define IOB4_PORT	PORTB
#define IOB4_DDR	DDRB

#define IOB5_MASK	(1<<5)
#define IOB5_PIN	PINB
#define IOB5_PORT	PORTB
#define IOB5_DDR	DDRB

#define IOB6_MASK	(1<<6)
#define IOB6_PIN	PINB
#define IOB6_PORT	PORTB
#define IOB6_DDR	DDRB

#define IOB7_MASK	(1<<7)
#define IOB7_PIN	PINB
#define IOB7_PORT	PORTB
#define IOB7_DDR	DDRB

// PORT C
#define IOC0_MASK	(1<<0)
#define IOC0_PIN	PINC
#define IOC0_PORT	PORTC
#define IOC0_DDR	DDRC

#define IOC1_MASK	(1<<1)
#define IOC1_PIN	PINC
#define IOC1_PORT	PORTC
#define IOC1_DDR	DDRC

#define IOC2_MASK	(1<<2)
#define IOC2_PIN	PINC
#define IOC2_PORT	PORTC
#define IOC2_DDR	DDRC

#define IOC3_MASK	(1<<3)
#define IOC3_PIN	PINC
#define IOC3_PORT	PORTC
#define IOC3_DDR	DDRC

#define IOC4_MASK	(1<<4)
#define IOC4_PIN	PINC
#define IOC4_PORT	PORTC
#define IOC4_DDR	DDRC

#define IOC5_MASK	(1<<5)
#define IOC5_PIN	PINC
#define IOC5_PORT	PORTC
#define IOC5_DDR	DDRC

#define IOC6_MASK	(1<<6)
#define IOC6_PIN	PINC
#define IOC6_PORT	PORTC
#define IOC6_DDR	DDRC

#define IOC7_MASK	(1<<7)
#define IOC7_PIN	PINC
#define IOC7_PORT	PORTC
#define IOC7_DDR	DDRC

// PORT D
#define IOD0_MASK	(1<<0)
#define IOD0_PIN	PIND
#define IOD0_PORT	PORTD
#define IOD0_DDR	DDRD

#define IOD1_MASK	(1<<1)
#define IOD1_PIN	PIND
#define IOD1_PORT	PORTD
#define IOD1_DDR	DDRD

#define IOD2_MASK	(1<<2)
#define IOD2_PIN	PIND
#define IOD2_PORT	PORTD
#define IOD2_DDR	DDRD

#define IOD3_MASK	(1<<3)
#define IOD3_PIN	PIND
#define IOD3_PORT	PORTD
#define IOD3_DDR	DDRD

#define IOD4_MASK	(1<<4)
#define IOD4_PIN	PIND
#define IOD4_PORT	PORTD
#define IOD4_DDR	DDRD

#define IOD5_MASK	(1<<5)
#define IOD5_PIN	PIND
#define IOD5_PORT	PORTD
#define IOD5_DDR	DDRD

#define IOD6_MASK	(1<<6)
#define IOD6_PIN	PIND
#define IOD6_PORT	PORTD
#define IOD6_DDR	DDRD

#define IOD7_MASK	(1<<7)
#define IOD7_PIN	PIND
#define IOD7_PORT	PORTD
#define IOD7_DDR	DDRD

#define __MASK(IO)	IO##_MASK
#define __PORT(IO)	IO##_PORT
#define __PIN(IO)	IO##_PIN
#define __DDR(IO)	IO##_DDR

#define READ(IO)				(__PIN(IO) & __MASK(IO))
#define SET0(IO)				do { __PORT(IO) &= ~__MASK(IO); } while (0)
#define SET1(IO)				do { __PORT(IO) |= __MASK(IO); } while (0)
#define WRITE(IO, v)			do { if (v) { SET1(IO); } else { SET0(IO); } } while (0)
#define SET_INPUT(IO)			do { __DDR(IO) &= ~__MASK(IO); } while (0)
#define SET_INPUT_PULLUP(IO)	do { __DDR(IO) &= ~__MASK(IO); __PORT(IO) |= __MASK(IO); } while (0)
#define SET_OUTPUT(IO)			do { __DDR(IO) |= __MASK(IO); } while (0)
#define PULLUP_ON(IO)			SET1(IO)
#define PULLUP_OFF(IO)			SET0(IO)
