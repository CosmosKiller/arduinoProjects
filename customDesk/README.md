# :computer: :bulb: Custom Smart Desk :satellite: :electric_plug:

With this project, the idea is to have multiple outlets that can be controlled remotelly, using a virtual assistant app like Google Assistant or Alexa. Also, including RGB led strips controll and a temperature sensor* is a goal.
>_***Note:**_  In futhure iterations and depending on the asisstant capabilities, the temperature sensor might trigger some other routines or actions for devices that aren´t part of the desk itself ; Like turning on an AC or a heater based on the room temperature  

For the moment i've decided to go with Alexa as the assistant as it has a built skill for the Arduino IoT Cloud. And, as I'm using it as the main cloud platform, choice was fairly simple. That's pretty much it for the SW side ; in the HW side, I'm using an NodeMCU ESP8266 v1.0 in STA mode, to establish connection to the internet, and an Arduino Mega2560 as the powerhouse to controll all of the devices (Outlets, RGB Leds and Sensors) and the algorithms to make them work properly. The communication between the two boards is via the serial pins (TX/RX for the ESP and TX1/RX1 for the Mega)

I'll try to make a blog to be able to make a register, whenever i feel i've made good progress. So, stay tuned for updates.

-  **10/17/2021:** I accomplished the make the first functional prototype:exclamation::sparkles:I used all of the five variables the the free plan of IoT Cloud gives you, so... i need to workaroud this issue. I ran out of variables, an I'm only able to controll 5 of the 8 outlets ; No room for RGB controller nor for the sensors. I've gotta find a better solution, but for the moment i'm happy that i can connect to Alexa and send voice command to controll the outlets:grin:
-  **10/18/2021:** With couple of tweaks here an there, I managed to use only 1 variable to control all of the different devices. Because I'm using a "CloudDimmedLight" variable an its getBrightness() method, I've created some routines on Alexa so that the voice commands doesn't sound weird when I call them:dizzy_face:It isn't really intuitive to say something like "Set the brightness of 'x' device to 8" in order to turn on an smart plug, right?:sweat_smile::satisfied:
- **10/22/2021:** Think I'm making good progress here:rocket:With a little bit of research and consulting official Arduino documentation, I got to make bidirectional communication between the ESP and the Mega so now I can push temperature measurements to Alexa app:tada:I also created two more Alexa compatible variables, one for the RGB Led controller and the other one for temperature readings:star2:

### To summarize, I'd love to recibe feedback and tips, so feel free to do it. This project is, above all, a personal challenge and a quest to develop myself as a professional.

## Copyright © 2021 Marcel Nahir Samur
