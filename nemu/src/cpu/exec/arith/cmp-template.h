/*************************************************************************
    > File Name: cmp-template.h
    > Author: Chen Kan
    > Mail: 14307130198@fudan.edu.cn 
    > Created Time: 2015年11月22日 星期日 15时33分45秒
 ************************************************************************/
#include "cpu/exec/template-start.h"

#define instr cmp

static void do_execute()
{
	/*
	int bits = DATA_BYTE << 3;
//	uint32_t mask = (1 << bits) - 1;
	uint32_t a = op_dest->val;
	uint32_t b = op_src->val;
	uint32_t ans = a - b;
	
	cpu.EFLAGS.CF = (b > a);
	cpu.EFLAGS.ZF = !ans;
	cpu.EFLAGS.OF = ((a ^ b ^ (a-b)) >> 31) & 1;
	cpu.EFLAGS.SF = ((a - b) >> 31) & 1;
	uint32_t tmp = 1;
	int i;
	for (i = 0; i < bits-1; i++)
	{
		tmp &= (ans & 1);
		ans >>= 1;
	}
	cpu.EFLAGS.PF = tmp & 1;
*/

	int bits = DATA_BYTE << 3;
	DATA_TYPE mask = (1 << bits) - 1;
	DATA_TYPE a = op_dest->val & mask;
	DATA_TYPE b = op_src->val & mask;
	DATA_TYPE ans = op_dest->val - op_src->val;
	
	cpu.EFLAGS.CF = (b > a);
	cpu.EFLAGS.ZF = (a - b == 0);
	cpu.EFLAGS.OF = ((a ^ b ^ (a-b)) >> 31) & 1;
	cpu.EFLAGS.SF = MSB(ans);

	DATA_TYPE tmp = ans & 0xffff;
	tmp = tmp & (tmp >> 4);
	tmp = tmp & (tmp >> 2);
	tmp = tmp & (tmp >> 1);
	cpu.EFLAGS.PF = tmp & 1;

	print_asm_template2();
}

#if DATA_BYTE == 2 || DATA_BYTE == 4
make_instr_helper(si2rm)
make_instr_helper(r2rm)
#endif

#include "cpu/exec/template-end.h"
