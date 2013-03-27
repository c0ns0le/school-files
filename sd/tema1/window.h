/*\
 *   Duma Andrei Dorian
 *   315 CA
\*/

#ifndef __WINDOW_H
#define __WINDOW_H

#include "package.h"
#include "package_stack.h"
#include "package_queue.h"

class Window {
    private:
        int window_id;
        int weight_min, weight_max;
        int Q, K, Q_, K_;

        PackageQueue queue;
        PackageStack stack;

        // process one package at this window;
        // if the weight is not acceptable, send package to window w
        void process_one_package(Window &w) {
            Package p = queue.dequeue();
            if (p.package_weight >= weight_min && p.package_weight <= weight_max) {
                send_to_stack(p);
            } else {
                w.send_to_queue(p);
            }
        }

    public:
        Window(int window_id, int weight_min, int weight_max, int Q, int K) {
            this->window_id = window_id;
            this->weight_min = weight_min;
            this->weight_max = weight_max;
            this->Q = Q;
            this->K = K;
            // current total weight and number of packages
            this->Q_ = 0;
            this->K_ = 0;
        }

        // send a package to the package (person) queue
        void send_to_queue(Package p) {
            queue.enqueue(p);
        }

        // send a package to the package stack, flushing it if necessary
        void send_to_stack(Package p) {
            if (K_ + p.package_weight > K || Q_ >= Q) {
                while (!stack.isEmpty()) {
                    stack.pop();
                }
                // mark as empty
                K_ = 0;
                Q_ = 0;
            }
            stack.push(p);
            Q_ += 1;
            K_ += p.package_weight;
        }

        // process n packages, sending unaccepted packages to window w
        void process(Window &w, int n) {
            int i;
            for (i=0; i<n; i++) {
                process_one_package(w);
            }
        }

        // process all packages in queue, sending unaccepted ones to window w
        void process_all(Window &w) {
            while (!queue.isEmpty()) {
                process_one_package(w);
            }
        }

        void print_stack() {
            Package p;

            // a temporary stack to hold our packages
            PackageStack tmp_stack;

            printf("%d:", window_id);

            // first package
            if (!stack.isEmpty()) {
                p = stack.pop();
                printf(" %d", p.package_weight);
                tmp_stack.push(p);
            }

            while (!stack.isEmpty()) {
                p = stack.pop();
                printf(", %d", p.package_weight);
                tmp_stack.push(p);
            }

            printf("\n");

            while (!tmp_stack.isEmpty()) {
                stack.push(tmp_stack.pop());
            }
        }

        // empty the stack, printing it to stdout
        void flush_stack() {
            printf("%d:", window_id);

            // first package
            if (!stack.isEmpty()) {
                printf(" %d", stack.pop().package_weight);
            }

            while (!stack.isEmpty()) {
                printf(", %d", stack.pop().package_weight);
            }

            printf("\n");
        }

        // print the queue to stdout
        void print_queue() {
            Package p;

            // a temporary queue to hold the packages
            PackageQueue tmp_queue;

            printf("%d:", window_id);

            // first package
            if (!queue.isEmpty()) {
                p = queue.dequeue();
                printf(" (%d, %d)", p.personal_id, p.package_weight);
                tmp_queue.enqueue(p);
            }

            while (!queue.isEmpty()) {
                p = queue.dequeue();
                printf(", (%d, %d)", p.personal_id, p.package_weight);
                tmp_queue.enqueue(p);
            }

            printf("\n");

            // restore the original queue
            while (!tmp_queue.isEmpty()) {
                queue.enqueue(tmp_queue.dequeue());
            }
        }
};

#endif
