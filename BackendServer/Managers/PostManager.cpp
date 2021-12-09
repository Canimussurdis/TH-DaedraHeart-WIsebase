#include "PostManager.hpp"

boost::property_tree::ptree PostManager::addPost(boost::property_tree::ptree &params)
{
    dbConnector.AddPost(params);
    return params;
}

boost::property_tree::ptree PostManager::deletePost(boost::property_tree::ptree &params)
{
    dbConnector.DeletePost(params);
    return params;
}

boost::property_tree::ptree PostManager::getPost(boost::property_tree::ptree &params)
{
    dbConnector.GetPost(params);
    return params;
}

boost::property_tree::ptree PostManager::getTopPosts(boost::property_tree::ptree &params)
{
    dbConnector.GetTopPosts(params);
    return params;
}

boost::property_tree::ptree PostManager::getUserPosts(boost::property_tree::ptree &params)
{
    dbConnector.GetUserPosts(params);
    return params;
}

boost::property_tree::ptree PostManager::updatePostRating(boost::property_tree::ptree &params)
{
    boost::property_tree::ptree old_grade = dbConnector.GetGrade(params);

    if (old_grade.get<std::string>("grade.count") == "0" || old_grade.get<std::string>("grade.value") == params.get<std::string>("grade.value"))
    {
        return params;
    }
    else if (old_grade.get<std::string>("grade.value") != params.get<std::string>("grade.value"))
    {
        int new_value = params.get<int>("grade.value") - old_grade.get<int>("grade.value");
        params.put("grade.value", new_value); 
    }

    dbConnector.DeleteGrade(params);
    dbConnector.AddGrade(params);
    dbConnector.UpdatePostRating(params);
    
    return params;
}