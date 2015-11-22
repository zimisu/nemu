/*************************************************************************
    > File Name: jcc.c
    > Author: Chen Kan
    > Mail: 14307130198@fudan.edu.cn 
    > Created Time: 2015年11月22日 星期日 15时52分49秒
 ************************************************************************/

#include "cpu/exec/helper.h"
#include "cpu/reg.h"

make_helper(je_i_b)
{
	if (cpu.EFLAGS.ZF == 1)
	{
		printf("now we should jmp!\n");
		cpu.esp += op_dest->val;
		print_asm_template2();
	}
	return 2;
}
