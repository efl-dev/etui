pdf_src = [ 'etui_module_pdf.c' ]

mod_install_dir = join_paths(etui_package_module, 'pdf', module_arch)

have_pdf = 'no'
if get_option('mupdf') == true and enable_mupdf == true

  mupdf_deps = [
    dependency('freetype2'),
    dependency('harfbuzz'),
    dependency('libjpeg'),
    dependency('libopenjp2'),
    dependency('zlib'),
    cc.find_library('jbig2dec')
  ]

# test if static library is available
  mupdf_a = cc.find_library(get_option('mupdf-static-lib'),
    required : true,
    dirs : get_option('mupdf-libdir')
  )
  if mupdf_a.found() == true
    path = get_option('mupdf-libdir')
    r = run_command('mupdf_ver.py', path + '/../include/mupdf/fitz/')
    minor = r.stdout().strip()
    mupdf_args = [ etui_args, '-DECRIN_ETUI_BUILD' ]
    if minor == '12'
      mupdf_args += [ '-DFZ_VERSION_MINOR=12' ]
    endif
    if minor == '11'
      mupdf_args += [ '-DFZ_VERSION_MINOR=11' ]
    endif

    mupdf_libs = [ mupdf_a ]

    mupdf_third_a = cc.find_library(get_option('mupdf-static-third'),
      required : false,
      dirs : get_option('mupdf-libdir')
    )

    if mupdf_third_a.found() == true
      mupdf_libs += [ mupdf_third_a ]
    endif

    have_pdf = 'yes'
    config_h.set('ETUI_BUILD_PDF', 1)
    shared_module('module', pdf_src,
      c_args : mupdf_args,
      include_directories : [ config_dir, get_option('mupdf-includedir') ],
      dependencies : [ etui, mupdf_deps, mupdf_libs],
      install : true,
      install_dir : mod_install_dir,
      name_suffix : sys_lib_ext
    )
  endif

  if have_pdf == 'no'
    message('mupdf needed for PDF module')
  endif
endif
