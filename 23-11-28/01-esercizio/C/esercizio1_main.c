#include "esercizio1.h"
#include <stdio.h>

int main() {

  char res = 0;
  messaggio mess;
  queue q;

  init(&q);

  do {
    printf("\nOperazioni possibili:\n");
    printf("Enqueue (e)\n");
    printf("Dequeue (d)\n");
    printf("First (f)\n");
    printf("Print (p)\n");
    printf("Quit (q)\n");

    scanf("%c", &res);
    // printf("%c", res);

    switch (res) {

    case 'e':
      printf("Valore: ");
      scanf("%s", mess.testo);
      do {
        printf("Priorita' (>=0 e <=10): ");
        scanf("%d", &mess.priority);
      } while (mess.priority < 0 || mess.priority > MAX_PRIORITY);
      if (!enqueue(&q, &mess)) {
        printf("Coda piena\n");
      }

      break;

    case 'd':
      if (!dequeue(&q)) {
        printf("Coda vuota\n");
      }

      break;

    case 'f':
      if (!first(&q, &mess)) {
        printf("Coda vuota!\n");
      } else {
        printf("First = %s\n", mess.testo);
      }

      break;

    case 'p':
      print(&q);

      break;

    case 'q':
      if (destroy(&q)) {
        printf("Coda distrutta\n");
      }
      break;

    default:
      printf("Valore errato!\n");
    }
  } while (res != 'q');

  return 0;
}
