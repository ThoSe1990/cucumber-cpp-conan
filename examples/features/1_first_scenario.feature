
Feature: My first feature
  This is my cucumber-cpp hello world

  Scenario: First Scenario
    Given An empty box
    When I place 2 x "apple" in it
    Then The box contains 2 item(s)
  
  Scenario: Second Scenario
    Given An empty box
    When I place 1 x "apple" in it
    And I place 1 x "banana" in it
    Then The 1. item is "apple"
    And The 2. item is "banana"
