#ifndef th_include_vm_op
#define th_include_vm_op
#define th_include_vm_op_impl

enum th_vm_op
{
	th_vm_op_nil,
	th_vm_op_load,
	th_vm_op_load_relative,
	th_vm_op_store,
	th_vm_op_store_relative,
	th_vm_op_bit_or,
	th_vm_op_bit_or_exclusive,
	th_vm_op_bit_and,
	th_vm_op_bit_not
};

enum th_vm_op_width
{
	th_vm_op_size_nil,
	th_vm_op_size_1,
	th_vm_op_size_2,
	th_vm_op_size_4
};

typedef enum th_vm_op th_vm_op;
typedef enum th_vm_op_width th_vm_op_width;

#endif
