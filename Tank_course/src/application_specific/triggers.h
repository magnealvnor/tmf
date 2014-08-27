/*
 * triggers.h
 *
 * Created: 18.08.2014 17:10:13
 *  Author: magne.normann
 */ 


#ifndef TRIGGERS_H_
#define TRIGGERS_H_

#define TRIGGER1_PIN	PIN_PB00A_EIC_EXTINT0 
#define TRIGGER1_MUX	MUX_PB00A_EIC_EXTINT0
#define TRIGGER1_LINE	0
#define TRIGGER1_PULL	EXTINT_PULL_UP
#define TRIGGER1_DETECT	EXTINT_DETECT_BOTH

#define TRIGGER2_PIN	PIN_PB01A_EIC_EXTINT1 
#define TRIGGER2_MUX	MUX_PB01A_EIC_EXTINT1
#define TRIGGER2_LINE	1		//somehting wrong with the line???
#define TRIGGER2_PULL	EXTINT_PULL_UP
#define TRIGGER2_DETECT	EXTINT_DETECT_BOTH

void configure_trigger1_channel(void);
void configure_trigger1_callbacks(void);
void trigger1_detection_callback(void);

void configure_trigger2_channel(void);
void configure_trigger2_callbacks(void);
void trigger2_detection_callback(void);

#endif /* TRIGGERS_H_ */