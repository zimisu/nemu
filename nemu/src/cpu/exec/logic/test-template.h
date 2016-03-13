/*************************************************************************
    > File Name: test-template.h
    > Author: Chen Kan
    > Mail: 14307130198@fudan.edu.cn 
    > Created Time: 2015年11月20日 星期五 20时54分52秒
 ************************************************************************/
#include "cpu/exec/template-start.h"

#define instr test

static void do_execute()
{
	DATA_TYPE_S result = op_src->val & op_src->val;
	if (DATA_BYTE == 2) result &= 0xffff;
	cpu.EFLAGS.ZF = (result == 0);
	cpu.EFLAGS.CF = cpu.EFLAGS.OF = 0;
	cpu.EFLAGS.SF = MSB(result);
	cpu.EFLAGS.PF = get_pf(result);
	print_asm_template2();
}

make_instr_helper(i2a)
make_instr_helper(i2rm)
make_instr_helper(r2rm)


#include "cpu/exec/template-end.h"