/**
******************************************************************************
@brief Header for unit test
@file unit_test.h
@author jonls@kth.se
******************************************************************************
*/

#include "unity.h"
#include "stdio.h"

void unit_test(void);
void setUp(void);
void tearDown(void);
void test_esp8266_init(void);
void test_esp8266_wifi_connect(void);
void test_esp8266_web_connection(void);
void test_esp8266_web_request(void);
void test_esp8266_at_send(char*);
void test_esp8266_send_data(char*);


