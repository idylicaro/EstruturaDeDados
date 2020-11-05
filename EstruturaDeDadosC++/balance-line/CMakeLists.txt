cmake_minimum_required(VERSION 3.17)
project(balance_line C)

set(CMAKE_C_STANDARD 11)

add_executable(balance_line main.c balanceLine.h cliente.h criaMestre.h criaTransacoes.h leMestre.h leTransacoes.h transacao.h)