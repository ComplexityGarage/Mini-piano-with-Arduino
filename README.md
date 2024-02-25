# ExemplaryProject 5 (Mini piano with Arduino, multiplexer and DFPlayer mini)
# Authors 
- Natalia Nowosada
- Jakub Wolak
  
# Tech used:
- Arduino
- multiplexer 16x4
- speaker
- DFPlayer mini
- SIM card
- 11 buttons
- 11 resistors 4,7k Ohm + 10k Ohm resistor
- a lot of wires
# Description of the project 
The idea behind our project was to create mini piano using Arduino. Since we wanted each button to play one note and have many keys, we decided to use multiplexer for the inputs instead of connecting each button/key directly to Arduino pins. Ultimately the piano designed by us has a range of C4 -Bb4 (chromatic scale) which is 11 keys, but with this design its possible for the maximum of 16 keys through multiplexer + 8 with the Arduino pins which are unused, which gives us maximum of 24 keys (almost 2 octaves). 

For the sound we have desided to use a DFPlayer mini with SIM card where the mp3 files of each note is stored and a simple speaker connected to it.

How it works:

![IMG_9911](https://github.com/ComplexityGarage/ExemplaryProject5/assets/125824728/3e5b594a-a21f-42d0-b860-1ae94c460d25)

Multiplexer:

We have got a multiplexer with 11 out of 16 of the inputs connected to each button. Every button is also powered with constant voltage of 5V and when the button is pressed, the high voltage can be read by Arduino. We have also got a pull-down resistor so when button is not pressed, the voltage read by Arduino is 0V. 
To read the signal we must also connect multiplexer to Arduino: outputs S0 to S3 are connected to pins 13 to 10 (see the code below), SIG to A0, EN and GND to ground and VCC to 5V.

In the code we use "void MuxChannel(byte channel)" to select a multiplexer channel and when the channel is selected, we can read its signal using "digitalRead(sig)". In the code we check every active channel (here there are 11 channels cheking the state of each button) and if the signal is high (button pressed), we play a sound.

DFPLayer mini:
We conneect it to Arduino: VCC to 5V, GND to ground, RX to pin 1<-TX (through high resistance resistor, 10k Ohm), TX to pin 0->RX on Arduino and speaker to SPK_1 and SPK_2.
On SIM card we have got mp3 files named 0001.mp3, 0002.mp3, ... and so on. Each file is a unique sound of a piano note. 
* When updating a code you must disconnect a wire connected to 0->RX pin on Arduino and when the code is uploaded to Arduino you connect it back again. If you don't do it then there is an error and you can't upload the code.

Code:

#include <SoftwareSerial.h> &emsp; &emsp;//essential for communicating with RX and TX pins <br />
#include <DFPlayer_Mini_Mp3.h> &emsp; &emsp;//essential for mp3_play() command

const int s0 = 13;<br />
const int s1 = 12;<br />
const int s2 = 11;<br />
const int s3 = 10;<br />
const int sig = A0;

void MuxChannel(byte channel){&emsp;&emsp;//selects a channel<br />
&emsp;  digitalWrite(s0, bitRead(channel, 0));<br />
&emsp;  digitalWrite(s1, bitRead(channel, 1));<br />
 &emsp; digitalWrite(s2, bitRead(channel, 2));<br />
 &emsp; digitalWrite(s3, bitRead(channel, 3));<br />
}

void setup()<br />
{<br />
&emsp;  pinMode(s0, OUTPUT); <br />
&emsp;  pinMode(s1, OUTPUT); <br />
 &emsp; pinMode(s2, OUTPUT); <br />
 &emsp; pinMode(s3, OUTPUT); <br />
 &emsp; Serial.begin(9600);<br />

 &emsp; mp3_set_serial(Serial);&emsp; &emsp;//set Serial for DFPlayer-mini mp3 module <br />
 &emsp; mp3_set_volume(30);   &emsp; &emsp; // set volume of speaker (0~30)<br />
}

void loop()<br />
{<br />
  &emsp;MuxChannel(0); &emsp;&emsp;//select channel 0 <br />
 &emsp; if (digitalRead(sig) == HIGH) {<br />
   &emsp;&emsp; mp3_play(12);&emsp;&emsp;//if buttons is pressed play a note <br />
    &emsp;}<br />

  &emsp;MuxChannel(1);<br />
  &emsp;if (digitalRead(sig) == HIGH) {<br />
   &emsp;&emsp; mp3_play(11); <br />
    &emsp;}  <br />

  &emsp;MuxChannel(2);<br />
  &emsp;if (digitalRead(sig) == HIGH) {<br />
   &emsp;&emsp; mp3_play(10); <br />
   &emsp; }  <br />

  &emsp;MuxChannel(3);<br />
  &emsp;if (digitalRead(sig) == HIGH) {<br />
  &emsp;&emsp;  mp3_play(9); <br />
   &emsp; }  <br />

 &emsp; MuxChannel(4);<br />
 &emsp; if (digitalRead(sig) == HIGH) {<br />
  &emsp;&emsp;  mp3_play(8); <br />
   &emsp; } <br />

 &emsp; MuxChannel(5);<br />
  &emsp;if (digitalRead(sig) == HIGH) {<br />
  &emsp;&emsp;  mp3_play(7); <br />
  &emsp;  }  <br />

 &emsp; MuxChannel(6);<br />
 &emsp; if (digitalRead(sig) == HIGH) {<br />
  &emsp;&emsp;  mp3_play(6); <br />
   &emsp; }  <br />

 &emsp; MuxChannel(7);<br />
 &emsp; if (digitalRead(sig) == HIGH) {<br />
  &emsp;&emsp;  mp3_play(5); <br />
  &emsp;  }  <br />

 &emsp; MuxChannel(8);<br />
 &emsp; if (digitalRead(sig) == HIGH) {<br />
 &emsp;&emsp;   mp3_play(4); <br />
  &emsp;  }  <br />

  &emsp;MuxChannel(9);<br />
  &emsp;if (digitalRead(sig) == HIGH) {<br />
  &emsp;&emsp;  mp3_play(3);  <br />
  &emsp;  }  <br />

  &emsp;MuxChannel(10);<br />
  &emsp;if (digitalRead(sig) == HIGH) {<br />
   &emsp;&emsp; mp3_play(2); <br />
  &emsp;  }  <br />
}

# State of the art:
Very butiful:
zdjęcie:
# What next?
null
# Sources 

