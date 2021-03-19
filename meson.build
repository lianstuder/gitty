project(
  'gitty', 
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
libcppgit2 = cmake.subproject('cppgit2')
cppgit2 = libcppgit2.dependency('cppgit2')

libFTXUI_options = cmake.subproject_options()
libFTXUI_options.add_cmake_defines({
  'CMAKE_BUILD_TYPE': 'Release'
})
libFTXUI = cmake.subproject('FTXUI', options : libFTXUI_options)
ftxui_screen = libFTXUI.dependency('screen')
ftxui_dom = libFTXUI.dependency('dom')
ftxui_component = libFTXUI.dependency('component')

message('CMake targets:\n - ' + '\n - '.join(libcppgit2.target_list()))

# Executable
executable(
  meson.project_name(),
  'src/gitty.cpp',
  'src/components/stage.cpp',
  'src/components/commit.cpp',
  'src/core/repository.cpp',
  install : true,
  install_dir : '/usr/local/bin',
  dependencies : [cppgit2, ftxui_screen, ftxui_dom, ftxui_component],
  cpp_args : '-std=c++17'
)
