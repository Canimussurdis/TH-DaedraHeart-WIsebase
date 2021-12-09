#ifndef DATA_HPP
#define DATA_HPP

#include <string>

struct _user
{
    std::string name;
    std::string password;
    std::string mail;
    std::string birth_date;
    std::string sex;
};

struct _post
{
    std::string title;
    std::string content;
    std::string user_id;
    std::string rating;
};

struct _grade
{
    std::string value;
    std::string post_id;
    std::string user_id;
};

struct _image
{
    std::string image_path;
    std::string extension;
};

struct _comment
{
    std::string content;
    std::string user_id;
    std::string post_id;
};

#endif