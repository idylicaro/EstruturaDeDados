cmake_minimum_required(VERSION 3.17)
project(partition_interleaving C)

set(CMAKE_C_STANDARD 11)

add_executable(partition_interleaving main.c cliente.c cliente.h intercalacao.c intercalacao.h lista_clientes.c lista_clientes.h nomes.c nomes.h)