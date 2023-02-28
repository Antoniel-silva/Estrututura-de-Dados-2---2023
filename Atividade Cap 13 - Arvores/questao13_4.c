#include "arvore.h"

int altura(Arv a) {
    if (a == NULL) {
        return 0;
    } else {
        int esq = altura(a -> sae);
        int dir = altura(a -> sad);

        if (esq > dir) {
            return 1 + esq;
        } else {
            return 1 + dir;
        }
    }
}

int main() {
  Arv e = novaarvore('E', NULL, NULL);
  Arv d = novaarvore('D', NULL, NULL);
  Arv c = novaarvore('C', e, NULL);
  Arv b = novaarvore('B', NULL, d);
  Arv a = novaarvore('A', b, c);

  printf("%d", altura(b));
  
  
  return 0;
}
