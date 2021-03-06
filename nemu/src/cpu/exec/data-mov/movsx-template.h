#include "cpu/exec/template-start.h"

#define instr movsb
static void do_execute() {
	uint32_t sign = op_src->val & 0x80;
    uint32_t mask = 0;
	if (sign) mask = 0xffffff00;
	
    OPERAND_W(op_dest, (op_src->val & 0xff) | mask);
    //OPERAND_W(op_dest, op_src->val | mask);
    print_asm_template2();
}

make_instr_helper(rm2r)
#undef instr

/*-----------------------------------------------*/
#define instr movsw
static void do_execute() {
	uint32_t sign = op_src->val & 0x8000;
    uint32_t mask = 0;
	if (sign) mask = 0xffff0000;
    OPERAND_W(op_dest, (op_src->val & 0xffff) | mask);
    //OPERAND_W(op_dest, op_src->val | mask);
    print_asm_template2();
}

make_instr_helper(rm2r)
#undef instr

#include "cpu/exec/template-end.h"
