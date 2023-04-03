#include <iostream>
#include <gtest/gtest.h>
#include <stdexcept>
#include "LibraryCode.hpp"

#include<gmock/gmock.h>

class AccountTestFixture: public testing::Test
{
  public:
    void SetUp() override;
    void TearDown() override;
  protected:
    Account *account;
};

void AccountTestFixture::SetUp()
{
  std::cout << "SetUp called\n";
  account = new Account();
  account->deposit(10.5);
}

void AccountTestFixture::TearDown()
{
  std::cout << "TearDown called\n";
  delete account;
}

TEST(AccountTest, TestEmptyAccount)
{
  Account account;

  double balance = account.getBalance();

  ASSERT_EQ(0, balance);
}

TEST_F(AccountTestFixture, TestDeposit)
{
  ASSERT_EQ(10.5, account->getBalance());
}


TEST_F(AccountTestFixture, TestWithdrawOK)
{
  
  
  account->withdraw(3);

  ASSERT_EQ(7.5, account->getBalance());
}


TEST_F(AccountTestFixture, TestWithdrawInsufficientFunds)
{
 
  
  ASSERT_THROW(account->withdraw(300), std::runtime_error);
}


TEST_F(AccountTestFixture, TestTransferOK)
{


  Account to;

  account->transfer(to, 2);
  
  ASSERT_EQ(8.5, account->getBalance());
  ASSERT_EQ(2, to.getBalance());
}



TEST_F(AccountTestFixture, TestTransferInsufficientFunds)
{
  
  Account to;

  ASSERT_THROW(account->transfer(to, 200), std::runtime_error);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
