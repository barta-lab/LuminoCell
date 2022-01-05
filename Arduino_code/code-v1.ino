//Define the pin connections of the Arduino.  
//Largely depends on what Arduino board you are using! Check the specifications https://www.arduino.cc/en/Main/Products or https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/
//we will use didital pins 2,3,4,5,6,7 of the Arduino Nano Every board, each pin is connected to TSL2375
#define TSL_FREQ_PIN2 2 // output use digital pin2 for interrupt
#define TSL_FREQ_PIN3 3 // output use digital pin3 for interrupt
#define TSL_FREQ_PIN4 4 // output use digital pin4 for interrupt
#define TSL_FREQ_PIN5 5 // output use digital pin5 for interrupt
#define TSL_FREQ_PIN6 6 // output use digital pin6 for interrupt
#define TSL_FREQ_PIN7 7 // output use digital pin7 for interrupt

#define ECHO_TO_SERIAL   1 // echo data to serial port

volatile unsigned long pulse_cnt_well_1 = 0; //pulse counts for well_1
volatile unsigned long pulse_cnt_well_2 = 0; //pulse counts for well_2
volatile unsigned long pulse_cnt_well_3 = 0; //pulse counts for well_3
volatile unsigned long pulse_cnt_well_4 = 0; //pulse counts for well_4
volatile unsigned long pulse_cnt_well_5 = 0; //pulse counts for well_5
volatile unsigned long pulse_cnt_well_6 = 0; //pulse counts for well_6

unsigned long integration_time = 300000; //integration time in ms
unsigned long previousMillis = 0;
void setup() {
  
Serial.begin(9600);
#if ECHO_TO_SERIAL
  Serial.println("well,time(min),count"); //header of the output
#endif
delay(2000);

pinMode(TSL_FREQ_PIN2, INPUT);
pinMode(TSL_FREQ_PIN3, INPUT);
pinMode(TSL_FREQ_PIN4, INPUT);
pinMode(TSL_FREQ_PIN5, INPUT);
pinMode(TSL_FREQ_PIN6, INPUT);
pinMode(TSL_FREQ_PIN7, INPUT);
attachInterrupt(digitalPinToInterrupt(TSL_FREQ_PIN2), add_pulse1, RISING);
attachInterrupt(digitalPinToInterrupt(TSL_FREQ_PIN3), add_pulse2, RISING);
attachInterrupt(digitalPinToInterrupt(TSL_FREQ_PIN4), add_pulse3, RISING);
attachInterrupt(digitalPinToInterrupt(TSL_FREQ_PIN5), add_pulse4, RISING);
attachInterrupt(digitalPinToInterrupt(TSL_FREQ_PIN6), add_pulse5, RISING);
attachInterrupt(digitalPinToInterrupt(TSL_FREQ_PIN7), add_pulse6, RISING);
}


void loop() {
  
unsigned long currentMillis = millis();



if (currentMillis - previousMillis >= integration_time) { //set the integration time period
#if ECHO_TO_SERIAL
  Serial.print("well_1,"); //number of the well
  Serial.print(millis()/60000); //time in minutes
  Serial.print(", ");    
  Serial.print(pulse_cnt_well_1); //number of pulses
  Serial.println(); 

  Serial.print("well_2,");
  Serial.print(millis()/60000);
  Serial.print(", ");    
  Serial.print(pulse_cnt_well_2);
  Serial.println(); 

  Serial.print("well_3,");
  Serial.print(millis()/60000);
  Serial.print(", ");    
  Serial.print(pulse_cnt_well_3);
  Serial.println(); 

  Serial.print("well_4,");
  Serial.print(millis()/60000);
  Serial.print(", ");    
  Serial.print(pulse_cnt_well_4);
  Serial.println(); 

  Serial.print("well_5,");
  Serial.print(millis()/60000);
  Serial.print(", ");    
  Serial.print(pulse_cnt_well_5);
  Serial.println(); 

  Serial.print("well_6,");
  Serial.print(millis()/60000);
  Serial.print(", ");    
  Serial.print(pulse_cnt_well_6);
  Serial.println(); 

#endif
previousMillis = currentMillis;
//reset values for the next period
pulse_cnt_well_1=0;
pulse_cnt_well_2=0;
pulse_cnt_well_3=0;
pulse_cnt_well_4=0;
pulse_cnt_well_5=0;
pulse_cnt_well_6=0;
}
}

void add_pulse1() {

  // increase pulse count
  pulse_cnt_well_1++;
  return;
}
void add_pulse2() {

  // increase pulse count
  pulse_cnt_well_2++;
  return;
}
void add_pulse3() {

  // increase pulse count
  pulse_cnt_well_3++;
  return;
}
void add_pulse4() {

  // increase pulse count
  pulse_cnt_well_4++;
  return;
}
void add_pulse5() {

  // increase pulse count
  pulse_cnt_well_5++;
  return;
}
void add_pulse6() {

  // increase pulse count
  pulse_cnt_well_6++;
  return;
}
