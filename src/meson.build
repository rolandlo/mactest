mactest_sources = [
  'main.cpp',
  'mactest-application.cpp',
  'mactest-window.cpp',
]

mactest_deps = [
  dependency('gtk+-3.0'),
]

mactest_sources += gnome.compile_resources('mactest-resources',
  'mactest.gresource.xml',
  c_name: 'mactest',
)

executable('mactest', mactest_sources,
  dependencies: mactest_deps,
       install: true,
)
