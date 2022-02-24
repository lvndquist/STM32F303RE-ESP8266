# STM32F303RE-ESP8266
This project has basic functionality for using the ESP8266 wifi module with a STM32 microcontroller. 
The implemented functions make it possible to make simple http requests. 
Has been tested using the F303RE, and L476RG. 

See unity_test.c for usage. 


### add /inc/login.h
     #ifndef INC_LOGIN_H_
     #define INC_LOGIN_H_

     static const char SSID[] = "One Plus 5"; // your ssid
     static const char PWD[]  = "password"; // your password

     #endif
