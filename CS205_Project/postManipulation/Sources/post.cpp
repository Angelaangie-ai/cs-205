#include "postManipulation/Headers/post.h"
#include "ui_post.h"

int Post::current_post_id = 0; // Initialize the static member variable

Post::Post(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Post)
{
    ui->setupUi(this);
    post_id = ++current_post_id; // Increment the current_post_id and assign it to post_id

}

Post::~Post()
{
    delete ui;
}

/**
 * @brief Post::upload_picture
 * @param picture
 * A function to upload the picture
 */
void Post::upload_picture(const std::string& picture) {
    std::cout << "Uploaded picture: " << picture << std::endl;
    // should generate post id
    post_id = ++current_post_id; // Increment the current_post_id and assign it to post_id
}

/**
 * @brief Post::upload_video
 * @param video
 * A function to upload a video
 */
void Post::upload_video(const std::string&video) {
    std::cout<<"Uploaded video: " <<video << std::endl;
    // should generate post id
    post_id = ++current_post_id; // Increment the current_post_id and assign it to post_id
}

/**
 * @brief Post::put_tag
 * @param tag
 * A function to put tag(s) to the post
 */
void Post::put_tag(const std::string& tag) {
    tags.push_back(tag);
}

/**
 * @brief Post::edit
 * @param newTitle
 * @param newDescription
 * A function to edit an existing post.
 */
void Post::edit(const std::string& newTitle, const std::string& newDescription) {
    title = newTitle;
    description = newDescription;
    // needs to manipulate database here too.
}

/**
 * @brief Post::getPostId
 * @return
 * Getter function for post id
 */
int Post::getPostId() {
    return post_id;
}


