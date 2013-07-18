def setup
  set_window_size(580, 600)
  # set_window_pos(0, 0)
end

def draw
  set_background(255, 255, 255)
  
  set_fill

  set_color(87, 25, 122)
  text("circle", 125, 90)
  circle(150, 150, 50)

  set_color(220, 73, 0)
  text("triangle", 370, 90)
  triangle(350, 200, 450, 200, 400, 114)

  set_no_fill
  
  set_color(51, 106, 21)
  text("ellipse", 120, 240)
  set_line_width(5)
  ellipse(150, 300, 150, 100)

  set_color(0, 0, 0)
  text("line", 380, 240)
  set_line_width(10)
  line(350, 250, 450, 350)
  line(450, 250, 350, 350)

  set_fill

  set_color(196, 0, 0)
  text("rect", 135, 390)
  rect(100, 400, 100, 100)

  set_line_width(1)
  set_color(196, 0, 230)
  text("rect_rounded", 350, 390)
  rect_rounded(350, 400, 100, 100, 30)

  set_color(0, 0, 0)
  
  text(DebugInfo.fps, 10, 15)
  text(DebugInfo.window, 10, 30)
  text(DebugInfo.mouse, 10, 45)
end

module DebugInfo
  def self.fps
    "#{format("%3.2f", get_frame_rate)} fps"
  end

  def self.window
    "window_pos: (#{window_pos_x}, #{window_pos_y}), size: (#{window_width}, #{window_height})"
  end

  def self.mouse
    str = "mouse: "
    str += format("(%4d, %4d)", Input.mouse_x, Input.mouse_y)

    # press?
    str += " press?: "
    str += (0..2).map {|v|
      Input.mouse_press?(v) ? '1' : '0'
    }.join('')

    # down?
    str += " down?: "
    str += (0..2).map {|v|
      Input.mouse_down?(v) ? '1' : '0'
    }.join('')

    # release?
    str += " release?: "
    str += (0..2).map {|v|
      Input.mouse_release?(v) ? '1' : '0'
    }.join('')

    str
  end
end


