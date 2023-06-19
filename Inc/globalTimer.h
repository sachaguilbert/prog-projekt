/*
 * globalTimer.h
 *
 *  Created on: 13. jun. 2023
 *      Author: alber
 */

#ifndef GLOBALTIMER_H_
#define GLOBALTIMER_H_

extern volatile uint16_t announcTick;
extern volatile uint8_t globalTick;
void TIM1_BRK_TIM15_IRQHandler(void);
void tim15Setup();


#endif /* GLOBALTIMER_H_ */
