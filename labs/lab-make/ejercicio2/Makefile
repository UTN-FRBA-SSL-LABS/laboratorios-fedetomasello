# Nombre del ejecutable final
PROGRAMA := scanner2

# Compilador
CC := gcc

# Regla principal
all: $(PROGRAMA)

# Regla para construir el scanner
# Dependencias: scanner2.l (Flex genera lex.yy.c a partir de él)
$(PROGRAMA): scanner2.l
	# TODO 1: Ejecutá Flex sobre scanner2.l para generar lex.yy.c
	flex scanner2.l

	# TODO 2: Compilá lex.yy.c con gcc para generar el ejecutable
	$(CC) lex.yy.c -o $(PROGRAMA)
# Regla para limpiar archivos generados
clean:
	# TODO 3: Eliminá el ejecutable y el archivo generado por Flex
	rm -f $(PROGRAMA) lex.yy.c

.PHONY: all clean
