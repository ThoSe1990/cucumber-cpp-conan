#include "cwt/cucumber.hpp"

#include "../src/box.hpp"

GIVEN(box_init, "A box with {int} x {int} x {int}")
{
  const unsigned int w = CUKE_ARG(1);
  const unsigned int l = CUKE_ARG(2);
  const unsigned int h = CUKE_ARG(3);

  cuke::context<box>(w,l,h);
}

WHEN(box_open, "I open the box")
{
  cuke::context<box>().open(); 
}
WHEN(box_close, "I close the box")
{
  cuke::context<box>().close(); 
}
WHEN(box_water, "Put {double} liter water into the box")
{
  const double water = CUKE_ARG(1);
  cuke::context<box>().set_weight(water);
}

THEN(box_is_open, "The box is open")
{
  cuke::is_true(cuke::context<box>().is_open());
}
THEN(box_is_closed, "The box is closed")
{
  cuke::is_false(cuke::context<box>().is_open());
}
THEN(box_volume, "The volume is {long}")
{
  const std::size_t volume = CUKE_ARG(1);
  cuke::equal(volume, cuke::context<box>().volume());  
}
THEN(box_weight, "The weight is {double} kg")
{
  const double weight = CUKE_ARG(1);
  cuke::equal(weight, cuke::context<box>().weight());  
}
THEN(box_front, "The front area is {int}")
{
  const unsigned int front = CUKE_ARG(1);
  cuke::equal(front, cuke::context<box>().front());
}
THEN(box_top, "The top area is {int}")
{
  const unsigned int top = CUKE_ARG(1);
  cuke::equal(top, cuke::context<box>().top());
}
THEN(box_side, "The side area is {int}")
{
  const unsigned int side = CUKE_ARG(1);
  cuke::equal(side, cuke::context<box>().side());
}



WHEN(box_set_description, "The box's description is")
{
  const std::string description = CUKE_ARG(1);
  cuke::context<box>().set_description(description);
}
WHEN(box_set_name, "The box's name is {string}")
{
  const std::string name = CUKE_ARG(1);
  cuke::context<box>().set_name(name);
}

THEN(box_print, "I print the box's name and description")
{
  std::cout << cuke::context<box>().name() << '\n' << cuke::context<box>().description() << '\n';
}

BEFORE(before)
{
  // std::puts("this runs before every scenario");
}
AFTER(after)
{
  // std::puts("this runs after every scenario");
}
BEFORE_STEP(before_step)
{
  // std::puts("this runs before every step");
}
AFTER_STEP(after_step)
{
  // std::puts("this runs after every step");
}

BEFORE_T(open_small_boxes, "@small_boxes and @open")
{
  cuke::context<box>(1u,1u,1u).open();
}