cmake_minimum_required(VERSION 3.17)
project(B_tree C)

set(CMAKE_C_STANDARD 11)

add_executable(B_tree arvore_b.c arvore_b.h cliente.c cliente.h lista_clientes.c lista_clientes.h lista_nos.c lista_nos.h metadados.c metadados.h no.c no.h test_arvore_b.c ufftest.h)