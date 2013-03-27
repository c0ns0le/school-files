#ifndef __POST_OFFICE_H
#define __POST_OFFICE_H

#include "package.h"
#include "window.h"

class PostOffice {
    private:
        int n;
        Window** window_array;

        // returns a reference to the next open window
        Window& next_open_window(int window_id) {
            int pos = (window_id + 1) % n;
            while ( window_array[pos] == NULL ) {
                pos = (pos + 1) % n;
            }

            return *window_array[pos];
        }

    public:
        PostOffice(int N) {
            n = N;
            window_array = new Window*[n]();   // ?!
        }

        ~PostOffice() {
            int i;

            for (i=0; i<n; i++) {
                if (window_array[i] != NULL) {
                    delete window_array[i];
                }
            }

            delete window_array;
        }

        void add_window(int window_id, int weight_min, int weight_max, int Q, int K) {
            window_array[window_id] = new Window(window_id, weight_min, weight_max, Q, K);
        }

        void add_person(int personal_id, int package_weight, int window_id) {
            Package p;
            p.personal_id = personal_id;
            p.package_weight = package_weight;
            window_array[window_id]->send_to_queue(p);
        }

        void process(int window_id, int n) {
            window_array[window_id]->process(next_open_window(window_id), n);
        }

        void process_all(int window_id) {
            window_array[window_id]->process_all(next_open_window(window_id));
        }

        void print_stacks() {
            int i;

            printf("STACKS:\n");
            for (i=0; i<n; i++) {
                if (window_array[i] != NULL) {
                    window_array[i]->print_stack();
                }
            }
        }
        
        void flush_stacks() {
            int i;

            printf("FLUSHING:\n");
            for (i=0; i<n; i++) {
                if (window_array[i] != NULL) {
                    window_array[i]->flush_stack();
                }
            }
        }

        void print_queues() {
            int i;

            printf("QUEUES:\n");
            for (i=0; i<n; i++) {
                if (window_array[i] != NULL) {
                    window_array[i]->print_queue();
                }
            }
        }
};

#endif
