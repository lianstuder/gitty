project(
  'neutron', 
  'cpp',
  version : '1.0.0',
  license : 'GPLv3',
  default_options : [
    'buildtype=release',
    'optimization=3'
  ]
)

# Dependencies
libgit2 = dependency('libgit2')

# Executable
executable(
  'neutron', 
  'src/neutron.cpp',
  install : true,
  install_dir : '/usr/local/bin',
  dependencies : [libgit2]
)
