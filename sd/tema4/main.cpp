#include "trie.h"
#include <cstdlib>
#include <fstream>
#include <iostream>

int main() {
    Trie t;

    std::ifstream in("date.in");
    std::ofstream out("date.out");

    int n;
    in >> n;

    std::string word;
    int occ, i;
    for (i=0; i<n; i++) {
        in >> word >> occ;
        t.insert(occ, word);
    }

    int m;
    in >> m;

    int pos;
    std::string line;
    for (i=0; i<m; i++) {
        in >> line;
        pos = line.find('*');
        if (pos < 0) {
            out << t.visit(line, 0) << std::endl;
        } else {
            out << t.visit(line.substr(0, pos),
                        atoi(line.substr(pos+1, line.length()-pos-1).c_str()))
                << std::endl;
        }
    }

    return 0;
}
