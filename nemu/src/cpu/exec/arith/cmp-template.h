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
	//int bits = DATA_BYTE << 3;
	DATA_TYPE a = op_dest->val;
	DATA_TYPE b = op_src->val;
	DATA_TYPE ans = a - b;
	
	//uint64_t tmp = (uint64_t)a - b;
	//cpu.EFLAGS.CF = (tmp >> 8 * DATA_BYTE) & 1;
	cpu.EFLAGS.CF = a < b;
	cpu.EFLAGS.OF = MSB(a) != MSB(b) && MSB(a) != MSB(ans);
	cpu.EFLAGS.ZF = (ans == 0);
	cpu.EFLAGS.SF = MSB(ans);
	cpu.EFLAGS.PF = get_pf(ans);
    //printf("0x%x 0x%x a-b = 0x%x CF=%d, OF=%d, ZF=%d\n", a, b, ans, cpu.EFLAGS.CF, cpu.EFLAGS.OF, cpu.EFLAGS.ZF);

	print_asm_template2();
}

#if DATA_BYTE == 2 || DATA_BYTE == 4
make_instr_helper(si2rm)
#endif

make_instr_helper(r2rm)
make_instr_helper(rm2r)
make_instr_helper(i2rm)
make_instr_helper(i2a)

#include "cpu/exec/template-end.h"
