# STM32F303RE-ESP8266
This project has basic functionality for using the ESP8266 wifi module with a STM32 microcontroller. 
Has been tested using the F303RE, and L476RG. 

See unity_test.c for usage. 

Note this is not an optimal solution, no ring buffer, and unnecessary hash function (commands dont need to return strings...)
