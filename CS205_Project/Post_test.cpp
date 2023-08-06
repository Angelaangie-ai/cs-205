#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "post.h"

using namespace testing;

class PostTest : public ::testing::Test {
protected:
    void SetUp() override {
        post = new Post();
    }

    void TearDown() override {
        delete post;
    }

    Post* post;
};

TEST_F(PostTest, UploadPicture) {
    post->upload_picture("picture1.jpg");
    EXPECT_EQ(post->getPostId(), 2);
}

TEST_F(PostTest, UploadVideo) {
    post->upload_video("video1.mp4");
    EXPECT_EQ(post->getPostId(), 2);
}
TEST_F(PostTest, Edit) {
    post->edit("new title", "new description");
    EXPECT_EQ(post->title, "new title");
    EXPECT_EQ(post->description, "new description");
}
