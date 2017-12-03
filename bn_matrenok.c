#include <math.h>
#include <stdlib.h>
#include "bn.h"


struct bn_s {
	int *body;
	int bodysize;
	int sign;
};

typedef struct bn_s bn;

bn *bn_new() { // Создать новое BN
    bn * r = malloc(sizeof bn);
    if (r == NULL){
        return NULL;
    }
    r->bodysize = 1;
    r->sign = 0;
    r->body = malloc(sizeof(int) * r->bodysize);
    if (r->body == NULL) {
        free (r);
        return NULL;
    }
    r->body[0] = 0;
    return r;
} 

bn *bn_init(bn const *orig) { // Создать копию существующего BN
    bn * r = malloc(sizeof bn);
    if (r == NULL){
        return NULL;
    }
    r->bodysize = orig->bodysize;
    r->sign = orig->sign;
    r->body = malloc(sizeof(orig->body));
    if (r->body == NULL) {
        free (r);
        return NULL;
    }
    for (i = 0; i<(r->bodysize); i++){
        r->body[i]=orig->body[i];
    }
    return r;
}

// Инициализировать значение BN десятичным представлением строки
int bn_init_string(bn *t, const char *init_string) {


}

// Инициализировать значение BN представлением строки 
// в системе счисления radix
int bn_init_string_radix(bn *t, const char *init_string, int radix) {

}

// Инициализировать значение BN заданным целым числом
int bn_init_int(bn *t, int init_int) {
    if (init_int < 0){
        t->sign = 1;
    }
    t->body[0] = init_int;
    return 0;
}

// Уничтожить BN (освободить память)
int bn_delete(bn *t) {
	free (t->body);
	free (t);
}

// Операции, аналогичные +=, -=, *=, /=, %=
int bn_add_to(bn *t, bn const *right) {
	int i;
	int size = t->bodysize;
	
	if (right->bodysize > size) {
		size = right->bodysize;
	}
	int mod = 0;
	for (i = 0; i < size; i++) {
		long int a = (long int) t->body[i];
		long int b = (long int) right->body[i];
		if ((a+b+k)/((int)pow (2, 8 * sizeof(int) - 1)) >= 1) {
			mod = 1;
		}
		t->body[i] = (a + b + k) % ((int)pow (2, 8 * sizeof(int) - 1));
	}
}

int bn_sub_to(bn *t, bn const *right) {

}

int bn_mul_to(bn *t, bn const *right) {

}

int bn_div_to(bn *t, bn const *right) {

}

int bn_mod_to(bn *t, bn const *right) {

}

// Возвести число в степень degree
int bn_pow_to(bn *t, int degree) {
    bn_add_to(t, degree);
}

// Извлечь корень степени reciprocal из BN (бонусная функция)
int bn_root_to(bn *t, int reciprocal) {

}

// Аналоги операций x = l+r (l-r, l*r, l/r, l%r)
bn* bn_add(bn const *left, bn const *right) {

}

bn* bn_sub(bn const *left, bn const *right) {

}

bn* bn_mul(bn const *left, bn const *right) {

}

bn* bn_div(bn const *left, bn const *right) {

}

bn* bn_mod(bn const *left, bn const *right) {

}

// Выдать представление BN в системе счисления radix в виде строки
//Строку после использования потребуется удалить.
const char *bn_to_string(bn const *t, int radix) {

}

// Если левое меньше, вернуть <0; если равны, вернуть 0; иначе >0
int bn_cmp(bn const *left, bn const *right) {

}

int bn_neg(bn *t) { // Изменить знак на противоположный

}

int bn_abs(bn *t) { // Взять модуль

}
int bn_sign(bn const *t) { //-1 если t<0; 0 если t = 0, 1 если t>0

}