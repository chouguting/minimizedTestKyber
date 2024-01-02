cmake_minimum_required(VERSION 3.26)
project(minimizedTestKyber C)

set(CMAKE_C_STANDARD 11)

add_executable(test_kyber test_kyber.c kex.c kem.c indcpa.c polyvec.c poly.c ntt.c cbd.c reduce.c verify.c fips202.c symmetric-shake.c randombytes.c
        my_memory_op.c
        my_memory_op.h
        my_io.c
        my_io.h)

add_executable(kyber_speed  test_speed.c cpucycles.c speed_print.c kex.c kem.c indcpa.c polyvec.c poly.c ntt.c cbd.c reduce.c verify.c fips202.c symmetric-shake.c randombytes.c
        my_memory_op.c
        my_memory_op.h
        my_io.c
        my_io.h
        test_speed.c)


