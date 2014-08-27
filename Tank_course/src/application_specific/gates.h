/*
 * gates.h
 *
 * Created: 14.07.2014 11:02:30
 *  Author: magne.normann
 */ 


#ifndef GATES_H_
#define GATES_H_

#define PWM_COUNTER_PERIOD	20000-1 // (GCC0/TCC_prescaler)*(1/F_PWM)-1

#define NEUTRAL				1500
#define OPEN_START			2400
#define OPEN_FINISH			540

struct tcc_module gates;

void gates_init(void);
void gates_unblock_start_line(void);
void gates_unblock_finish_line(void);



#endif /* GATES_H_ */