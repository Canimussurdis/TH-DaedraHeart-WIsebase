#include "CommandCreator.hpp"

std::shared_ptr<BaseCommand> CommandCreator::createCommand(std::string method, std::string path, boost::property_tree::ptree &body)
{
    std::shared_ptr<AddUser> command(new AddUser(body));

    if (method == "POST" && path == "/user"){
        std::shared_ptr<AddUser> addUser(new AddUser(body));
        body.put("command", "AddUser");

        return addUser;
    } else if (method == "POST" && path == "/post"){
        std::shared_ptr<AddPost> addPost(new AddPost(body));
        body.put("command", "AddPost");

        return addPost;
    } else if (method == "DELETE" && path == "/user"){
        std::shared_ptr<DeleteUser> deleteUser(new DeleteUser(body));
        body.put("command", "DeleteUser");

        return deleteUser;
    } else if (method == "DELETE" && path == "/post"){
        std::shared_ptr<DeletePost> deletePost(new DeletePost(body));
        body.put("command", "DeletePost");

        return deletePost;
    } else if (method == "GET" && path == "/post"){
        std::shared_ptr<GetPost> getPost(new GetPost(body));
        body.put("command", "GetPost");

        return getPost;
    } else if (method == "GET" && path == "/mainpage"){
        std::shared_ptr<GetTopPosts> getTopPosts(new GetTopPosts(body));
        body.put("command", "GetTopPosts");

        return getTopPosts;
    } else if (method == "GET" && path == "/user"){
        std::shared_ptr<GetUser> getUser(new GetUser(body));
        body.put("command", "GetUser");

        return getUser;
    } else if (method == "GET" && path == "/userpage"){
        std::shared_ptr<GetUserPosts> getUserPosts(new GetUserPosts(body));
        body.put("command", "GetUserPosts");

        return getUserPosts;
    } else if (method == "UPDATE" && path == "/grade"){
        std::shared_ptr<UpdatePostRating> updatePostRating(new UpdatePostRating(body));
        body.put("command", "UpdatePostRating");

        return updatePostRating;
    } else if (method == "POST" && path == "/comment"){
        std::shared_ptr<AddComment> addComment(new AddComment(body));
        body.put("command", "AddComment");

        return addComment;
    } else if (method == "DELETE" && path == "/comment"){
        std::shared_ptr<DeleteComment> deleteComment(new DeleteComment(body));
        body.put("command", "DeleteComment");

        return deleteComment;
    }
    else {
        return command;
    }
}