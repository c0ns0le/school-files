#include <stdio.h>

#include "package.h"
#include "package_stack.h"
#include "package_queue.h"
#include "window.h"

int test_package_stack() {
    PackageStack stack;

    Package p;
    p.personal_id = 0;
    p.package_weight = 0;

    stack.push(p);
    stack.push(p);
    stack.push(p);

    stack.pop();
    stack.pop();
    
    if (stack.isEmpty()) {
        return 0;
    }

    stack.pop();

    if (!stack.isEmpty()) {
        return 0;
    }

    stack.push(p);
    stack.pop();

    if (!stack.isEmpty()) {
        return 0;
    }

    // OK
    return 1;
}

int test_package_queue() {
    PackageQueue queue;

    Package p;
    p.personal_id = 0;
    p.package_weight = 0;
    
    queue.enqueue(p);
    queue.enqueue(p);
    queue.enqueue(p);
    
    queue.dequeue();
    queue.dequeue();
    
    if (queue.isEmpty()) {
        return 0;
    }

    queue.dequeue();

    if (!queue.isEmpty()) {
        return 0;
    }

    queue.enqueue(p);
    queue.dequeue();

    if (!queue.isEmpty()) {
        return 0;
    }

    // OK
    return 1;
}

void test_window() {
    printf("Test Window Class:\n");
    Window a(0, 200, 500, 2, 500),
           b(4, 450, 1000, 3, 5000);

    a.add_person(100, 250);
    a.add_person(101, 650);
    a.add_person(102, 300);
    a.add_person(103, 550);

    a.print_queue();
    b.print_queue();
    //OK

    b.add_person(110, 800);

    a.process(2, b);

    a.print_queue();
    b.print_queue();
    //OK

    a.process_all(b);

    a.print_stack();
    b.print_stack();
    //OK

    b.process_all(a);

////// ?!
    a.print_stack();
    b.print_stack();
////// ?!

    a.flush_stack();
    b.flush_stack();

    // Should be empty now
    a.print_stack();
    b.print_stack();
    //OK

    printf("\n");
}

int main() {
    printf(test_package_stack() ? "OK\n" : "FAIL\n");
    printf(test_package_queue() ? "OK\n" : "FAIL\n");

    test_window();

    return 0;
}
