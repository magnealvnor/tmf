/*
 * gates.c
 *
 * Created: 14.07.2014 10:59:45
 *  Author: magne.normann
 */ 

#include "conf_application.h"
#include "gates.h"

/* Initialization of the two servos used to drive the Abot */
void gates_init(void)
{
	struct tcc_config config_gates;
	tcc_get_config_defaults(&config_gates, CONF_GATES_MODULE);
	
	/* Generate Single Slope PWM signals with period set to 20 ms */
	config_gates.counter.period				= PWM_COUNTER_PERIOD;
	config_gates.counter.clock_source		= GCLK_GENERATOR_3;		// 8 Mhz
	config_gates.counter.clock_prescaler	= TCC_CLOCK_PRESCALER_DIV8;
	config_gates.compare.wave_generation	= TCC_WAVE_GENERATION_SINGLE_SLOPE_PWM;
	
	/* Set default speed to zero. (Motors are operational in the range [1200:1900] */
	config_gates.compare.match[CONF_GATES_CHANNEL]		= NEUTRAL;

	/* Enable PWM Output on pins defined in the conf_motor header */
	config_gates.pins.enable_wave_out_pin[CONF_GATES_OUTPUT]	= true;
	config_gates.pins.wave_out_pin[CONF_GATES_OUTPUT]			= CONF_GATES_OUT_PIN;
	config_gates.pins.wave_out_pin_mux[CONF_GATES_OUTPUT]		= CONF_GATES_OUT_MUX;
	
	/* Configuration is done! initialize the gates */
	tcc_init(&gates, CONF_GATES_MODULE, &config_gates);
	tcc_enable(&gates);
}

/************************************** Gate Commands **********************************************/

void gates_unblock_start_line(void){
	TCC0->CC[2].reg = OPEN_START;
}

void gates_unblock_finish_line(void){
	TCC0->CC[2].reg = OPEN_FINISH;
}
