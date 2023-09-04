


#include <SPI.h> // Kütüphaneleri Tanımlıyoruz
#include <RF24.h>
#include <RF24_config.h>
#include <nRF24L01.h>
int data[1];
RF24 radio(9,10);//CE -> 9 CSN -> 10
const uint64_t pipe = 0xE8E8F0F0E1LL;
int potpin = 0;
int Potdeger;
void setup(void){
radio.begin();
radio.openWritingPipe(pipe);
}
void loop(void){
Potdeger = analogRead(potpin);
Potdeger = map(Potdeger, 0, 1023, 0, 179);
data[0] = Potdeger;
radio.write(data, 1);
}


