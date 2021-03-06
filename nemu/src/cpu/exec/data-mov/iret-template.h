#include "cpu/exec/template-start.h"

#define instr iret

void load_sreg(uint32_t);

static void do_execute() {
	cpu.eip = swaddr_read(cpu.esp, 4, R_SS);
	cpu.esp += 4;
	
	cpu.cs = swaddr_read(cpu.esp, 4, R_SS);
	cpu.esp += 4;
	load_sreg(R_CS);

	cpu.EFLAGS.all_EFLAGS = swaddr_read(cpu.esp, 4, R_SS);
	cpu.esp += 4;
	//cpu.eip -= 1;
	//printf("in iret: eip=%x\n", cpu.eip);
	print_asm("iret");
}


make_instr_helper(n)

#include "cpu/exec/template-end.h"
