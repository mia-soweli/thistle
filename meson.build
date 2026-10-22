project('thistle', 'c', version: '0', meson_version: '>=1.1.0', default_options: ['warning_level=3'])

th_compiler_c = meson.get_compiler('c')
th_compiler_c_args_link = []
th_compiler_c_args = []

th_compiler_c_args_link += th_compiler_c.get_supported_link_arguments()
th_compiler_c_args += th_compiler_c.get_supported_arguments(
	'-fvisibility=hidden',
	'-fvisibility-inlines-hidden',
	'-Werror=format-security',
	'-Werror=format=2',
	'-Werror=implicit',
	'-Werror=implicit-fallthrough',
	'-Werror=incompatible-pointer-types',
	'-Werror=strict-aliasing',
	'-Wpedantic',
)

add_project_arguments(th_compiler_c_args, language: 'c')
add_project_link_arguments(th_compiler_c_args_link, language: 'c')

thl_core_source_include = []
thl_core_source = []

thl_core_source_include += [ 'thistle_core' ]
thl_core_source += [
	'thistle_core/thistle_core/thistle_core.c',
	'thistle_core/thistle_core/thistle_core.h',
]

thl_core_source_include += [ 'thistle_core_p' ]
thl_core_source += [
	'thistle_core_p/thistle_core/thistle_core_type.h',
	'thistle_core_p/thistle_core/thistle_core_type_attributes.h',
]

thl_source_include = []
thl_source = []

thl_source_include += [ 'thistle' ]
thl_source += [
	'thistle/thistle/thistle.c',
	'thistle/thistle/thistle.h',
]

thl_core = library('thistle_core', sources: thl_core_source, include_directories: thl_core_source_include)
thl_core_dependency = declare_dependency(link_with: thl_core, include_directories: thl_core_source_include)
thl = library('thistle', sources: thl_source, include_directories: thl_source_include, dependencies: thl_core_dependency)

summary({})
