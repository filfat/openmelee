project('openmelee', 'cpp',
  version : '1.0.0',
  license : 'MPL2',
  default_options : ['c_std=c17', 'cpp_std=gnu++17'])

source_files_finder = run_command('source_files.sh')
main_src = source_files_finder.stdout().strip().split('\n')
executable('openmelee', main_src)
