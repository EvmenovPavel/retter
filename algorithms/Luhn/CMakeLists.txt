add_executable(luhn
               luhn.c)
target_link_libraries(luhn PUBLIC
                      -lm)