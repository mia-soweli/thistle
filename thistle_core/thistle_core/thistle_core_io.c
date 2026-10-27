#include <thistle_core/thistle_core.h>

th_attr_export
th_usize
th_io_in_1(th_io *self, th_u1 *data)
{
	*data = 0;

	if (self->data_limit_o + 1 <= self->data_limit_i)
	{
		*data |= *self->data_limit_o;
		return 1;
	}

	return 0;
}

th_attr_export
th_usize
th_io_in_1_take(th_io *self, th_u1 *data)
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

th_attr_export
th_usize
th_io_in_2(th_io *self, th_u2 *data)
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

th_attr_export
th_usize
th_io_in_2_take(th_io *self, th_u2 *data)
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

th_attr_export
th_usize
th_io_in_4(th_io *self, th_u4 *data)
{
	*data = 0;

	if (self->data_limit_o + 4 <= self->data_limit_i)
	{
		*data |= self->data_limit_o[0];
		*data |= self->data_limit_o[1] << 8;
		*data |= self->data_limit_o[2] << 16;
		*data |= self->data_limit_o[3] << 24;
		return 4;
	}

	return 0;
}

th_attr_export
th_usize
th_io_in_4_take(th_io *self, th_u4 *data)
{
	*data = 0;

	if (self->data_limit_o + 4 <= self->data_limit_i)
	{
		*data |= self->data_limit_o[0];
		*data |= self->data_limit_o[1] << 8;
		*data |= self->data_limit_o[2] << 16;
		*data |= self->data_limit_o[3] << 24; self->data_limit_o += 4;

		if (self->data_limit_o == self->data_limit_i)
		{
			self->state = th_io_state_i_end;
		}

		return 4;
	}

	return 0;
}

th_attr_export
th_usize
th_io_out_1(th_io *self, th_u1 data)
{
	if (self->data_limit_i + 1 <= self->data_limit_o)
	{
		*self->data_limit_i++ = data;
		return 1;
	}

	return 0;
}

th_attr_export
th_usize
th_io_out_2(th_io *self, th_u2 data)
{
	if (self->data_limit_i + 2 <= self->data_limit_o)
	{
		self->data_limit_i[0] = data;
		self->data_limit_i[1] = data >> 8; self->data_limit_i += 2;
		return 2;
	}

	return 0;
}

th_attr_export
th_usize
th_io_out_4(th_io *self, th_u4 data)
{
	if (self->data_limit_i + 4 <= self->data_limit_o)
	{
		self->data_limit_i[0] = data;
		self->data_limit_i[1] = data >> 8;
		self->data_limit_i[2] = data >> 16;
		self->data_limit_i[3] = data >> 24; self->data_limit_i += 4;
		return 4;
	}

	return 0;
}
