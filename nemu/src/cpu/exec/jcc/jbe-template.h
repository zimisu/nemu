/*************************************************************************
    > File Name: jbe-template.h
    > Author: Chen Kan
    > Mail: 14307130198@fudan.edu.cn 
    > Created Time: 2015年12月04日 星期五 15时37分26秒
 ************************************************************************/
#include "cpu/exec/template-start.h"

#define instr jbe

static void do_execute() {
    int l = DATA_BYTE << 3;
    int mask = 0xffffffff;
    if (DATA_BYTE == 1) mask = 0xff;
    else if (DATA_BYTE == 2) mask = 0xffff;
    printf("op_src->val : %x\n", op_src->val);
	if (cpu.EFLAGS.ZF == 1 || cpu.EFLAGS.CF == 1)
	{
        //cpu.eip += op_src->val;
		cpu.eip = ((cpu.eip>>l)<<l)+((cpu.eip + op_src->val) & mask);
        if (DATA_BYTE == 2)
            cpu.eip &= 0xffff;
	}
	print_asm_template1();
}




make_instr_helper(i)


#include "cpu/exec/template-end.h"
