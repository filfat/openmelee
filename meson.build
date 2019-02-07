project('openmelee', 'cpp',
  version : '1.0.0',
  license : 'MPL2',
  default_options : ['c_std=c17', 'cpp_std=c++17'])

dep_glew = dependency('glew')
dep_glfw3 = dependency('glfw3')

source_files_finder = run_command('source_files.sh')
main_src = source_files_finder.stdout().strip().split('\n')
executable('openmelee', main_src, dependencies: [dep_glew, dep_glfw3], cpp_args: ['-D__LINUX__'])