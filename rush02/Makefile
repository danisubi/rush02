# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsubiran <dsubiran@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/16 18:57:41 by dsubiran          #+#    #+#              #
#    Updated: 2022/04/17 22:39:34 by dsubiran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#creo una variable con los files para no tenerlos que escribir en cda linea, solo modificarlos aqui
OBJS = main.o files.o array.o search.o


#creo una variable para los flags al compilar
CFLAGS = -Wall -Werror -Wextra

CC = gcc

#indicaciones para Makefile
#objetivo: 	dependencias
#			instrucciones


#si al llamar make no ponemos nada mas compilara todo el programa

all: programa

#esta regla compila el programa principal

programa: $(OBJS)
		gcc -o rush-02 $(OBJS)

#asi con cada uno de los archivos para poder compilar solo uno de los files

main.o: main.c
		gcc $(CFLAGS) -c main.c
		
clean:
		rm -f programa $(OBJS)

fclean:
		rm -f programa $(OBJS) a.out
