#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */
void test_compra_con_descuento(void) {
    printf("\n[compra con descuento]\n");
    Carrito c;
    carrito_init(&c);

    Producto pan   = {"Pan", 200, 3};    /* 200 x 3 = 600 */
    Producto leche = {"Leche", 350, 2};  /* 350 x 2 = 700 */

    carrito_agregar(&c, pan);
    carrito_agregar(&c, leche);

    int total = carrito_total(&c);
    ASSERT_IGUAL(1300, total);
    ASSERT_IGUAL(1170, carrito_descuento(total, 10));
}
/* TODO: escribir test_compra_con_descuento() siguiendo la guia del .md */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */
void test_agregar_hasta_llenar(void) {
    printf("\n[agregar hasta llenar]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Leche", 350, 1};

    for (int i = 0; i < MAX_ITEMS; i++) {
        carrito_agregar(&c, p);
    }
    ASSERT_IGUAL(MAX_ITEMS, carrito_contar(&c));

    ASSERT_IGUAL(0, carrito_agregar(&c, p));
    ASSERT_IGUAL(MAX_ITEMS, carrito_contar(&c));
}
/* TODO: escribir test_agregar_hasta_llenar() */

int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento();  
    test_agregar_hasta_llenar();  
    RESUMEN();
    return EXIT_CODE();
}
