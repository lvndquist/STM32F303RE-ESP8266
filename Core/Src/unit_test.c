/**
******************************************************************************
@brief unit test
@file unit_test.c
@author  jonls@kth.se
@date 29-03-2021
@version 1.0
******************************************************************************
*/

#include "unit_test.h"
#include "stdio.h"
#include "ESP8266.h"

#define RUN_ESP8266_TEST

void unit_test(void){


/* Test begin */
UNITY_BEGIN();

/* Run test for ESP8266 */
#ifdef RUN_ESP8266_TEST

	/* Init should be here, else it will break the esp when first plugging it in.
	   This init is for UART4 and needs to be changed if the module is connected
	   on different pins 														 */
	MX_UART4_Init();

	/* Set up interrupt for ESP*/
	init_uart_interrupt();

	/* Test initiation of ESP8266 */
  	RUN_TEST(test_esp8266_init);

    /* Test connecting to wifi */
    RUN_TEST(test_esp8266_wifi_connect);

    /* Test connecting to a website */
    RUN_TEST(test_esp8266_web_connection);

    /* Test making a http web request to connected website */
    RUN_TEST(test_esp8266_web_request);
    HAL_Delay(2000);

#endif

/* Test end*/
UNITY_END();
}

/* Setup */
void setUp(void){}

/* Teardown */
void tearDown(void){}


void test_esp8266_init(void){
	TEST_ASSERT_EQUAL_STRING(ESP8266_AT_OK, esp8266_init());
}

void test_esp8266_wifi_connect(void){
	TEST_ASSERT_EQUAL_STRING(ESP8266_AT_WIFI_CONNECTED, esp8266_wifi_init());
}

void test_esp8266_web_connection(void){
	char connection_command[256] = {0};
	char remote_ip[] = "";
	char type[] = "TCP";
	char remote_port[] = "80";
	esp8266_get_connection_command(connection_command, type, remote_ip, remote_port);
	TEST_ASSERT_EQUAL_STRING(ESP8266_AT_CONNECT, esp8266_send_command(connection_command));
}

void test_esp8266_web_request(void){

	char request[256] = {0};
	char init_send[64] = {0};
	char uri[] = "";

	char host[] = "";

	//	uint8_t len = esp8266_http_get_request(request, HTTP_GET, uri, host);
	uint8_t len = esp8266_http_get_request(request, HTTP_POST, uri, host);
	esp8266_get_at_send_command(init_send, len);

	test_esp8266_at_send(init_send);
	test_esp8266_send_data(request);
}

void test_esp8266_at_send(char* init_send){
	TEST_ASSERT_EQUAL_STRING(ESP8266_AT_SEND_OK, esp8266_send_command(init_send));
}

void test_esp8266_send_data(char* request) {
	TEST_ASSERT_EQUAL_STRING(ESP8266_AT_CLOSED, esp8266_send_data(request));
}
