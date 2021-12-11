#include "DataBaseConnection.hpp"
#include "Data.hpp"

void DataBaseConnection::AddUser(boost::property_tree::ptree &params)
{
    _user user;
    user.name = params.get<std::string>("user.name");
    user.password = params.get<std::string>("user.password");
    user.mail = params.get<std::string>("user.mail");
    user.birth_date = params.get<std::string>("user.birth_date");
    user.sex = params.get<std::string>("user.sex");

    txn->exec("INSERT INTO users (name, password, mail, birth_date, sex)\
              VALUES (" +
             txn->quote(user.name) + ", " + txn->quote(user.password) + ", " + txn->quote(user.mail) + ", " + txn->quote(user.birth_date) + ", " + txn->quote(user.sex) + ");");

    txn->commit();
}

void DataBaseConnection::DeleteUser(boost::property_tree::ptree &params)
{
    std::string id = params.get<std::string>("user.id");

    txn->exec("DELETE FROM users WHERE user_id = " + txn->quote(id) + ";");

    txn->commit();
}

void DataBaseConnection::GetUser(boost::property_tree::ptree &params)
{
    std::string id = params.get<std::string>("user.id");

    pqxx::result res{txn->exec("SELECT name, mail, birth_date, sex FROM users WHERE user_id = " + txn->quote(id) + ";")};

    for (auto row : res) {
        params.put("user.name", row[0].c_str());
        params.put("user.mail", row[1].c_str());
        params.put("user.birth_date", row[2].c_str());
        params.put("user.sex", row[3].c_str());
    }
}

void DataBaseConnection::AddPost(boost::property_tree::ptree &params)
{
    _post post;
    post.title = params.get<std::string>("post.title");
    post.content = params.get<std::string>("post.content");
    post.user_id = params.get<std::string>("post.user_id");
    post.rating = params.get<std::string>("post.rating");

    txn->exec("INSERT INTO posts (title, content, user_id, rating) \
              VALUES (" +
             txn->quote(post.title) + ", " + txn->quote(post.content) + ", " + txn->quote(post.user_id) + ", " + txn->quote(post.rating) + ");");

    txn->commit();
}

void DataBaseConnection::DeletePost(boost::property_tree::ptree &params)
{
    std::string id = params.get<std::string>("post.id");

    txn->exec("DELETE FROM posts WHERE post_id = " + txn->quote(id) + ";");

    txn->commit();
}

void DataBaseConnection::GetPost(boost::property_tree::ptree &params)
{
    std::string id = params.get<std::string>("post.id");

    pqxx::result res{txn->exec("SELECT title, content, user_id, pub_date, rating FROM posts WHERE post_id = " + txn->quote(id) + ";")};

    for (auto row : res) {
        params.put("post.title", row[0].c_str());
        params.put("post.content", row[1].c_str());
        params.put("post.user_id", row[2].c_str());
        params.put("post.pub_date", row[3].c_str());
        params.put("post.rating", row[4].c_str());

        boost::property_tree::ptree images = GetPostImages(id);
        params.add_child("post.images", images);

        boost::property_tree::ptree comments = GetPostComments(id);
        params.add_child("post.comments", comments);
    }
}

void DataBaseConnection::GetUserPosts(boost::property_tree::ptree &params)
{
    boost::property_tree::ptree posts;

    std::string id = params.get<std::string>("user.id");

    pqxx::result res{txn->exec("SELECT post_id, title, content, pub_date, user_id, rating FROM posts JOIN user USING(user_id) WHERE user_id =" + txn->quote(id) + "ORDER BY pub_date;")};

    for (auto row : res) {
        boost::property_tree::ptree post;
        post.put("title", row[1].c_str());
        post.put("content", row[2].c_str());
        post.put("user_id", row[3].c_str());
        post.put("pub_date", row[4].c_str());
        post.put("rating", row[5].c_str());

        boost::property_tree::ptree images = GetPostImages(row[0].c_str());
        post.add_child("post.images", images);

        boost::property_tree::ptree comments = GetPostComments(row[0].c_str());
        post.add_child("post.comments", comments);

        posts.push_back(std::make_pair("", post));
    }

    params.add_child("posts", posts);
}

void DataBaseConnection::GetTopPosts(boost::property_tree::ptree &params)
{
    boost::property_tree::ptree posts;

    pqxx::result res{txn->exec("SELECT post_id, title, content, user_id, pub_date, rating FROM posts ORDER BY rating DESC LIMIT 100;")};

    for (auto row : res) {
        boost::property_tree::ptree post;
        post.put("title", row[1].c_str());
        post.put("content", row[2].c_str());
        post.put("user_id", row[3].c_str());
        post.put("pub_date", row[4].c_str());
        post.put("rating", row[5].c_str());

        boost::property_tree::ptree images = GetPostImages(row[0].c_str());
        post.add_child("post.images", images);

        boost::property_tree::ptree comments = GetPostComments(row[0].c_str());
        post.add_child("post.comments", comments);

        posts.push_back(std::make_pair("", post));
    }

    params.add_child("posts", posts);
}

void DataBaseConnection::UpdatePostRating(boost::property_tree::ptree &params)
{
    _grade grade;
    grade.value = params.get<std::string>("grade.value");
    grade.post_id = params.get<std::string>("grade.post_id");
    grade.user_id = params.get<std::string>("grade.user_id");

    txn->exec("UPDATE posts SET rating = rating + " + txn->quote(grade.value) + " WHERE post_id = " + txn->quote(grade.post_id) + ";");

    txn->commit();
}

void DataBaseConnection::AddGrade(boost::property_tree::ptree &params)
{
    _grade grade;
    grade.value = params.get<std::string>("grade.value");
    grade.post_id = params.get<std::string>("grade.post_id");
    grade.user_id = params.get<std::string>("grade.user_id");

    txn->exec("INSERT INTO grades (value, post_id, user_id) \
              VALUES (" +
             txn->quote(grade.value) + ", " + txn->quote(grade.post_id) + ", " + txn->quote(grade.user_id) + ");");

    txn->commit();
}

void DataBaseConnection::DeleteGrade(boost::property_tree::ptree &params)
{
    _grade grade;
    grade.post_id = params.get<std::string>("grade.post_id");
    grade.user_id = params.get<std::string>("grade.user_id");

    txn->exec("DELETE FROM grades WHERE post_id = " + txn->quote(grade.post_id) + " AND user_id = " + txn->quote(grade.user_id) + ";");

    txn->commit();
}

boost::property_tree::ptree DataBaseConnection::GetGrade(boost::property_tree::ptree &params)
{
    boost::property_tree::ptree old_grade;

    _grade grade;
    grade.post_id = params.get<std::string>("grade.post_id");
    grade.user_id = params.get<std::string>("grade.user_id");

    pqxx::result res{txn->exec("SELECT value, user_id, post_id \
                               FROM grades WHERE post_id = " +
                              txn->quote(grade.post_id) +
                              " AND user_id = " + txn->quote(grade.user_id) + ";")};

    for (auto row : res) {
        old_grade.put("grade.value", row[0].c_str());
        old_grade.put("grade.user_id", row[1].c_str());
        old_grade.put("grade.post_id", row[2].c_str());
    }
    old_grade.put("grade.count", res.affected_rows());

        return old_grade;
}

void DataBaseConnection::AddImage(boost::property_tree::ptree &params)
{
    _image image;
    image.image_path = params.get<std::string>("image.image_path");
    image.extension = params.get<std::string>("image.extension");

    txn->exec("INSERT INTO images (image_path, extension) \
              VALUES (" +
             txn->quote(image.image_path) + ", " + txn->quote(image.extension) + ");");

    txn->commit();
}

void DataBaseConnection::DeleteImage(boost::property_tree::ptree &params)
{
    std::string id = params.get<std::string>("image.id");

    txn->exec("DELETE FROM images WHERE image_id = " + txn->quote(id) + ";");

    txn->commit();
}

boost::property_tree::ptree DataBaseConnection::GetPostImages(std::string id)
{
    boost::property_tree::ptree images;

    pqxx::result res{txn->exec("SELECT image_id, image_path, extension \
                               FROM images JOIN posts_images USING(image_id) WHERE post_id = " +
                              txn->quote(id) + ";")};

    for (auto row : res) {
        boost::property_tree::ptree image;
        image.put("title", row[0].c_str());
        image.put("content", row[1].c_str());
        image.put("user_id", row[2].c_str());

        images.push_back(std::make_pair("", image));
    }

    return images;
}

void DataBaseConnection::AddComment(boost::property_tree::ptree &params)
{
    _comment comment;
    comment.content = params.get<std::string>("comment.content");
    comment.user_id = params.get<std::string>("comment.user_id");
    comment.post_id = params.get<std::string>("comment.post_id");

    txn->exec("INSERT INTO comments (content, post_id, user.id) \
              VALUES (" +
             txn->quote(comment.content) + ", " + txn->quote(comment.post_id) + txn->quote(comment.user_id) + ");");

    txn->commit();
}

void DataBaseConnection::DeleteComment(boost::property_tree::ptree &params)
{
    std::string id = params.get<std::string>("comment.id");

    txn->exec("DELETE FROM comments WHERE comment_id = " + txn->quote(id) + ";");

    txn->commit();
}

boost::property_tree::ptree DataBaseConnection::GetPostComments(std::string id)
{
    boost::property_tree::ptree comments;

    pqxx::result res{txn->exec("SELECT content, post_id, user_id \
                               FROM comments WHERE post_id = " +
                              txn->quote(id) + ";")};

    for (auto row : res) {
        boost::property_tree::ptree comment;
        comment.put("content", row[0].c_str());
        comment.put("post_id", row[1].c_str());
        comment.put("user_id", row[2].c_str());

        comments.push_back(std::make_pair("", comment));
    }

    return comments;
}