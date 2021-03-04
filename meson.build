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

# Import CMake Subproject Module
cmake = import('cmake')

# Dependencies
libgit2 = dependency('libgit2')

libFTXUI_options = cmake.subproject_options()
libFTXUI_options.add_cmake_defines({
  'CMAKE_BUILD_TYPE': 'Release'
})
libFTXUI = cmake.subproject('FTXUI', options : libFTXUI_options)
message('CMaket targets:\n - ' + '\n - '.join(libFTXUI.target_list()))
ftxui_screen = libFTXUI.dependency('screen')
ftxui_dom = libFTXUI.dependency('dom')
ftxui_component = libFTXUI.dependency('component')

# Executable
executable(
  'neutron', 
  'src/neutron.cpp',
  'src/screen.cpp',
  'src/document.cpp',
  install : true,
  install_dir : '/usr/local/bin',
  dependencies : [libgit2, ftxui_screen, ftxui_dom, ftxui_component],
  cpp_args : '-std=c++17'
)
