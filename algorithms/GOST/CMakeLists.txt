add_executable(gost
               gostan.c
               gosthash.c
               gosthash.h)

add_executable(gosttest
               gosthash.c
               gosthash.h
               gosttest.c)
