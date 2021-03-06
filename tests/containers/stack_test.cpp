#include <stack>
#include "containers/Stack.h"
#include "gtest/gtest.h"

cuhksz::Stack<int> testStack;
std::stack<int> stlStack;

TEST(stackTest, initialize) {
  stlStack.push(1);
  cuhksz::Stack<int> initStack1(stlStack);
  EXPECT_EQ(initStack1.size(), 1);
}

TEST(stackTest, typeConvert) {
  auto stack1 = testStack.toStlStack();
  std::stack<int> stack2 = testStack;
  EXPECT_EQ(stack1, stack2);
}

TEST(stackTest, eqOperator) {
  cuhksz::Stack<int> initStack1(stlStack);
  testStack = initStack1;
  EXPECT_EQ(testStack.size(), 1);
}

TEST(stackTest, push) {
  testStack.push(1);
  testStack.push(2);
  testStack.push(3);
  EXPECT_EQ(testStack.size(), 4);
}

TEST(stackTest, top) {
  EXPECT_EQ(testStack.top(), 3);
  testStack.top() = 4;
  EXPECT_EQ(testStack.top(), 4);
}

TEST(stackTest, pop) {
  EXPECT_EQ(testStack.pop(), 4);
  EXPECT_EQ(testStack.size(), 3);
}

TEST(stackTest, clear) {
  testStack.clear();
  EXPECT_TRUE(testStack.isEmpty());
}

TEST(stackDeathTest, emptyPopDeath) { EXPECT_DEATH(testStack.pop(), "empty"); }
