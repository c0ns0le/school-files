#include <stdio.h>
#include <string.h>

#include "post_office.h"


int main(int argc, char* argv[]) {
    FILE *f = fopen(argv[1], "r");

    int n;
    fscanf(f, "%d", &n);

    PostOffice p(n);

    char command[15];
    int window_id, weight_min, weight_max, Q, K, personal_id, package_weight, n_people;

    while (fscanf(f, "%s ", command) > 0) {
        if (strcmp(command, "OPEN_WINDOW") == 0) {
            fscanf(f, "%d %d %d %d %d", &window_id, &weight_min, &weight_max, &Q, &K);
            p.add_window(window_id, weight_min, weight_max, Q, K);
        } else if (strcmp(command, "ADD_PERSON") == 0) {
            fscanf(f, "%d %d %d", &personal_id, &package_weight, &window_id);
            p.add_person(personal_id, package_weight, window_id);
        } else if (strcmp(command, "PROCESS") == 0) {
            fscanf(f, "%d %d", &window_id, &n_people);
            p.process(window_id, n_people);
        } else if (strcmp(command, "PROCESS_ALL") == 0) {
            fscanf(f, "%d", &window_id);
            p.process_all(window_id);
        } else if (strcmp(command, "PRINT_STACKS") == 0) {
            p.print_stacks();
        } else if (strcmp(command, "FLUSH_STACKS") == 0) {
            p.flush_stacks();
        } else if (strcmp(command, "PRINT_QUEUES") == 0) {
            p.print_queues();
        }
    }

    fclose(f);

    return 0;
}
