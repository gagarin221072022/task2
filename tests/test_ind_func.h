#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include<fstream>
#include<string>

extern "C" {
#include "../app/common.h"
#include "../app/text.h"
#include "../app/_text.h"
}

TEST(show, suite1) {
    text txt = create_text();
    load(txt, path_to_file);
    move(txt, 1, 2);
    testing::internal::CaptureStdout();
    show(txt);
    std::string output = testing::internal::GetCapturedStdout();
    int i = 0;
    node *current = txt->begin;
    while(current)
    {
        for (int j = 0; j < strlen(current->contents); j++)
   {
            if (current == txt->cursor->line
                   && j == txt->cursor->position)
            {
                EXPECT_EQ(output[i], '|');
                i++;
            }
            EXPECT_EQ(output[i], current->contents[j]);
            i++;
        }
        i++;
        current = current->next;
    }
    remove_all(txt);
}

TEST(show, suite2) {
    text txt = create_text();
    testing::internal::CaptureStderr();
    show(txt);
    std::string output = testing::internal::GetCapturedStderr();
    EXPECT_EQ(output, "There are already no any lines in the text!\n");

    remove_all(txt);
}

TEST(showlengths, suite1) {
    text txt = create_text();
    testing::internal::CaptureStdout();
    load(txt, "./tests/test_input1.txt");
    showlengths(txt);
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_EQ(output, "5\n11\n17\n");
}

TEST(showlengths, suite2) {
    text txt = create_text();
    
    testing::internal::CaptureStderr();

    showlengths(txt);
    
    std::string output = testing::internal::GetCapturedStderr();
    
    EXPECT_EQ(output, "There are already no any lines in the text!\n");

    remove_all(txt);
}

TEST(rp, suite1) {
    text txt = create_text();

    load(txt, "./tests/test_rp_input.txt");
    move(txt, 2, 0);
    rp(txt);
    save(txt, "./tests/test_rp_output.txt");
    
    int k = 0;
    char arr[3] = {'1', '3', '4'};

    std::ifstream f;
    f.open("./tests/test_rp_output.txt");
    std::string s;

    int cnt = 0;
    while (std::getline(f, s))
    {
        EXPECT_EQ(s[0], arr[cnt]);
        cnt++;
    }

}

TEST(rp, suite2) {
    text txt = create_text();
    load(txt, "./tests/test_rp_input.txt");
    move(txt, 1, 0);
    //fprintf(stderr, "call rp\n");
    rp(txt);
    //fprintf(stderr, "good\n");
    save(txt, "./tests/test_rp_output.txt");
    
    
    char arr[3] = {'2', '3', '4'};

    std::ifstream f;
    f.open("./tests/test_rp_output.txt");
    std::string s;

    int cnt = 0;
    while (std::getline(f, s))
    {
        EXPECT_EQ(s[0], arr[cnt]);
        cnt++;
    }

}

TEST(rp, suite3) {
    text txt = create_text();

    testing::internal::CaptureStderr();

    rp(txt);
    
    std::string output = testing::internal::GetCapturedStderr();
    EXPECT_EQ(output, "There are already no any lines in the text!\n");
}

TEST(nmwbf, suite1) {
    text txt = create_text();
    load(txt, "./tests/test_input1.txt");
    move(txt, 1, 0);
    mnwbf(txt);
    
    char* content = txt -> cursor -> line -> contents;
    int cnt = txt -> cursor -> position;
    
    EXPECT_EQ(content[cnt - 1], ' ');
    
    remove_all(txt);
}

TEST(nmwbf, suite2) {
    text txt = create_text();
    load(txt, "./tests/test_input1.txt");
    move(txt, 0, 0);
    int pos1 = txt -> cursor -> position;

    mnwbf(txt);
    
    int pos2 = txt -> cursor -> position;
  
    
    EXPECT_EQ(pos2, pos1);
    
    remove_all(txt);
}

TEST(mnwbf, suite3) {
    text txt = create_text();
    
    
    testing::internal::CaptureStderr();
    mnwbf(txt);
    
    std::string output = testing::internal::GetCapturedStderr();
    EXPECT_EQ(output, "There are already no any lines in the text!\n");

    remove_all(txt);
}


