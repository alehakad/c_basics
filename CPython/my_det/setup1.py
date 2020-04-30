from distutils.core import setup, Extension

module1 = Extension(
	'my_det', # название модуля внутри Python
	 sources = ['my_det_gauss.c'] # Исходные файлы модуля
)

setup(
	name = 'my_det',              # название модуля (my_plus.__name__)
	version = '1.1',               # версия модуля
	description = 'Simple module', # описание модуля
	ext_modules= [module1]         # объекты типа Extension (мы объявили его выше)
)
