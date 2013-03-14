//#include "radix.h"
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
 /*   Queue<int, 3> q;
    
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << q.dequeue() << endl;
    q.enqueue(4);
    cout << q.front() << endl;
    q.enqueue(5);  // eroare
    
    q.dequeue();
    q.dequeue();
        cout << q.front() << endl;
    q.dequeue();

    q.dequeue();  // eroare
*/
    // ---------------------------- // Radix // ------------ //
    
 /*   int v[] = {268, 123, 279, 100, 399, 170, 45, 75, 90, 2, 24, 802, 66};
    RadixSort(v, 8);
    
    int i;
    for (i=0; i<8; i++) {
        printf("%d ", v[i]);
    }
    */
 
    Stack<int, 3> S;
    
    S.push(1);
    S.push(2);
    S.push(3);
    cout << S.pop() << endl;
    cout << S.pop() << endl;
    cout << S.pop() << endl;
    
    S.pop();
    
    return 0;
}