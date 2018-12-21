import os 

env = Environment()
include = Dir('#/include')
testEnv = Environment(LIBS=['pthread'], CCFLAGS='-std=c++14 -Wl,rpath=./', CPPPATH=[include, '/opt/uvahep/include', '/opt/picoscope/include', '/usr/include/python2.7'], LIBPATH=['/opt/uvahep/lib'])
pyEnv = Environment(LIBS=['pthread', 'boost_python', 'python2.7', 'ps5000a','ps6000','ps5444b', 'ps6404', 'picoscopeInterface'], CCFLAGS='-std=c++14 -Wl,rpath=./', CPPPATH=[include, '/opt/uvahep/include', '/opt/picoscope/include', '/usr/include/python2.7'], LIBPATH=['/opt/uvahep/lib', '/opt/picoscope/lib'])
testEnv.ParseConfig("/usr/bin/root-config --cflags --libs")
pyEnv['SHLIBPREFIX']=''
pyEnv.Append(RPATH = [str(Dir('/opt/uvahep/lib'))])

psPython = pyEnv.SharedLibrary('pscope.so', ['psPython.cc'])
