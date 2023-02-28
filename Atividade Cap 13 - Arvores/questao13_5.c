#include "arvore.h"

int tem(Arv a, char x) {
    if (a == NULL) {
        return 0;
    } else {
        int esq = tem(a -> sae, x);
        int dir = tem(a -> sad, x);

        if (a -> item == x) {
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

  printf("%d", tem(a, 'C'));
  
  
  return 0;
}
