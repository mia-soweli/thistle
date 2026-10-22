#include <thistle_core/thistle_core.h>

th_visibility
th_usize
th_io_in_1(struct th_io *self, th_u1 *data)
{
	*data = 0;

	if (self->data_limit_o + 1 <= self->data_limit_i)
	{
		*data = *self->data_limit_o;
		return 1;
	}

	return 0;
}

th_visibility
th_usize
th_io_in_1_take(struct th_io *self, th_u1 *data)
{
	*data = 0;

	if (self->data_limit_o + 1 <= self->data_limit_i)
	{
		*data |= *self->data_limit_o;
		return 1;
	}

	return 0;
}
