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

extern th_attr_export th_u1 th_vm_stack_in_1(th_vm_stack *self);
extern th_attr_export th_u2 th_vm_stack_in_2(th_vm_stack *self);
extern th_attr_export th_u4 th_vm_stack_in_4(th_vm_stack *self);

extern th_attr_export th_u1 th_vm_stack_out_1(th_vm_stack *self, th_u1 data);
extern th_attr_export th_u2 th_vm_stack_out_2(th_vm_stack *self, th_u2 data);
extern th_attr_export th_u4 th_vm_stack_out_4(th_vm_stack *self, th_u4 data);

#endif
