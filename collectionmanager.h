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
    void search_collection();
    void update_collection();
    void delete_collection();

    void add_item();
    void search_item();
    void update_item();
    void delete_item();
};

#endif // COLLECTIONMANAGER_H__
