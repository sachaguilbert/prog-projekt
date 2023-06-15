/*
 * ADC.h
 *
 *  Created on: 8. jun. 2023
 *      Author: alber
 */

#ifndef ADC_H_
#define ADC_H_


uint16_t ADCRead(uint8_t sel);
void movement(player_t *p,bullet_t *b);
void ADCSetup();
#endif /* ADC_H_ */
