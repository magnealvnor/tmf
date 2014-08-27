/*
 * triggers.c
 *
 * Created: 18.08.2014 17:09:57
 *  Author: magne.normann
 */ 

#include <asf.h>
#include "triggers.h"
#include "gates.h"

void configure_trigger1_channel(void)
{
	struct extint_chan_conf config_extint_chan;
	extint_chan_get_config_defaults(&config_extint_chan);
	config_extint_chan.gpio_pin = TRIGGER1_PIN;
	config_extint_chan.gpio_pin_mux = TRIGGER1_MUX;
	config_extint_chan.gpio_pin_pull = TRIGGER1_PULL;
	config_extint_chan.detection_criteria = TRIGGER1_DETECT;
	extint_chan_set_config(TRIGGER1_LINE, &config_extint_chan);
}

void configure_trigger1_callbacks(void)
{
	extint_register_callback(trigger1_detection_callback,	TRIGGER1_LINE,	EXTINT_CALLBACK_TYPE_DETECT);
	extint_chan_enable_callback(TRIGGER1_LINE, EXTINT_CALLBACK_TYPE_DETECT);
}
void trigger1_detection_callback(void)
{
	uint8_t pin_state = port_pin_get_input_level(TRIGGER1_PIN);
	port_pin_set_output_level(TRIGGER1_PIN, pin_state);
	
	if(pin_state){
		gates_unblock_finish_line();
	}else{
		gates_unblock_start_line();
	}
}

void configure_trigger2_channel(void)
{
	struct extint_chan_conf config_extint_chan;
	extint_chan_get_config_defaults(&config_extint_chan);
	config_extint_chan.gpio_pin = TRIGGER2_PIN;
	config_extint_chan.gpio_pin_mux = TRIGGER2_MUX;
	config_extint_chan.gpio_pin_pull = TRIGGER2_PULL;
	config_extint_chan.detection_criteria = TRIGGER2_DETECT;
	extint_chan_set_config(TRIGGER2_LINE, &config_extint_chan);
}

void configure_trigger2_callbacks(void)
{
	extint_register_callback(trigger1_detection_callback,	TRIGGER2_LINE,	EXTINT_CALLBACK_TYPE_DETECT);
	extint_chan_enable_callback(TRIGGER2_LINE, EXTINT_CALLBACK_TYPE_DETECT);
}
void trigger2_detection_callback(void)
{
	uint8_t pin_state = port_pin_get_input_level(TRIGGER2_PIN);
	port_pin_set_output_level(TRIGGER2_PIN, pin_state);
	
	if(pin_state){
		gates_unblock_finish_line();
		}else{
		gates_unblock_start_line();
	}
}

