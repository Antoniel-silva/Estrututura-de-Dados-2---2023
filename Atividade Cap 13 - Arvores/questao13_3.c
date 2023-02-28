#include "arvore.h"

int folhas(Arv a) {
    if (a == NULL) {
        return 0;
    } else {
        int esq = folhas(a -> sae);
        int dir = folhas(a -> sad);

        if (a -> sae == NULL && a -> sad == NULL) {
            return 1 + esq + dir;
        } else {
            return 0 + esq + dir;
        }
    }
}

int main() {
  Arv e = novaarvore('E', NULL, NULL);
  Arv d = novaarvore('D', NULL, NULL);
  Arv c = novaarvore('C', e, NULL);
  Arv b = novaarvore('B', NULL, d);
  Arv a = novaarvore('A', b, c);

  printf("%d", folhas(a));
  

  return 0;
}
