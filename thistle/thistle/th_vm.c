#include <thistle/th.h>

th_attr_export
th_u1
th_vm_stack_in_1(th_vm_stack *self)
{
	th_u1 data = 0;

	if (self->data_limit_p - 1 >= self->data)
	{
		data |= self->data_limit_p[-1]; self->data_limit_p -= 1;
	}

	return data;
}

th_attr_export
th_u2
th_vm_stack_in_2(th_vm_stack *self)
{
	th_u2 data = 0;

	if (self->data_limit_p - 2 >= self->data)
	{
		data |= self->data_limit_p[-2];
		data |= self->data_limit_p[-1] << 8; self->data_limit_p -= 2;
	}

	return data;
}

th_attr_export
th_u4
th_vm_stack_in_4(th_vm_stack *self)
{
	th_u4 data = 0;

	if (self->data_limit_p - 4 >= self->data)
	{
		data |= self->data_limit_p[-4];
		data |= self->data_limit_p[-3] << 8;
		data |= self->data_limit_p[-2] << 16;
		data |= self->data_limit_p[-1] << 24; self->data_limit_p -= 4;
	}

	return data;
}

th_attr_export
th_u1
th_vm_stack_out_1(th_vm_stack *self, th_u1 data)
{
	if (self->data_limit_p + 1 <= self->data_limit)
	{
		self->data_limit_p[0] = data; self->data_limit_p += 1;
	}

	return data;
}

th_attr_export
th_u2
th_vm_stack_out_2(th_vm_stack *self, th_u2 data)
{
	if (self->data_limit_p + 2 <= self->data_limit)
	{
		self->data_limit_p[0] = data;
		self->data_limit_p[1] = data >> 8; self->data_limit_p += 2;
	}

	return data;
}

th_attr_export
th_u4
th_vm_stack_out_4(th_vm_stack *self, th_u4 data)
{
	if (self->data_limit_p + 4 <= self->data_limit)
	{
		self->data_limit_p[0] = data;
		self->data_limit_p[1] = data >> 8;
		self->data_limit_p[2] = data >> 16;
		self->data_limit_p[3] = data >> 24; self->data_limit_p += 4;
	}

	return data;
}
