#ifndef th_include_vm_op
#define th_include_vm_op
#define th_include_vm_op_impl

enum th_vm_op_type
{
	th_vm_op_nil,
	th_vm_op_load,
	th_vm_op_load_relative,
	th_vm_op_store,
	th_vm_op_store_relative
};

enum th_vm_op_type_size
{
	th_vm_op_size_nil,
	th_vm_op_size_1,
	th_vm_op_size_2,
	th_vm_op_size_4
};

typedef enum th_vm_op_type th_vm_op_type;
typedef enum th_vm_op_type_size th_vm_op_type_size;

#endif
