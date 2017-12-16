#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define max(x, y) (((x) < (y)) ? (x) : (y))
#define N 10000

struct bn_s {
    int *body;
    int bodysize;
    int sign;
};

typedef struct bn_s bn;



//Длинное число представляет из себя массив из шестизначных чисел
//То есть максимум каждой "цифры" 9999.

bn *bn_new() { // Создать новое BN
    bn* r = malloc(sizeof (bn));
    if (r == NULL) {
        return NULL;
    }
    r->bodysize = 1;
    r->sign = 0;
    r->body = malloc(sizeof (int) * r->bodysize);
    if (r->body == NULL) {
        free (r);
        return NULL;
    }
    r->body[0] = 0;
    return r;
} 

bn *bn_init(bn const *orig) { // Создать копию существующего BN
    bn * r = bn_new();
    r->sign = orig->sign;
    r->bodysize = orig->bodysize;
    r->body = realloc(r->body, sizeof(int) * r->bodysize);
    int i;
    for (i = 0; i < r->bodysize; i++) {
        r->body[i] = orig->body[i];
    }
    return r;
}

// Инициализировать значение BN десятичным представлением строки
int bn_init_string(bn *t, const char *init_string) {
    int sign_num;
    if (init_string[0] == '-') {
        sign_num = 1;
        t->sign = 1;
    }
    else if ((init_string[0] < 58 && init_string[0] > 48) || (init_string[0] < 'Z' && init_string[0] > 'A'))) {
        sign_num = 0;
        t->sign = 0;
    }
    else if (init_string[0] == '0' && strlen(init_string) == 1) {
        sign_num = 0;
        t->sign = 0;
    } else{
        printf("incorrect input");
        return 1;
    }

    int number_digits = strlen(init_string) - sign_num;
    t->bodysize = number_digits % N == 0 ? number_digits / N : number_digits / N + 1;
    t->body = realloc(t->body, sizeof(int) * t->bodysize);
    int i;
    for (i = strlen(init_string) - 1; i >= sign_num; i--) {
        t->body[(strlen(init_string) - i - 1)/N] += (init_string[i] - '0') * pow(10, (strlen(init_string) - i - 1) % N);
    }
    return 0;
}

// Инициализировать значение BN представлением строки 
// в системе счисления radix
int bn_init_string_radix(bn *t, const char *init_string, int radix) {
    int sign_num;
    if (init_string[0] == '-') {
        sign_num = 1;
        t->sign = 1;
    }
    else if ((init_string[0] < 58) && (init_string[0] > 48) || (init_string[0] < 'Z' && init_string[0] > 'A'))) {
        sign_num = 0;
        t->sign = 0;
    }
    else if ((init_string[0] == '0') && (strlen(init_string) == 1)) {
        sign_num = 0;
        t->sign = 0;
    } else {
        printf("incorrect input");
        return 1;
    }

    int number_digits = strlen(init_string) - sign_num;
    t->bodysize = number_digits % N == 0 ? number_digits / N : number_digits / N + 1;
    t->body = realloc(t->body, sizeof(int) * t->bodysize);
    int i;
    for (i = strlen(init_string) - 1; i >= sign_num; i--) {
        if (init_string[i] < 58 && init_string[i] > 48) {
            t->body[(strlen(init_string) - i - 1)/N] += (init_string[i]  - '0')* pow(radix, (strlen(init_string) - i - 1) % N);
        } else if (init_string[i] < 'Z' && init_string[i] > 'A'){
            t->body[(strlen(init_string) - i - 1)/N] += (init_string[i] - 'A' + 10) * pow(radix, (strlen(init_string) - i - 1) % N);
        }
    }
    return 0;
}

// Инициализировать значение BN заданным целым числом
int bn_init_int(bn *t, int init_int) {
    if (init_int < 0){
        t->sign = 1;
    } else {
        t->sign = 0;
    }

    int x = abs(init_int);
    while (x > 0) {
        t->body[t->bodysize - 1] = x % N;
        t->bodysize++;
        t->body = realloc(t->body, sizeof(int) * t->bodysize);
        x /= N;
    }

    return 0;
}

// Уничтожить BN (освободить память)
int bn_delete(bn *t) {
    if (t != NULL) {
        if (t->body != NULL) {
            free (t->body);
        }
    free (t);
    }
}

// Операции, аналогичные +=, -=, *=, /=, %=
int bn_add_to(bn *t, bn const *right) {
    t = bn_add(t, right);
    return 0;
}

int bn_sub_to(bn *t, bn const *right) {

}

int bn_mul_to(bn *t, bn const *right) {
    t = bn_mul(t, right);
    return 0;
}

int bn_div_to(bn *t, bn const *right) {
    t = bn_div(t, right);
    return 0;
}

int bn_mod_to(bn *t, bn const *right) {

}

// Возвести число в степень degree
int bn_pow_to(bn *t, int degree) {
    bn* nbn = bn_init(t);
    int i;
    for (i = 0; i < degree - 1; i++) {
        bn_mul_to(t, nbn);
    }
    bn_delete(nbn);
}

// Извлечь корень степени reciprocal из BN (бонусная функция)
int bn_root_to(bn *t, int reciprocal) {
    
}

bn* bn_abs_add(bn const *left, bn const *right) {
    bn* res = bn_new();
    
    res->sign = 0;
    res->bodysize = max (left->bodysize, right->bodysize);
    
    res->body = realloc(res->body, sizeof(int) * (res->bodysize));
    int i;
    int r = 0;
    for (i = 0; i < res->bodysize; i++) {
        res->body[i] = left->body[i] + right->body[i] + r;
        if (res->body[i] >= N) {
            res->body[i] -= N;
            r = 1;
        } else {
            r = 0;
        }
    }

    return res;
}
bn* bn_one_min_add(bn const *left, bn const *right);

bn* bn_two_min_add(bn const *left, bn const *right);

// Аналоги операций x = l+r (l-r, l*r, l/r, l%r)
bn* bn_add(bn const *left, bn const *right) {
    if ((left->sign == 0) && (right->sign == 0)) {
        return bn_abs_add (left, right);
    }
    else if ((left->sign == 1) && (right->sign == 0)){
        return bn_one_min_add(left, right);
    }
    else if ((left->sign == 0) && right->sign ==1){
        return bn_one_min_add(right, left);
    }
    else{
        return bn_two_min_add(left, right);
    }
}

bn* bn_abs_sub(bn const *left, bn const *right);

bn* bn_cmp(bn const *left, bn const *right);

//сложение когда l<0 r>0
bn* bn_one_min_add(bn const *left, bn const *right) {
    bn* left1 = bn_init(left);
    //left1=left;
    //left1->sign = 0;
    //left1->bodysize = left->bodysize;
    //left1->body = realloc(left1->body, sizeof(int) * (left1->bodysize));
    left1->sign = 0;
    bn *res = bn_new();
    if (bn_cmp(left1, right) >= 0) {
        res = bn_init(bn_abs_sub(left1, right)); // TODO if I write 'return (bn_sub(left1,right))' will left1 be free?
        res->sign = 1;
    }
    else{
        res = bn_init(bn_abs_sub(right, left1));
    }
    free(left1);
    return (res);
}

bn* bn_two_min_add(bn const *left, bn const *right) {
    bn* left1 = bn_init(left);
    bn* right1 = bn_init(right);
    left1->sign = 0;
    right1->sign = 0;
    bn *res = bn_new();
    if (bn_cmp(left1, right1) >= 0) {
        res = bn_init(bn_abs_sub(left1, right1)); // TODO if I write 'return (bn_sub(left1,right))' will left1 be free?
    }
    else{
        res = bn_init(bn_abs_sub(right1, left1));
    }
    free(left1);
    free(right1);
    res->sign = 1;
    return (res);
}

// вычитание по модулю, left>right
bn* bn_abs_sub(bn const *left, bn const *right) {
    bn* res = bn_new();
    int i = 0;
    res->bodysize = max (left->bodysize, right->bodysize);
    res->body = realloc(res->body, sizeof(int) * (res->bodysize));

    for (i; i<left->bodysize; i++) {
        res->body[i] = left->body[i] - right->body[i];
        if (res->body[i] <0) {
            res->body[i+1]--;
            res->body = res->body + N;
        }
    }
    int a = res->bodysize - 1;
    while ((res->body[a] == 0) && (a != 0)) {
        res->bodysize--;
    }
    return res;
}

bn* bn_sub(bn const *left, bn const *right) {
    if ((left->sign == 0) && (right->sign == 0)){
        if (bn_cmp(left,right) >= 0){
            return bn_abs_sub(left, right);
        }
        else{
            bn *res = bn_new();
            res = bn_abs_sub(left,right);
            res->sign = 1;
        }
    }
    else if (((left->sign == 1) && (right->sign == 0)) || ((left->sign == 0) && (right->sign == 1))) {
        bn *left1 = bn_init(left);
        bn *right1 = bn_init(right);
        right1->sign = 0;
        left1->sign = 0;
        bn *res = bn_new();
        res = bn_add(left1,right1);
        res->sign = 1;
        free (right1);
        free (left1);
        return res;
    }
    else if ((left->sign == 1) && (right->sign == 1)){
        bn *left1 = bn_init(left);
        bn *right1 = bn_init(right);
        right1->sign = 0;
        left1->sign = 0;
        bn *res = bn_new();
        if (bn_cmp(left,right) >= 0){
            res = bn_abs_sub(left1, right1);
            res->sign = 1;
            free(left1);
            free(right1);
            return res;
        }
        else {
            res = bn_abs_sub(right1, left1);
            free(left1);
            free(right1);
            return res;
        }
    }
}

bn* bn_mul(bn const *left, bn const *right) {
    bn *res = bn_new();
    res->sign = left->sign * right->sign;
    res->bodysize = left->bodysize + right->bodysize;
    res->body = realloc(res->body, sizeof(int) * res->bodysize);
    int i;
    for (i = 0; i < left->bodysize; i++){
        int v_ume = 0;
        int j;
        for (j = 0; j < right->bodysize || v_ume; j++){
            res->body[i+j] += left->body[i] * right->body[j] + v_ume;
            v_ume = res->body[i+j] / N;
            res->body[i+j] -= v_ume * N;
        }
    }
    int pos = left->bodysize + right->bodysize;
    while (pos>0 && !res->body[pos])
    pos--;
    bn *res1 = bn_new();
    res1->bodysize = pos + 1;
    res1->sign = res->sign;
    for (i = 0; i < res1->bodysize; i++){
        res1->body[i] = res->body[i];
    }
    bn_delete(res);
    return res1;
}

bn* bn_div(bn const *left, bn const *right) {
    bn *res = bn_new();
    res->sign = left->sign * right->sign;
    res->bodysize = left->bodysize;
    res->body = realloc(res->body, sizeof(int) * res->bodysize);
    bn *curValue = bn_new();
    curValue->sign = left->sign;
    curValue->bodysize = left->bodysize;
    curValue->body = realloc(curValue->body, sizeof(int) * res->bodysize);
    int i;
    for (int i = left->bodysize; i>=0; i--){
        bn_mul_to(curValue, bn_init_int(N));
        curValue->body[0] = left->body[i];
        int x = 0;
        int l = 0;
        int r = N;
        while (l <= r) {
            int m = (l + r) >> l;
            bn *cur = bn_new();
            cur->sign = left->sign;
            cur->bodysize = m * right->bodysize;
            cur->body = realloc(cur->body, sizeof(int) * cur->bodysize);
            if (bn_cmp(cur, curValue) <= 0){
                x = m;
                l = m+1;
            }
            else {r = m - 1;}
        }
        res->body[i] = x;
        curValue = bn_init(bn_sub(curValue, bn_mul(right, bn_init_int(x))));

    }
    int pos = left->bodysize;
    while (pos>=0 && !res->body[pos])
    pos--;
    res->bodysize = pos+1;
 
  return res;
}

bn* bn_mod(bn const *left, bn const *right) {

}

void bn_print (bn* t) {
    int i;
    for (i = 0; i < t->bodysize; i++) {
        printf("%d ", t->body[i]);
    }
}


// Выдать представление BN в системе счисления radix в виде строки
//Строку после использования потребуется удалить.
const char *bn_to_string(bn const *t, int radix) {
    
}

// Если левое меньше, вернуть <0; если равны, вернуть 0; иначе >0
int bn_cmp(bn const *left, bn const *right) {
    if (left->sign == 1 && right->sign == 0){
        return -1;
    }
    else if (left->sign == 0 && right->sign == 1){
        return 1;
    }
    else if (left->sign == 0 && right->sign == 0){
        if (left->bodysize > right->bodysize){
            return 1;
        }
        else if (left->bodysize < right->bodysize){
            return -1;
        }
        else{
            int i = left->bodysize - 1;
            for (i; i == -1; i--){
                if (left->body[i]>right->body[i]){
                    return 1;
                }
                else if (left->body[i] < right->body[i]) {
                    return -1;
                }
            }
            return 0;
        }
    }
}

int bn_neg(bn *t) { // Изменить знак на противоположный
    if (t->sign) {
        t->sign = 0;
    } else {
        t->sign = 1;
    }
}

int bn_abs(bn *t) { // Взять модуль
    t->sign = 0;
}
int bn_sign(bn const *t) { //-1 если t<0; 0 если t = 0, 1 если t>0
    if ((t->bodysize == 1) && (t->body[0] == 0)) {
        return 0;
    } else {
        return ((t->sign * 2) - 1);
    }
}
