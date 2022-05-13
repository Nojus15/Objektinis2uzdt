#include "pch.h"
#include "../headers/Studentas.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}
TEST(StudentTest, studentFirstNameTest) {
	Studentas stud;
	string name = "AAA";
	stud.setFirstName(name);
	EXPECT_EQ(stud.getFirstName(),"AAA");
}
TEST(StudentTest, studentLastNameTest) {
	Studentas stud;
	string name = "BBB";
	stud.setLastName(name);
	EXPECT_EQ(stud.getLastName(), "BBB");
}
TEST(StudentTest, studentEgzTest) {
	Studentas stud;
	stud.setEgz(5);
	EXPECT_EQ(stud.getEgz(), 6);
}