from distutils.core import setup, Extension

module1 = Extension('mymodule',
                    sources = ['mymodule.c'])

setup(name = 'PackageName',
      version = '1.0',
      description = 'This is a package for mymodule',
      ext_modules = [module1])
