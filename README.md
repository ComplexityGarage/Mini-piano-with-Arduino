# Mini piano with Arduino, multiplexer and DFPlayer mini
# Authors 
- Natalia Nowosada
- Jakub Wolak
  
# Tech used:
- Arduino Uno R3
- multiplexer 16 to 4
- speaker
- DFPlayer mini
- SIM card
- 11 buttons
- 11 resistors 4,7k Ohm + 10k Ohm resistor
- a lot of wires
- 3D printer for piano keys
# Description of the project 
The idea behind our project was to create mini piano using Arduino. Since we wanted each button to play one note and have many keys, we decided to use multiplexer for the inputs instead of connecting each button/key directly to Arduino pins. Ultimately the piano designed by us has a range of C4 -Bb4 (chromatic scale) which is 11 keys, but with this design its possible for the maximum of 16 keys through multiplexer + 8 with the Arduino pins which are unused, which gives us maximum of 24 keys (almost 2 octaves). 

For the sound we have desided to use a DFPlayer mini with SIM card where the mp3 files of each note is stored and a simple speaker connected to it.

How it works:

Circuit diagram: 

![IMG_0864](https://github.com/ComplexityGarage/ExemplaryProject5/assets/125824728/317f2261-d7fe-4e53-8da5-028def02ff8d)


![IMG_9911](https://github.com/ComplexityGarage/ExemplaryProject5/assets/125824728/3e5b594a-a21f-42d0-b860-1ae94c460d25)

Multiplexer:

We have got a multiplexer with 11 out of 16 of the inputs connected to each button. Every button is also powered with constant voltage of 5V and when the button is pressed, the high voltage can be read by Arduino. We have also got a pull-down resistor so when button is not pressed, the voltage read by Arduino is 0V. 
To read the signal we must also connect multiplexer to Arduino: outputs S0 to S3 are connected to pins 13 to 10 (see the code below), SIG to A0, EN and GND to ground and VCC to 5V.

In the code we use "void MuxChannel(byte channel)" to select a multiplexer channel and when the channel is selected, we can read its signal using "digitalRead(sig)". In the code we check every active channel (here there are 11 channels cheking the state of each button) and if the signal is high (button pressed), we play a sound.

DFPLayer mini:
We conneect it to Arduino: VCC to 5V, GND to ground, RX to pin 1<-TX (through high resistance resistor, 10k Ohm), TX to pin 0->RX on Arduino and speaker to SPK_1 and SPK_2.
On SIM card we have got mp3 files named 0001.mp3, 0002.mp3, ... and so on. Each file is a unique sound of a piano note. 
* When updating a code you must disconnect a wire connected to 0->RX pin on Arduino and when the code is uploaded to Arduino you connect it back again, otherwise the error occurs.

&emsp;Code:

https://github.com/ComplexityGarage/ExemplaryProject5/blob/main/piano_code.ino

# State of the art:
![IMG_0113](https://github.com/ComplexityGarage/ExemplaryProject5/assets/125824728/831e3ea5-9e71-43f5-909c-10d0fc86135e)

We printed piano keys with little pillars underneath and glued it to each button.

# What next?
There are a few things that can be improved:
- the speaker is very quiet, for improvement you could use for example a sound amplifier or a better speaker.
- piano keys are not very reliable, they are hard to press; for improvement you could use bigger buttons or just use a diffrent method of pressing the buttons with the keys; also gluing keys with buttons using hot glue may not be most optimal idea because buttons can stop working when there is too much glue.
- stability of construction and overall design of piano could be improved
# Sources 
https://github.com/fuhton/piano-mp3/tree/master/piano-mp3

https://botland.store/16-bit-multiplexers/1630-module-with-analog-digital-multiplexer-74hc4067--5904422369842.html

https://botland.store/mp3-wav-ogg-midi-players/3170-dfplayer-mini-mp3-player-with-microsd-slot-6959420902521.html

https://www.youtube.com/watch?v=Dco6jo9xgAo&t=1s

https://mytectutor.com/mp3-player-using-dfplayer-and-arduino/




