#ifndef USERCOLUMN_H
#define USERCOLUMN_H

#include <QtDebug>

#include "User.h"

class UserColumn {
public:
    void setUserProfilePicture(User* user_profile_picture);
    void setUserName(User* user_name);

    void addTableView();
    void deleteTableView();

private slots:
    void onAddTabbleButtonClicked();
    void onDeleteButtonClicked();

private:
    User number_of_users;
};

#endif // USERCOLUMN_H
