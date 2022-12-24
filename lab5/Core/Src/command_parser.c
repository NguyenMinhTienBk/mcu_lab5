/*
 * command_parser.c
 *
 *  Created on: Dec 24, 2022
 *      Author: pc
 */

#include "command_parser.h"

enum CommandParserState{Wait_BeginChar , Wait_EndChar};
enum CommandParserState comparstate = Wait_BeginChar;

uint8_t temp = 0;
uint8_t index_buffer = 0;
uint8_t buffer[MAX_BUFFER_SIZE];

int command_flag = 0;

uint8_t command_data[MAX_BUFFER_SIZE];
char index_commmand = 0;

void command_parser_fsm(void){
	switch (comparstate){
	case Wait_BeginChar:
		if (temp == '!'){
			comparstate = Wait_EndChar;

		}
		break;
	case Wait_EndChar:
		if (temp == '#'){
			comparstate = Wait_BeginChar;
			command_flag = 1;
			index_buffer = 0;
			index_commmand = 0;
//			clerCommand();
		} else {
			command_data[index_commmand] = temp;
			index_commmand++;
		}
		break;
	default:
		break;

	}
}
unsigned char CompareCommand(char resp[], size_t num){
	return strncmp((const char *)command_data, resp, num) == 0;
//	if (resp == "RST" )
//	case "RST":
//		if (command_data[0] == 'R' && command_data[2] == 'S' && command_data[3] == 'T'){
//			return 1;
//		}
//		break;
//	case "OK":
//		if (command_data[1] == 'O' && command_data[2] == 'K' ){
//			return 1;
//		}
//		break;
//	default:
//		break;
//	}
//	return 0;
}

void clerCommand(void){
//	*command_data = "";
	for( char i = 0; i < MAX_BUFFER_SIZE;  ++i )
		command_data[i] = (char)0;
}
