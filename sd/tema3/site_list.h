/**
 *  Duma Andrei Dorian
 *  315 CA
 */

#ifndef __SITE_LIST_H
#define __SITE_LIST_H

/**
 * Nod în lista simplu înlănțuită SiteList
 * - conține un string, site
 */
class SiteNode {
    public:
        char site[100];
        SiteNode* next;

        SiteNode(char*);
};

/**
 * O listă simplu înlănțuită de SiteNode-uri
 */
class SiteList {
    public:
        SiteNode* first;
        
        SiteList();
        ~SiteList();

        void print();
        void addSite(char* s);
        void intersectWith(SiteList* list);
        SiteList* duplicate();
};

#endif
