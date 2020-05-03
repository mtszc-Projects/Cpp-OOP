#ifndef COLLECTIONMANAGER_H__
#define COLLECTIONMANAGER_H__

#include "user.h"

class CollectionManager{
    User & user1;
public:
    explicit CollectionManager(User & u1);
    ~CollectionManager();

    void manage();

    void add_collection();
    void display_collection();
    void display_category();
    void change_collection_name();
    void delete_collection();

    void add_item();
    void search_item();
    void update_item();
    void delete_item();
};

#endif // COLLECTIONMANAGER_H__
