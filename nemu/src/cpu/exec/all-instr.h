#include "prefix/prefix.h"

#include "data-mov/mov.h"
#include "data-mov/xchg.h"
#include "data-mov/movsx.h"
#include "data-mov/movzx.h"
#include "data-mov/cmovcc.h"
#include "data-mov/convert.h"
#include "data-mov/lgdt.h"
#include "data-mov/movsp.h"
#include "data-mov/lidt.h"
#include "data-mov/iret.h"


#include "arith/dec.h"
#include "arith/inc.h"
#include "arith/neg.h"
#include "arith/imul.h"
#include "arith/mul.h"
#include "arith/idiv.h"
#include "arith/div.h"
#include "arith/sub.h"
#include "arith/cmp.h"
#include "arith/add.h"
#include "arith/adc.h"
#include "arith/sbb.h"

#include "logic/and.h"
#include "logic/or.h"
#include "logic/not.h"
#include "logic/xor.h"
#include "logic/sar.h"
#include "logic/shl.h"
#include "logic/shr.h"
#include "logic/shrd.h"

#include "string/rep.h"
#include "string/movs.h"
#include "string/stos.h"
#include "string/cmps.h"

#include "jmp/jcc.h"
#include "jmp/jmp.h"

#include "misc/misc.h"
#include "misc/flags.h"
#include "misc/int.h"

#include "special/special.h"

#include "call/call.h"

#include "stack/push.h"

#include "logic/test.h"

#include "setcc/setcc.h"

#include "stack/leave.h"
#include "stack/ret.h"
#include "stack/pop.h"
