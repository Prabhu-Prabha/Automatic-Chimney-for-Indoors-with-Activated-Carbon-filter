/* MQ-7 Carbon Monoxide Sensor Circuit with Arduino */

const int AOUTpin=0;//the AOUT pin of the CO sensor goes into analog pin A0 of the arduino
const int DOUTpin=8;//the DOUT pin of the CO sensor goes into digital pin D8 of the arduino
const int fan=13;//the anode of the LED connects to digital pin D13 of the arduino

int limit;
int value;

void setup() {
Serial.begin(9600);//sets the baud rate
pinMode(DOUTpin, INPUT);//sets the pin as an input to the arduino
pinMode(fan, OUTPUT);//sets the pin as an output of the arduino
}

void loop()
{
value= analogRead(AOUTpin);//reads the analaog value from the CO sensor's AOUT pin
limit= digitalRead(DOUTpin);//reads the digital value from the CO sensor's DOUT pin
Serial.print("CO value: ");
Serial.println(value);//prints the CO value
Serial.print("Limit: ");
Serial.println(limit);//prints the limit reached as either LOW or HIGH (above or underneath)
delay(1000);
if (value > 200)
{
digitalWrite(fan, LOW);//if limit has been reached, LED turns on as status indicator
}
else
{
digitalWrite(fan, HIGH);//if threshold not reached, LED remains off
}
}
