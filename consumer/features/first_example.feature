# ./examples/features/first_examples.feature

Feature: My First Feature File
  Just for demonstration

  Scenario: An arbitrary box
    Given A box with 2 x 2 x 2
    When I open the box
    Then The box is open 
    And The volume is 8 