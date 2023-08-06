#ifndef POST_H
#define POST_H

#include <iostream>
#include <string>
#include <vector>
#include <QWidget>

namespace Ui {
class Post;
}

class Post : public QWidget
{
    Q_OBJECT

public:
    explicit Post(QWidget *parent = nullptr);
    ~Post();
    /**
     * @brief upload_picture
     * @param picture
     * this is a funciton to upload a picture, it is designed to post a link/URL of a picture and
     * the user can see the picture using different platform
     */
    void upload_picture(const std::string& picture);

    /**
     * @brief upload_video
     * @param video
     * This is a function to upload a video, it is designed to post a link/URL of a video and
     * the user can see the video using different platform
     */
    void upload_video(const std::string&video);

    /**
     * @brief put_tag
     * @param tag
     * this is a function to put tag to a post, we have
     * fresh water
     * salt water
     * big tank fish
     * small tank fish
     *
     */
    void put_tag(const std::string& tag);

    /**
     * @brief edit
     * @param newTitle
     * @param newDescription
     * this is a function to edit a description of existing post.
     */
    void edit (const std::string& newTitle,
               const std::string& newDescription);

    /**
     * @brief getPostId
     * @return
     * getter function for postId
     */
    int getPostId();

    std::string title;
    std::string body;
    std::string user;
    std::string description;      // Description of the post
    std::string tag;
    std::string source;
    bool checkBox_fresh;
    bool checkBox_salt;
    bool checkBox_bigTank;
    bool checkBox_smallTank;
    bool checkBox_generalKnowledge;
    bool checkBox_specific;
    bool checkBox_source;
    int post_id;

    static int current_post_id; // Declaration of the static member variable

private:
    Ui::Post *ui;
    std::vector<std::string> tags; // Vector to store tags associated with the post

};

#endif // POST_H
