#include <catch.hpp>

#include <randomcpp.hpp>

TEST_CASE( "Test for random integers", "[integers]" ) {
   randomcpp::seed(1);

   SECTION ( "random integer inside positive range" ) {
      for (unsigned i=0; i < 100; ++i) {
          int rand_i = randomcpp::randint(0, 5);
          REQUIRE(rand_i <= 5);
          REQUIRE(rand_i >= 0);
      }
   }

   SECTION ( "random integer inside negative range" ) {
      for (unsigned i=0; i < 100; ++i) {
         int rand_i = randomcpp::randint(-10, -5);
         REQUIRE(rand_i <= -5);
         REQUIRE(rand_i >= -10);
      }
   }

   SECTION ( "random range stop" ) {
      for (unsigned i=0; i < 100; ++i) {
         int rand_i = randomcpp::randrange(5);
         REQUIRE(rand_i < 5);
         REQUIRE(rand_i >= 0);
      }
   }

   SECTION ( "random range start, stop" ) {
      for (unsigned i=0; i < 100; ++i) {
         int rand_i = randomcpp::randrange(1, 6);
         REQUIRE(rand_i < 6);
         REQUIRE(rand_i >= 1);
      }
   }

   SECTION ( "random range start, stop, step (odd)" ) {
      for (unsigned i=0; i < 100; ++i) {
         int rand_i = randomcpp::randrange(1, 6, 2);
         REQUIRE(rand_i < 6);
         REQUIRE(rand_i >= 1);
         REQUIRE(rand_i % 2 == 1);
      }
   }

   SECTION ( "random range start, stop, step (even)" ) {
      for (unsigned i=0; i < 100; ++i) {
         int rand_i = randomcpp::randrange(0, 7, 2);
         REQUIRE(rand_i <= 6);
         REQUIRE(rand_i >= 0);
         REQUIRE(rand_i % 2 == 0);
      }
   }

   SECTION ( "random integer range with both" ) {
      for (unsigned i=0; i < 100; ++i) {
         int rand_neg = randomcpp::randint(-5, 5);
         REQUIRE(rand_neg <= 5);
         REQUIRE(rand_neg >= -5);
      }
   }

   SECTION ( "repeat random integers not equal" ) {
      for (unsigned i=0; i < 100; ++i) {
         REQUIRE(randomcpp::randint(0, 1000) != randomcpp::randint(0, 1000));
      }
   }
}