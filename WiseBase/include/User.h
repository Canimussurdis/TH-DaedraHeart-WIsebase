#ifndef USER_H
#define USER_H

#include <QString>
#include <QtDebug>

class User {

public:
    User addUser(User* user);
    User deleteUser(User* user);
    User changeUserInformation(User* user);

    QString user_profile_picture;
    QString user_name;
};

#endif // USER_H
