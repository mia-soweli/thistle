#ifndef th_include_vm
#define th_include_vm
#define th_include_vm_impl

struct th_vm_stack
{
	th_u1 *data;
	th_u1 *data_limit;
	th_u1 *data_limit_p;
};

struct th_vm
{
	struct th_vm_stack stack;
	struct th_vm_stack stack_return;
};

typedef struct th_vm th_vm;
typedef struct th_vm_stack th_vm_stack;

#endif
