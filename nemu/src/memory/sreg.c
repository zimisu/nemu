#include "common.h"
#include "../../lib-common/x86-inc/mmu.h"
#include "cpu/reg.h"

uint32_t lnaddr_read(hwaddr_t, size_t);
uint32_t hwaddr_read(hwaddr_t, size_t);
uint32_t hwaddr_write(hwaddr_t, size_t, uint32_t);

void init_seg() {	
	uint8_t tmp[8];	
	cpu.cs = 8;
	/*
	printf("%d %d %d %d----\n", cpu.sr[0]._16, cpu.sr[1]._16, cpu.sr[2]._16, cpu.sr[3]._16);
	printf("%llu %llu %llu %llu\n", 
		(unsigned long long)cpu.sr[0].value, 
		(unsigned long long)cpu.sr[1].value, 
		(unsigned long long)cpu.sr[2].value, 
		(unsigned long long)cpu.sr[3].value);
	printf("R_CS:%d\n  cs:%d  es index:%d\n", R_CS, cpu.cs, cpu.sr[R_CS].index);
	*/
	SegDesc *segdesc = (SegDesc*)tmp;
	segdesc->present = 1;
	segdesc->base_31_24 = segdesc->base_23_16 = segdesc->base_15_0 = 0;
	segdesc->limit_19_16 = segdesc->limit_15_0 = -1;
	cpu.sr[R_CS].invi = *segdesc;
	/*
	printf("R_CS:%d\n  _16:%d  %d %d es index:%d\n", R_CS, cpu.sr[R_CS]._16, 
		cpu.sr[R_CS].rpl, 
		cpu.sr[R_CS].ti, 
		cpu.sr[R_CS].index);


	printf("%d %d %d %d----\n", cpu.sr[0]._16, cpu.sr[1]._16, cpu.sr[2]._16, cpu.sr[3]._16);
	printf("%llu %llu %llu %llu\n", 
		(unsigned long long)cpu.sr[0].value, 
		(unsigned long long)cpu.sr[1].value, 
		(unsigned long long)cpu.sr[2].value, 
		(unsigned long long)cpu.sr[3].value);
		*/
	cpu.cr._[0] = cpu.cr._[3] = 0;
	/*
	int i;
	
	for (i = 0; i < 8; i++)
		printf("%x\n", tmp[i]);
		*/
	//printf("--------------%x  %x\n", *(int*)segdesc, *((int*)segdesc) + 1);
}

lnaddr_t seg_translate(swaddr_t addr, uint8_t sreg) {
	SegDesc *segdesc = &cpu.sr[sreg].invi;
	int result = (segdesc->base_31_24 << 24) + 
		(segdesc->base_23_16 << 16) + 
		segdesc->base_15_0 + addr;
	//printf("seg_translate: sreg:%d   %x\n", sreg, result);	
	return result;
}

void load_sreg(uint32_t sreg) {
	uint8_t tmp[8]; 
	int i;
	for(i = 0; i < 8; ++ i) 
		tmp[i] = lnaddr_read(cpu.GDTR.base + cpu.sr[sreg].index * 8 + i, 1);
	SegDesc *segdesc = (SegDesc*)tmp;

	//printf("sreg:%d\n", sreg);
	/*
	for (i = 0; i < 8; i++)
		printf("%x\n", tmp[i]);*/
	Assert(segdesc->present == 1, "Segdesc is not valid! 0x%x  segdesc::0x%x %x", 
		cpu.GDTR.base + cpu.sr[sreg].index * 8, *(int*)segdesc, *((int*)segdesc) + 1);
	Assert(cpu.sr[sreg].index * 8 < (segdesc->limit_19_16 << 16) + segdesc->limit_15_0, "Segment overflow!");
	cpu.sr[sreg].invi = *segdesc;
}


