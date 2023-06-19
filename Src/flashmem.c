#include "flashmem.h"

uint16_t memRead(uint16_t offset){
	uint32_t baseAddress = 0x0800F800;
	uint16_t returnVal;
	returnVal = *(uint16_t *)(baseAddress + offset*2); // Read Command
	return returnVal;
}

void memWrite(uint16_t *in,uint8_t sizeofarr){
	uint32_t baseAddress = 0x0800F800;
	FLASH_Unlock();
	FLASH_ClearFlag( FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPERR );
	FLASH_ErasePage( baseAddress );
	for(uint16_t i = 0; i<sizeofarr;i++){
		FLASH_ProgramHalfWord(baseAddress+i*2, in[i]);
	}
	FLASH_Lock();
}

void clearFlashMem(){
	uint32_t baseAddress = 0x0800F800;
	FLASH_Unlock();
	FLASH_ClearFlag( FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPERR );
	FLASH_ErasePage( baseAddress );
	FLASH_ProgramHalfWord(baseAddress, 0);
	FLASH_Lock();
}
