#include "arvore.h"

int no(Arv a) {
  if (a == NULL) {
    return 0;
  } else {
    int esq = nos(a -> sae);
    int dir = nos(a -> sad);

    return 1 + esq + dir;
  }
}

int main() {
  Arv e = novaarvore('E', NULL, NULL);
  Arv d = novaarvore('D', NULL, NULL);
  Arv c = novaarvore('C', e, NULL);
  Arv b = novaarvore('B', NULL, d);
  Arv a = novaarvore('A', b, c);

  printf("%d", no(a));
  
  
  return 0;
}
