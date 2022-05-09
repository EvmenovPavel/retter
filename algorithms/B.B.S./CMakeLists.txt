add_executable(bbs
               bbs.c)
target_link_libraries(bbs PUBLIC
                      -lrt -lcrypto -lz -lpthread -ldl)
