

#include <Servo.h>
#include <SPI.h>
#include <RF24.h>
#include <RF24_config.h>
#include <nRF24L01.h>
Servo ServoM;

RF24 radio(9,10);//CE -> 9 CSN -> 10
const uint64_t pipe = 0xE8E8F0F0E1LL;
int data[1];
void setup()
{
ServoM.attach(7);
radio.begin();
radio.openReadingPipe(1,pipe);
radio.startListening();
}
void loop()
{
if (radio.available()){
bool done = false;
while (!done){
done = radio.read(data, 1);
ServoM.write (data[0]);

}
}
}


