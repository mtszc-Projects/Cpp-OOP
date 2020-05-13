#ifndef COLLECTIONMANAGER_H__
#define COLLECTIONMANAGER_H__

#include "user.h"

class CollectionManager{
    User & user1;
public:
    explicit CollectionManager(User & u1);
    ~CollectionManager();

    void manage();

    void name_change();
    void collection_not_created();
    void exit_to_menu();
    void add_collection();
    void add_item();
    void display_collection();
    void display_category();
    void change_collection_name();
    void search_item();
    void update_item();
    void statistics();
    void delete_item();
    void delete_collection();
};

#endif // COLLECTIONMANAGER_H__
