</$objtype/mkfile

CFLAGS=$CFLAGS -Ithistle_core -Ithistle_core_p9 -Ithistle

thl_core=libthistle_core.a
thl_core_o=\
	thistle_core/thistle_core/thistle_core.$O\
	thistle_core/thistle_core/thistle_core_io.$O\

thl_core_h=\
	thistle_core/thistle_core/thistle_core.h\
	thistle_core/thistle_core/thistle_core_io.h\
	thistle_core_p9/thistle_core/thistle_core_type.h\
	thistle_core_p9/thistle_core/thistle_core_type_attributes.h\

thl=libthistle.a
thl_o=\
	thistle/thistle/thistle.$O\
	thistle/thistle/thistle_machine.$O\
	thistle/thistle/thistle_machine_op.$O\

thl_h=\
	thistle/thistle/thistle.h\
	thistle/thistle/thistle_machine.h\
	thistle/thistle/thistle_machine_op.h\

all:V: $thl $thl_core

clean:V:
	rm -f */*/*.[$OS] */*.[$OS]

$thl(%.$O):N:	%.$O
$thl:	${thl_o:%=$thl(%)}
	ar vu $target $newmember

$thl_core(%.$O):N:	%.$O
$thl_core:	${thl_core_o:%=$thl_core(%)}
	ar vu $target $newmember

%.$O:	$thl_core_h $thl_h

%.$O:	%.c
	$CC $CFLAGS -o $target $stem.c
