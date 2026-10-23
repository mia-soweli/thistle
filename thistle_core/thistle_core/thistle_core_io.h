#ifndef th_include_core_io
#define th_include_core_io
#define th_include_core_io_impl

enum th_io_state
{
	th_io_state,
	th_io_state_i,
	th_io_state_i_end,
};

enum th_io_state_flag
{
	th_io_state_flag,
};

struct th_io
{
	enum th_io_state state;
	enum th_io_state_flag state_flag;

	th_u1 *data;
	th_u1 *data_limit;
	th_u1 *data_limit_i;
	th_u1 *data_limit_o;
};

extern th_attr_export th_usize th_io_in_1(struct th_io *self, th_u1 *data);
extern th_attr_export th_usize th_io_in_1_take(struct th_io *self, th_u1 *data);
extern th_attr_export th_usize th_io_in_2(struct th_io *self, th_u2 *data);
extern th_attr_export th_usize th_io_in_2_take(struct th_io *self, th_u2 *data);
extern th_attr_export th_usize th_io_in_4(struct th_io *self, th_u4 *data);
extern th_attr_export th_usize th_io_in_4_take(struct th_io *self, th_u4 *data);

#endif
