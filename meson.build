project('openmelee', 'cpp',
  version : '1.0.0',
  license : 'MPL2',
  default_options : ['c_std=c17', 'cpp_std=c++17'])

cpp_args = [
  '-D__DEBUG__'
]
link_args = []
dep = []

if build_machine.system() == 'darwin'
  cpp_args += ['-D__DARWIN__']
elif build_machine.system() == 'linux'
  cpp_args += ['-D__LINUX__']
elif build_machine.system() == 'windows'
  cpp_args += ['-D__WIN32__']
endif

if build_machine.system() == 'linux' or build_machine.system() == 'darwin'
  # TODO: Metal for darwin?
  dep_glew = dependency('glew')
  dep_glfw3 = dependency('glfw3')
  dep_usb = dependency('libusb')

  cpp_args += ['-D__USE_OPENGL__']
  link_args += ['-lusb-1.0'] # temporary
  dep += [dep_glew, dep_glfw3, dep_usb]
elif
  # TODO: subproject for OpenGL? D3D? Vulkan?
endif

source_files_finder = run_command('source_files.sh')
main_src = source_files_finder.stdout().strip().split('\n')
executable('openmelee', main_src, dependencies: dep, cpp_args: cpp_args, link_args: link_args)