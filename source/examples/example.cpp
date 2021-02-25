/*  example.cpp
 *
 *  Copyright (c) 2021 Mitya Selivanov
 *
 *  This file is part of IncludeCanvas.
 */

#include <canvas.h>
#include <numbers>

using canvas::set_title, canvas::set_size, canvas::on_render,
    canvas::get_frame, canvas::finalize, canvas::done, canvas::run,
    canvas::rgba, canvas::buffer;

auto main(int argc, char **argv) -> int {
  /*  Set the title and frame size.
   */
  set_title(L"IncludeCanvas Example");
  set_size(800, 600);

  /*  Setup the rendering routine.
   */
  on_render([] {
    using namespace canvas::color;

    buffer buf;
    buf.set_size(160, 120, gray);

    buf.fill_rectangle(5, 5, 15, 15, red);
    buf.fill_rectangle(5, 25, 15, 35, green);
    buf.fill_rectangle(5, 45, 15, 55, blue);

    buf.draw_rectangle(39, 4, 71, 11, dark_green);
    buf.draw_line_fast(40, 5, 70, 10, black);

    buf.draw_rectangle(39, 24, 71, 31, dark_green);
    buf.draw_line(40, 25, 70, 30, black);

    buf.draw_rectangle(79, 4, 85, 31, dark_green);
    buf.draw_line(80, 5, 84, 30, black);
    buf.draw_line(84, 5, 80, 30, black);

    buf.draw_line(40.5, 44.5, 80.5, 45., black);
    buf.draw_line(40.5, 46.5, 60., 80., dark_blue);

    buf.draw_line(70, 70, 70, 70, red);
    buf.draw_line(72.3, 70.4, 72.3, 70.4, red);

    buf.draw_line(80., 12., 100., 10., rgba(0, 255, 0, 127));
    buf.draw_towards(90., 25., 100., 10., rgba(0, 255, 0, 127));

    constexpr auto step = .2;

    for (double t = 0; t < std::numbers::pi * 2; t += step) {
      constexpr auto x0 = 80.;
      constexpr auto y0 = 60.;
      constexpr auto r  = 20.;

      buf.draw_towards(x0 + r * cos(t), y0 + r * sin(t),
                       x0 + r * cos(t + step), y0 + r * sin(t + step),
                       white);
    }

    get_frame().stretch(buf);

    /*  Draw the canvas.
     */
    finalize();

    /*  Reset the render function.
     */
    done();
  });

  /*  Run the application.
   */
  return run();
}
