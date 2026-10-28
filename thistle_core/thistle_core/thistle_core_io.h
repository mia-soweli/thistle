#ifndef th_include_core_io
#define th_include_core_io
#define th_include_core_io_impl

enum th_io_state
{
	th_io_state_none,
	th_io_state_i,
	th_io_state_i_end,
	th_io_state_o,
};

enum th_io_state_flag
{
	th_io_state_flag_none,
};

typedef enum th_io_state th_io_state;
typedef enum th_io_state_flag th_io_state_flag;

struct th_io
{
	th_io_state state;
	th_io_state_flag state_flag;

	th_u1 *data;
	th_u1 *data_limit;
	th_u1 *data_limit_i;
	th_u1 *data_limit_o;
};

typedef struct th_io th_io;

extern th_attr_export th_usize th_io_in(th_io *self, th_u1 *data, th_usize data_size);
extern th_attr_export th_usize th_io_in_1(th_io *self, th_u1 *data);
extern th_attr_export th_usize th_io_in_2(th_io *self, th_u2 *data);
extern th_attr_export th_usize th_io_in_4(th_io *self, th_u4 *data);

extern th_attr_export th_usize th_io_in_1_peek(th_io *self, th_u1 *data);
extern th_attr_export th_usize th_io_in_2_peek(th_io *self, th_u2 *data);
extern th_attr_export th_usize th_io_in_4_peek(th_io *self, th_u4 *data);

extern th_attr_export th_usize th_io_out(th_io *self, th_u1 *data, th_usize data_size);
extern th_attr_export th_usize th_io_out_1(th_io *self, th_u1 data);
extern th_attr_export th_usize th_io_out_2(th_io *self, th_u2 data);
extern th_attr_export th_usize th_io_out_4(th_io *self, th_u4 data);

#endif
