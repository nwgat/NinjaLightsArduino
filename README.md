# NinjaLightsArduino

* Turn off hue light group 1,2
* switch to USB input on Klipsch 14PM

# Parts

* [Wemos D1 Mini](https://docs.wemos.cc/en/latest/d1/d1_mini.html)
* [Wemos IR Shield](https://www.wemos.cc/en/latest/d1_mini_shiled/ir.html)

# setup

**infrared**

you need to find out your ir code with IRrecvDumpV2 by flashing your d1 mini and use the remote to capture the ir  code
https://github.com/wemos/D1_mini_Examples/blob/master/examples/04.Shields/IR_Controller_Shield/IRrecvDumpV2/IRrecvDumpV2.ino

**hue**
* Get your hue api key here https://developers.meethue.com/develop/get-started-2/
* You can find your hue ip here https://discovery.meethue.com/

**when everyting is built and flashed you can turn off the lights and switch input at 
http://yourD1MiniIP/on

# Dependencies

* https://github.com/tomvanrooij/ESPHue
* https://github.com/crankyoldgit/IRremoteESP8266
* https://github.com/wemos/D1_mini_Examples/tree/master/examples/04.Shields/IR_Controller_Shield/
