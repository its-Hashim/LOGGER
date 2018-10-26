
const uint16_t LOAD = 0;
const uint16_t COMP = 31250;

void setup() {
  pinMode(13,HIGH);
  TCCR1A = 0;
  TCCR1B |= 1<<CS12;
  TCCR1B &= ~ (1<<CS11 | 1<<CS10);
  TCNT1=0;
  OCR1A=COMP;
  TIMSK1=(1 << OCIE1A);
  sei();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(90000);

}

ISR(TIMER1_COMPA_vect)
{
  TCNT1 = 0;
  PORTB ^= 1<<PB5;
}

