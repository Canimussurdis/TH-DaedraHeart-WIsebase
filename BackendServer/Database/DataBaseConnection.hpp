#ifndef CONNETION_HPP
#define CONNETION_HPP

#include <pqxx/pqxx>

#include <string>

#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>

class DataBaseConnection
{
public:
    DataBaseConnection();
    ~DataBaseConnection() = default;

    void AddUser(boost::property_tree::ptree & params);
    void DeleteUser(boost::property_tree::ptree & params);
    void GetUser(boost::property_tree::ptree & params);
    void AddPost(boost::property_tree::ptree & params);
    void DeletePost(boost::property_tree::ptree & params);
    void GetPost(boost::property_tree::ptree & params);
    void GetUserPosts(boost::property_tree::ptree & params);
    void GetTopPosts(boost::property_tree::ptree & params);
    void UpdatePostRating(boost::property_tree::ptree & params);
    void AddGrade(boost::property_tree::ptree & params);
    void DeleteGrade(boost::property_tree::ptree & params);
    boost::property_tree::ptree GetGrade(boost::property_tree::ptree & params);
    void AddImage(boost::property_tree::ptree & params);
    void DeleteImage(boost::property_tree::ptree & params);
    boost::property_tree::ptree GetPostImages(std::string id);
    void AddComment(boost::property_tree::ptree & params);
    void DeleteComment(boost::property_tree::ptree & params);
    boost::property_tree::ptree GetPostComments(std::string id);    

private:
    pqxx::connection connection{"postgresql://postgres:qwerty123@localhost/social_network"};
    pqxx::work txn{connection};
};

#endif