#include "collectionmanager.h"
#include "user.h"

int main(){
    User user1;
    CollectionManager manager1(user1);
    manager1.manage();

    return 0;
}
