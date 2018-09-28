# Data-transfer-through-ESP8266

Hardware used during development 

    • ESP-01 ESP8266 Serial WiFi Wireless Transceiver Module.
    • ESP8266 programmer CH340G chip adapter.
    • USB To RS232 RS-232(DB9) Standard Serial Cable Converter.
    • RS232 to TTL  converter module.
    • PC with LINUX OS.

Software used during development

    • Arduino IDE 1.8.5
      
Configuring ESP8266 using Arduino IDE 

    • Download Arduino IDE from   https://www.arduino.cc/en/Main/Software.
    • Go to File > Preferences.
         In Preferences paste “http://arduino.esp8266.com/stable/package_esp8266com_index.json ”  in Additional Boards Manager URLs.
    • click OK.
    • Then Go to Tools > Boards > Boards Manager  
       	In board manager search for “   esp8266 by esp8266 community     ” and click install.
    • Then Go to Tools > Board > Generic ESP8266 Module.
    • Tools > Reset Mode > ck.
    • Tools >  Upload Speed > 115200.
    • Then select preffered port in which ESP is connected. 

Flashing ESP8266

	Before flashing we need to set the ESP in Flash Mode. For putting ESP-01 in flash mode, before powering it ON we need to short GPIO0 and GND using a jumper.After giving power remove the jumper. Then write the code and click upload button.	 

	If ESP8266 is not in flash mode while uploading sketch ,it will show errors like this

• An error occurred while uploading the sketch
• warning: espcomm_sync failed
• error: espcomm_open failed
• error: espcomm_upload_mem failed

Working

	The data from milk analyzer  (host device) is continuously send to ESP WiFi Module via RS232 port. WiFi Module is configured in such a way that it should connect to a router with an SSID and PASSWORD and to a client device with a ststic IP. It should send data from RS232 to a particular PORT (in program 2222) in the network. On the other side the client device should continuously listen to the same PORT so that it can read data send by ESP WiFi Module to the PORT.

TESTING CODE

    • Upload the code usiing arduino IDE.
    • Connect Host machine and Client machine to same router to which the ESP WiFi Module is connected.
    • Make sure that the IP address of Client machine should match with IP address mentioned in code
      
Client machine(Linux PC)

    • Open terminal (Alt+Ctrl+T)
    • Type  nc -l -p PORT (nc -l -p 2222)  to listen to the data coming through that port.
      
Host machine(Linux PC)

    • To send data – open  terminal window and type
       echo “ data  ” >  /dev/ttyUSB* 
    • Press enter.

	The data send from the Host Machine can be seen on the Terminal Window of client  machine.


TEST PASSED

    • SSID loss                 passed
    • TCP loss                  passed
    • RS232 loss                passed
    • Client machine restart    passed
    • Host machine restart      passed
    • WiFi Module restart       passed
