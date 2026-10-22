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
};

#endif
