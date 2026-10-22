#include <thistle_core/thistle_core.h>

th_visibility
th_usize
th_io_in_1(struct th_io *self, th_u1 *data)
{
	*data = 0;

	if (self->data_limit_o + 1 <= self->data_limit_i)
	{
		*data |= *self->data_limit_o;
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
		*data |= *self->data_limit_o++;

		if (self->data_limit_o == self->data_limit_i)
		{
			self->state = th_io_state_i_end;
		}

		return 1;
	}

	return 0;
}

th_visibility
th_usize
th_io_in_2(struct th_io *self, th_u2 *data)
{
	*data = 0;

	if (self->data_limit_o + 2 <= self->data_limit_i)
	{
		*data |= self->data_limit_o[0];
		*data |= self->data_limit_o[1] << 8;
		return 2;
	}

	return 0;
}

th_visibility
th_usize
th_io_in_2_take(struct th_io *self, th_u2 *data)
{
	*data = 0;

	if (self->data_limit_o + 2 <= self->data_limit_i)
	{
		*data |= self->data_limit_o[0];
		*data |= self->data_limit_o[1] << 8; self->data_limit_o += 2;

		if (self->data_limit_o == self->data_limit_i)
		{
			self->state = th_io_state_i_end;
		}

		return 2;
	}

	return 0;
}

th_visibility
th_usize
th_io_in_4(struct th_io *self, th_u2 *data)
{
	*data = 0;

	if (self->data_limit_o + 4 <= self->data_limit_i)
	{
		*data |= self->data_limit_o[0];
		*data |= self->data_limit_o[1] << 8;
		*data |= self->data_limit_o[2] << 12;
		*data |= self->data_limit_o[3] << 16;
		return 4;
	}

	return 0;
}

th_visibility
th_usize
th_io_in_4_take(struct th_io *self, th_u2 *data)
{
	*data = 0;

	if (self->data_limit_o + 4 <= self->data_limit_i)
	{
		*data |= self->data_limit_o[0];
		*data |= self->data_limit_o[1] << 8;
		*data |= self->data_limit_o[2] << 12;
		*data |= self->data_limit_o[3] << 16; self->data_limit_o += 4;

		if (self->data_limit_o == self->data_limit_i)
		{
			self->state = th_io_state_i_end;
		}

		return 4;
	}

	return 0;
}
