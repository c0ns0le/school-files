/**
  *    Duma Andrei Dorian
  *    315 CA
  */

#include <stdio.h>
#include <string.h>
#include "deque.h"

int main() {
    int maxSize;
    scanf("%d", &maxSize);

    Deque d(maxSize);

    char command[25], param[100];
    int n;
    while (scanf("%s", command) > 0) {
        if (strcmp(command, "DAY_PASSES") == 0) {
            d.dayPasses();
        } else if (strcmp(command, "ACCESS_PAGE") == 0) {
            scanf("%s", param);
            d.accessPage(param);
        } else if (strcmp(command, "SHOW_ENTRY") == 0) {
            scanf("%d", &n);
            printf("ENTRY %d:\n%d %s\n\n", n, d.get(n).date, d.get(n).url);
        } else if (strcmp(command, "SHOW_HISTORY") == 0) {
            d.show_history();
        } else if (strcmp(command, "CLEAR_RECENT_HISTORY") == 0) {
            scanf("%d", &n);
            d.popBack(n);
        } else if (strcmp(command, "SET_MAX_DAYS") == 0) {
            scanf("%d", &n);
            d.setMaxDays(n);
        } else if (strcmp(command, "DELETE_ENTRY") == 0) {
            scanf("%d", &n);
            d.erase(n);
        } else if (strcmp(command, "RECOVER_HISTORY") == 0) {
            scanf("%s", param);
            d.recoverHistory(param);
        }
    }

    return 0;
}
