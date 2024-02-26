#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>

const int s0 = 13;
const int s1 = 12;
const int s2 = 11;
const int s3 = 10;
const int sig = A0;

void MuxChannel(byte channel){
  digitalWrite(s0, bitRead(channel, 0));
  digitalWrite(s1, bitRead(channel, 1));
  digitalWrite(s2, bitRead(channel, 2));
  digitalWrite(s3, bitRead(channel, 3));
}

void setup()
{
  pinMode(s0, OUTPUT); 
  pinMode(s1, OUTPUT); 
  pinMode(s2, OUTPUT); 
  pinMode(s3, OUTPUT); 
  Serial.begin(9600);

  mp3_set_serial(Serial);  //set Serial for DFPlayer-mini mp3 module 
  mp3_set_volume(30);      // set volume of speaker (0~30)
}

void loop()
{
  MuxChannel(0);      //select multiplexer channel 0
  if (digitalRead(sig) == HIGH) {
    mp3_play(12);     //if button is pressed, play 0012.mp3
    }

  MuxChannel(1);
  if (digitalRead(sig) == HIGH) {
    mp3_play(11); 
    }  

  MuxChannel(2);
  if (digitalRead(sig) == HIGH) {
    mp3_play(10); 
    }  

  MuxChannel(3);
  if (digitalRead(sig) == HIGH) {
    mp3_play(9); 
    }  

  MuxChannel(4);
  if (digitalRead(sig) == HIGH) {
    mp3_play(8); 
    } 

  MuxChannel(5);
  if (digitalRead(sig) == HIGH) {
    mp3_play(7); 
    }  

  MuxChannel(6);
  if (digitalRead(sig) == HIGH) {
    mp3_play(6); 
    }  

  MuxChannel(7);
  if (digitalRead(sig) == HIGH) {
    mp3_play(5); 
    }  

  MuxChannel(8);
  if (digitalRead(sig) == HIGH) {
    mp3_play(4); 
    }  

  MuxChannel(9);
  if (digitalRead(sig) == HIGH) {
    mp3_play(3); 
    }  

  MuxChannel(10);
  if (digitalRead(sig) == HIGH) {
    mp3_play(2); 
    }  
}

